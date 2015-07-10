#include "MdiChildImage.h"
#include <qgraphicsscene.h>
#include <qgraphicsitem.h>

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
	
}