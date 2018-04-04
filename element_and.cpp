#include "element_and.h"

ElementAnd::ElementAnd()
{
	_bgImage = new QImage("images/and_gate.png");

	_point.setX(this->x() + _rect.width() / 2);
	_point.setY(this->y() - 5);
}


ElementAnd::ElementAnd(int id)
{
	_id = id;
	_bgImage = new QImage("images/and_gate.png");

	_point.setX(this->x() + _rect.width() / 2);
	_point.setY(this->y() - 5);
}


ElementAnd::~ElementAnd()
{
}


void ElementAnd::Update()
{
	_outPin = _inPin[0] & _inPin[1];
	if (_connectedElement)
	{
		_connectedElement->SetInput(_connectedPin, _outPin);

		if (_wire)
			_wire->Update(_outPin);
	}
}


QPointF ElementAnd::GetPinPoint(int pinNumber)
{
	if (pinNumber >= 0)
	{
		return QPointF(this->x() + 19 + pinNumber * 54, this->y() + _rect.height() - 6);
	}

	return QPointF(this->x() + _rect.width() / 2, this->y());
}


void ElementAnd::SetInput(int pinNumber, bool value)
{
	_inPin[pinNumber] = value;

	Update();
}
