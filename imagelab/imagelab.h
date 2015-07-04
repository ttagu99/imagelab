#ifndef IMAGELAB_H
#define IMAGELAB_H

#include <QtWidgets/QMainWindow>
#include "ui_imagelab.h"

class imagelab : public QMainWindow
{
	Q_OBJECT

public:
	imagelab(QWidget *parent = 0);
	~imagelab();

private:
	Ui::imagelabClass ui;
};

#endif // IMAGELAB_H
