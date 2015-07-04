#include "imagelab.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	imagelab w;
	w.show();
	return a.exec();
}
