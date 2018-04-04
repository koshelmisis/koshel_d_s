#include "level.h"
#include <fstream>
#include <string>
#include <chrono>
#include <thread>

Level::Level(int levelNumber, QGraphicsScene *scene)
{
	_levelNumber = levelNumber;
	_scene = scene;

	_logicElements = nullptr;
	_wires = nullptr;
	_logicElementsCount = 0;
	_wiresCount = 0;

	_title = nullptr;
	_shadow = nullptr;

	_sceneWidth = _scene->width();
	_sceneHeight = _scene->height();

	_nextBtn = new LevelButton(0);
	_menuBtn = new LevelButton(-1);
}


Level::~Level()
{
	if (_logicElements)
	{
		for (int i = 0; i < _logicElementsCount; i++)
		{
			delete _logicElements[i];
		}
		delete[] _logicElements;
	}

	if (_wires)
	{
		for (int i = 0; i < _wiresCount; i++)
		{
			delete _wires[i];
		}
		delete[] _wires;
	}

	if (_title)
		delete _title;
}


LogicElement* Level::GetElementById(int id)
{
	LogicElement *el = nullptr;

	for (int i = 0; i < _logicElementsCount; i++)
	{
		if (_logicElements[i]->GetId() == id)
		{
			el = _logicElements[i];
			break;
		}
	}

	return el;
}


void Level::Load(int levelNumber)
{
	std::string filename = "levels/" + std::to_string(levelNumber) + ".cfg";
	std::ifstream levelCfg(filename, std::ios_base::binary);

	int offset = 0;

	Header_t header;
	Element_t el;

	if (levelCfg.is_open())
	{
		levelCfg.read((char*)(&header), sizeof(header));

		_andCount = header.andCount;
		_orCount = header.orCount;
		_notCount = header.notCount;
		_xorCount = header.xorCount;
		_sourceCount = header.sourceCount;
		_wiresCount = header.wiresCount;

		_logicElementsCount = _andCount + _orCount + _notCount + _xorCount + _sourceCount + 1;

		_logicElements = new LogicElement*[_logicElementsCount];
		_wires = new Wire*[_wiresCount];

		for (int i = offset; i < _sourceCount + offset; i++)
		{
			levelCfg.read((char*)(&el), sizeof(el));

			_logicElements[i] = new LogicOutput((bool)el.init, el.id);
			_logicElements[i]->SetRect(QRectF(0, 0, 39, 39));
			_logicElements[i]->setPos((qreal)el.x, (qreal)el.y);
			_logicElements[i]->SetCId(el.cid);
			_logicElements[i]->SetConnectedPin(el.pin);
		}
		offset += _sourceCount;

		for (int i = offset; i < _andCount + offset; i++)
		{
			levelCfg.read((char*)(&el), sizeof(el));

			_logicElements[i] = new ElementAnd(el.id);
			_logicElements[i]->SetRect(QRectF(0, 0, 92, 44));
			_logicElements[i]->setPos((qreal)el.x, (qreal)el.y);
			_logicElements[i]->SetCId(el.cid);
			_logicElements[i]->SetConnectedPin(el.pin);
		}
		offset += _andCount;

		for (int i = offset; i < _orCount + offset; i++)
		{
			levelCfg.read((char*)(&el), sizeof(el));

			_logicElements[i] = new ElementOr(el.id);
			_logicElements[i]->SetRect(QRectF(0, 0, 92, 44));
			_logicElements[i]->setPos((qreal)el.x, (qreal)el.y);
			_logicElements[i]->SetCId(el.cid);
			_logicElements[i]->SetConnectedPin(el.pin);
		}
		offset += _orCount;

		for (int i = offset; i < _notCount + offset; i++)
		{
			levelCfg.read((char*)(&el), sizeof(el));

			_logicElements[i] = new ElementNot(el.id);
			_logicElements[i]->SetRect(QRectF(0, 0, 27, 27));
			_logicElements[i]->setPos((qreal)el.x, (qreal)el.y);
			_logicElements[i]->SetCId(el.cid);
			_logicElements[i]->SetConnectedPin(el.pin);
		}
		offset += _notCount;

		for (int i = offset; i < _xorCount + offset; i++)
		{
			levelCfg.read((char*)(&el), sizeof(el));

			_logicElements[i] = new ElementXor(el.id);
			_logicElements[i]->SetRect(QRectF(0, 0, 92, 44));
			_logicElements[i]->setPos((qreal)el.x, (qreal)el.y);
			_logicElements[i]->SetCId(el.cid);
			_logicElements[i]->SetConnectedPin(el.pin);
		}
		offset += _xorCount;

		levelCfg.read((char*)(&el), sizeof(el));

		//LogicInput
		_logicElements[offset] = new LogicInput(el.id);
		_logicElements[offset]->SetRect(QRectF(0, 0, 135, 60));
		_logicElements[offset]->setPos((qreal)el.x, (qreal)el.y);

		levelCfg.close();

		_title = new QGraphicsTextItem();
		_title->setFont(QFont("Consolas", 24));
		_title->setDefaultTextColor(QColor(255, 255, 255));
		_title->setPlainText(QString("LEVEL %1").arg(_levelNumber));
		_title->setPos((_sceneWidth - _title->boundingRect().width()) / 2, _sceneHeight / 25);

		_scene->addItem(_title);

		_menuBtn->SetRect(QRectF(0, 0, 68, 29));
		_menuBtn->setPos(10, 10);
		connect(_menuBtn, SIGNAL(Press()), this, SLOT(ReturnToMenu()));

		_scene->addItem(_menuBtn);

		LogicInput *input = (LogicInput *)_logicElements[offset];

		_scene->addItem(input);
		connect(input, SIGNAL(Completed()), this, SLOT(LevelCompleted()));

		LogicElement *connected = nullptr;
		for (int i = 0; i < _logicElementsCount - 1; i++)
		{
			connected = GetElementById(_logicElements[i]->GetCId());
			_logicElements[i]->ConnectTo(connected);

			_wires[i] = new Wire(_logicElements[i]->GetPinPoint(-1), connected->GetPinPoint(_logicElements[i]->GetConnectedPin()));
			_logicElements[i]->SetWire(_wires[i]);

			_scene->addItem(_logicElements[i]);
			_scene->addItem(_wires[i]);
			_wires[i]->Update();
		}

		for (int i = 0; i < _sourceCount; i++)
		{
			_logicElements[i]->Update();
		}
	}
	else
	{
		ReturnToMenu();
	}
}


int Level::LevelNumber() const
{
	return _levelNumber;
}


Level::ExitReason Level::Reason() const
{
	return _reason;
}


void Level::ReturnToMenu()
{
	_reason = ExitReason::Quit;

	CloseLevel();
}


void Level::CloseLevel()
{
	for (int i = 0; i < _logicElementsCount; i++)
	{
		_scene->removeItem(_logicElements[i]);
	}

	for (int i = 0; i < _wiresCount; i++)
	{
		_scene->removeItem(_wires[i]);
	}

	if (_title)
		_scene->removeItem(_title);
	if (_nextBtn)
		_scene->removeItem(_nextBtn);
	if (_menuBtn)
		_scene->removeItem(_menuBtn);
	if (_shadow)
		_scene->removeItem(_shadow);

	emit Passed();
}


void Level::LevelCompleted()
{
	_reason = ExitReason::Success;

	connect(_nextBtn, SIGNAL(Press()), this, SLOT(CloseLevel()));

	_nextBtn->SetRect(QRectF(0, 0, 116, 43));
	_nextBtn->setPos((_sceneWidth - _nextBtn->boundingRect().width()) / 2, (_sceneHeight - _nextBtn->boundingRect().height()) / 2);

	_scene->addItem(_nextBtn);
	_nextBtn->setZValue(1000);
	_menuBtn->setZValue(1000);

	_shadow = _scene->addRect(_scene->sceneRect(), QPen(Qt::NoPen), QColor(0, 10, 0, 128));

	LogicOutput *logicBtn;

	for (int i = 0; i < _sourceCount; i++)
	{
		logicBtn = (LogicOutput *)_logicElements[i];
		logicBtn->Disable();
	}
}


void Level::Start()
{
	Load(_levelNumber);
}
