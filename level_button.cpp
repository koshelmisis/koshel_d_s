#include "level_button.h"

LevelButton::LevelButton(int levelNumber)
{
	_levelNumber = levelNumber;
	_bgImage = new QImage(QString("images/%1.png").arg(_levelNumber));
	setFlag(ItemIsSelectable);
}


LevelButton::~LevelButton()
{
	delete _bgImage;
}


void LevelButton::SetRect(QRectF rect)
{
	_rect = rect;
}


int LevelButton::GetLevelNumber() const
{
	return _levelNumber;
}


QRectF LevelButton::boundingRect() const
{
	return _rect;
}


void LevelButton::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	QBrush *brush = new QBrush(*_bgImage);

	painter->setPen(Qt::NoPen);

	painter->fillRect(_rect, *brush);
	painter->drawRect(_rect);

	delete brush;
}


void LevelButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	_itemPressed = true;
	update();
	QGraphicsItem::mousePressEvent(event);
}


void LevelButton::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
	if (_itemPressed)
	{
		_itemPressed = false;
		update();
		QGraphicsItem::mouseReleaseEvent(event);

		emit Press();
	}
}
