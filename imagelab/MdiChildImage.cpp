#include "MdiChildImage.h"
#include <qgraphicsscene.h>
#include <qgraphicsitem.h>
#include <sstream>

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
	m_Img = Mat(500, 500, CV_8UC3,Scalar(0,255,0));
    static int nNewImgCnt = 0;
    nNewImgCnt++;

    //ostringstream ostream;
    //ostream << "imagelab" << nNewImgCnt << ".bmp";
    //string str = ostream.str();
    string str = "imagelab" + to_string(nNewImgCnt) + ".bmp";
    m_strCurFile.fromStdString(str);
    setItemScene(m_Img);
}


bool CMdiChildImage::loadFile(const QString &fileName)
{
  m_Img = imread(fileName.toStdString());
  if (m_Img.empty())
    return false;

  m_strCurFile = fileName;
  setItemScene(m_Img);
  return true;
}

void CMdiChildImage::setItemScene(Mat img)
{
  item->setPixmap(cvMatToQPixmap(img));
  scene->addItem(item);
  setScene(scene);
}


bool CMdiChildImage::save()
{
	if (isUntitled) {
		return saveAs();
	}
	else {
		return saveFile(m_strCurFile);
	}
}

bool CMdiChildImage::saveAs()
{
	QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"),m_strCurFile,"*.jpg");
	if (fileName.isEmpty())
		return false;

	return imwrite(fileName.toStdString(),m_Img);
}

bool CMdiChildImage::saveFile(const QString &fileName)
{
	return imwrite(fileName.toStdString(), m_Img);
}