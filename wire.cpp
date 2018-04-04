#include "wire.h"

Wire::Wire(QPointF p1, QPointF p2)
{
	_p1 = p1;
	_p2 = p2;
}


Wire::~Wire()
{

}


void Wire::Update(bool state)
{
	if (state)
		_color = QColor(42, 212, 255);
	else
		_color = QColor(255, 198, 0);
	
	update();
}


#ifndef min
#define min(a,b) (a)<(b)?(a):(b)
#endif


QRectF Wire::boundingRect() const
{
	return QRectF(min(_p1.x(), _p2.x()), min(_p1.y(), _p2.y()), abs(_p1.x() - _p2.x()), abs(_p1.y() - _p2.y()));
}


void Wire::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
	QBrush bgBrush = QBrush(QColor(0, 85, 0));
	QBrush brush = QBrush(_color);

	QPen bgPen(bgBrush, 10, Qt::SolidLine, Qt::RoundCap);
	QPen pen(brush, 6, Qt::SolidLine, Qt::RoundCap);

	painter->setPen(bgPen);
	painter->drawLine(_p1, _p2);

	painter->setPen(pen);
	painter->drawLine(_p1, _p2);
}
