#include "logic_output.h"

LogicOutput::LogicOutput()
{
	_enabled = true;
	_outPin = false;
	_bgImage = nullptr;
	_imagePressed = new QImage("images/source_pressed.png");
	_imageReleased = new QImage("images/source_released.png");

	if (_outPin)
		_bgImage = _imagePressed;
	else
		_bgImage = _imageReleased;

	_point.setX(this->x() + _rect.width() / 2);
	_point.setY(this->y());
}


LogicOutput::LogicOutput(bool initialState)
{
	_enabled = true;
	_outPin = initialState;
	_bgImage = nullptr;
	_imagePressed = new QImage("images/source_pressed.png");
	_imageReleased = new QImage("images/source_released.png");

	if (_outPin)
		_bgImage = _imagePressed;
	else
		_bgImage = _imageReleased;

	_point.setX(this->x() + _rect.width() / 2);
	_point.setY(this->y());
}


LogicOutput::LogicOutput(bool initialState, int id)
{
	_enabled = true;
	_id = id;
	_outPin = initialState;
	_bgImage = nullptr;
	_imagePressed = new QImage("images/source_pressed.png");
	_imageReleased = new QImage("images/source_released.png");

	if (_outPin)
		_bgImage = _imagePressed;
	else
		_bgImage = _imageReleased;

	_point.setX(this->x() + _rect.width() / 2);
	_point.setY(this->y());
}


LogicOutput::~LogicOutput()
{
	if (_imagePressed)
		delete _imagePressed;

	if (_imageReleased)
		delete _imageReleased;

	_bgImage = nullptr;
}


void LogicOutput::Disable()
{
	_enabled = false;
}


QPointF LogicOutput::GetPinPoint(int pinNumber)
{
	if (pinNumber == -1)
		return QPointF(this->x() + _rect.width() / 2, this->y());
}


void LogicOutput::SetInitialState(bool initialState)
{
	_outPin = initialState;
}


void LogicOutput::Update()
{
	if (_outPin)
		_bgImage = _imagePressed;
	else
		_bgImage = _imageReleased;

	if (_connectedElement)
	{
		_connectedElement->SetInput(_connectedPin, _outPin);

		if (_wire)
			_wire->Update(_outPin);
	}
}


void LogicOutput::Press()
{
	_outPin = !_outPin;
	Update();
}


void LogicOutput::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	_itemPressed = true;
	update();
	QGraphicsItem::mousePressEvent(event);
}


void LogicOutput::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	if (_itemPressed)
	{
		if (_enabled)
			Press();

		_itemPressed = false;
		update();
		QGraphicsItem::mouseReleaseEvent(event);
	}
}
