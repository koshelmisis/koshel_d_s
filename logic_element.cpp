#include "logic_element.h"
#include <QColor>

LogicElement::LogicElement()
{
	_connectedElement = nullptr;
    _bgImage = nullptr;
	setFlag(ItemIsSelectable);

	_inPin[0] = false;
	_inPin[1] = false;
	_outPin = false;
	_wire = nullptr;
}


LogicElement::LogicElement(int id)
{
	_connectedElement = nullptr;
    _bgImage = nullptr;
	setFlag(ItemIsSelectable);
	_id = id;

	_inPin[0] = false;
	_inPin[1] = false;
	_outPin = false;
	_wire = nullptr;
}


LogicElement::~LogicElement()
{
	if (_bgImage)
		delete _bgImage;
}


int LogicElement::GetId() const
{
	return _id;
}


void LogicElement::SetCId(int cid)
{
	_cid = cid;
}


int LogicElement::GetCId() const
{
	return _cid;
}


void LogicElement::SetWire(Wire *wire)
{
	_wire = wire;
}


QPointF LogicElement::GetPinPoint(int pinNumber)
{
	return QPointF();
}


void LogicElement::SetConnectedPin(int pinNumber)
{
	_connectedPin = pinNumber;
}


int LogicElement::GetConnectedPin() const
{
	return _connectedPin;
}


void LogicElement::ConnectTo(LogicElement *logicElement)
{
	_connectedElement = logicElement;
}


void LogicElement::ConnectTo(LogicElement *logicElement, int pinNumber)
{
	_connectedElement = logicElement;
	_connectedPin = pinNumber;
}


void LogicElement::SetInput(int pinNumber, bool value)
{
	_inPin[pinNumber] = value;
}


bool LogicElement::GetOutput() const
{
	return _outPin;
}


void LogicElement::Update()
{

}


void LogicElement::SetRect(QRectF rect)
{
    _rect = rect;
}


QRectF LogicElement::boundingRect() const
{
    return _rect;
}


void LogicElement::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QBrush *brush = new QBrush(*_bgImage);

	painter->setPen(Qt::NoPen);

    painter->fillRect(_rect, *brush);
    painter->drawRect(_rect);

	delete brush;
}
