#include "MdiChildImage.h"
#include <qgraphicsscene.h>
#include <qgraphicsitem.h>

#include <opencv2/opencv.hpp>
using namespace cv;
using namespace ASM;

CMdiChildImage::CMdiChildImage()
{
	scene= new QGraphicsScene();
	item = new QGraphicsPixmapItem();
}


CMdiChildImage::~CMdiChildImage()
{

}


void CMdiChildImage::newFile()
{
	Mat img(500, 500, CV_8UC3,Scalar(0,255,0));
	
	item->setPixmap(cvMatToQPixmap(img));
	scene->addItem(item);
	setScene(scene);
}