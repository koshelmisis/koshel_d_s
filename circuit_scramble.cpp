#include "circuit_scramble.h"
#include "game.h"

circuit_scramble::circuit_scramble(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	this->setWindowTitle("Circuit Scramble");
	this->setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);

	scene = new QGraphicsScene(this);
	ui.graphicsView->setScene(scene);
	ui.graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

	Game *game = new Game(scene, 324, 576);
	game->ShowMenu();
}
