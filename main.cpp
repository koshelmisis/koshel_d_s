#include "circuit_scramble.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	circuit_scramble w;
	w.show();
	return a.exec();
}
