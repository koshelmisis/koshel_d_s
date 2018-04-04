#include "element_not.h"

ElementNot::ElementNot()
{
	_bgImage = new QImage("images/not_gate.png");
}


ElementNot::ElementNot(int id)
{
	_id = id;
	_bgImage = new QImage("images/not_gate.png");
}


ElementNot::~ElementNot()
{
}


void ElementNot::Update()
{
	_outPin = !_inPin[0];
	if (_connectedElement)
	{
		_connectedElement->SetInput(_connectedPin, _outPin);

		if (_wire)
			_wire->Update(_outPin);
	}
}


QPointF ElementNot::GetPinPoint(int pinNumber)
{
	if (pinNumber >= 0)
	{
		return QPointF(this->x() + _rect.width() / 2, this->y() + _rect.height());
	}

	return QPointF(this->x() + _rect.width() / 2, this->y());
}


void ElementNot::SetInput(int pinNumber, bool value)
{
	_inPin[0] = value;

	Update();
}
