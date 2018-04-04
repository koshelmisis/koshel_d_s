#include "logic_input.h"

LogicInput::LogicInput()
{
	_bgImage = nullptr;

	_imageOk = new QImage("images/input_ok.png");
	_imageBad = new QImage("images/input_bad.png");

	_bgImage = _imageBad;
	setFlag(ItemIsSelectable);
}


LogicInput::LogicInput(int id)
{
	_id = id;
	_bgImage = nullptr;

	_imageOk = new QImage("images/input_ok.png");
	_imageBad = new QImage("images/input_bad.png");

	_bgImage = _imageBad;
	setFlag(ItemIsSelectable);
}


LogicInput::~LogicInput()
{
	if (_imageOk)
		delete _imageOk;

	if (_imageBad)
		delete _imageBad;

	_bgImage = nullptr;
}


QPointF LogicInput::GetPinPoint(int pinNumber)
{
	if (pinNumber >= 0)
	{
		return QPointF(this->x() + _rect.width() / 2, this->y() + _rect.height());
	}
}


void LogicInput::SetInput(int pinNumber, bool value)
{
	_inPin[0] = value;
	_inPin[1] = value;
	_outPin = value;

	if (_outPin)
	{
		_bgImage = _imageOk;
	}

	update();

	if (_outPin)
	{
		emit Completed();
	}
}
