#include "game.h"
#include <QGraphicsTextItem>
#include <QSignalMapper>
#include <QAction>

Game::Game(QGraphicsScene *scene, int width, int height)
{
	_scene = scene;

	_sceneWidth = width;
	_sceneHeight = height;

	_scene->setSceneRect(0, 0, _sceneWidth, _sceneHeight);
	_scene->setBackgroundBrush(QBrush(QColor(0, 85, 0)));

	_signalMapper = new QSignalMapper(this);
	_title = new QGraphicsTextItem();
	
	_levelButtonsCount = 10;
	_levelButtons = new LevelButton*[_levelButtonsCount];
	for (int i = 0; i < _levelButtonsCount; i++)
	{
		_levelButtons[i] = new LevelButton(i + 1);
		connect(_levelButtons[i], SIGNAL(Press()), this, SLOT(LevelButtonPressed()));
	}
	
	_levelsCount = 10;
	_levels = new Level*[_levelsCount];
	for (int i = 0; i < _levelsCount; i++)
	{
		_levels[i] = new Level(i + 1, _scene);
		connect(_levels[i], SIGNAL(Passed()), this, SLOT(LevelPassed()));
	}
}


Game::~Game()
{
	if (_levelButtons)
	{
		for (int i = 0; i < _levelButtonsCount; i++)
		{
			if (_levelButtons[i])
				delete _levelButtons[i];
		}

		delete[] _levelButtons;
	}
}


void Game::LevelButtonPressed()
{
	LevelButton *btn = (LevelButton*)QObject::sender();

	LoadLevel(btn->GetLevelNumber());
}


void Game::LevelPassed()
{
	Level *level = (Level*)QObject::sender();

	if (level->Reason() == Level::ExitReason::Quit)
	{
		ShowMenu();
	}
	else if (level->Reason() == Level::ExitReason::Success)
	{
		if (level->LevelNumber() < _levelsCount)
		{
			LoadLevel(level->LevelNumber() + 1);
		}
		else
		{
			ShowMenu();
		}
	}
}


void Game::LoadLevel(int level)
{
	_scene->removeItem(_title);
	for (int i = 0; i < _levelButtonsCount; i++)
	{
		_scene->removeItem(_levelButtons[i]);
	}
	_levels[level - 1]->Start();
}


void Game::ShowMenu()
{
	int btnWidth = 43;
	int btnHeight = 57;
	int sep = (_sceneWidth - 5 * btnWidth) / 6;

	_title->setFont(QFont("Consolas", 36));
	_title->setDefaultTextColor(QColor(255, 255, 255));
	_title->setPlainText("LEVELS");
	_title->setPos((_sceneWidth - _title->boundingRect().width()) / 2, _sceneHeight / 7);

	_scene->addItem(_title);

	for (int h = 0; h < 2; h++)
	{
		for (int w = 0; w < 5; w++)
		{
			_levelButtons[5 * h + w]->SetRect(QRectF(0, 0, btnWidth, btnHeight));
			_levelButtons[5 * h + w]->setPos(sep*(w + 1) + w*btnWidth, 100 * (h + 1) + btnHeight);
			_scene->addItem(_levelButtons[5 * h + w]);
		}
	}
}
