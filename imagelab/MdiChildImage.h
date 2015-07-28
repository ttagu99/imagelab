#pragma once
#include <qgraphicsview.h>
#include <QtWidgets>
#include <QImage>
#include <QPixmap>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
namespace ASM {
  inline QImage  cvMatToQImage(const cv::Mat &inMat)
  {
	switch (inMat.type())
	{
		// 8-bit, 4 channel
	case CV_8UC4:
	{
		QImage image(inMat.data, inMat.cols, inMat.rows, inMat.step, QImage::Format_RGB32);

		return image;
	}

	// 8-bit, 3 channel
	case CV_8UC3:
	{
		QImage image(inMat.data, inMat.cols, inMat.rows, inMat.step, QImage::Format_RGB888);

		return image.rgbSwapped();
	}

	// 8-bit, 1 channel
	case CV_8UC1:
	{
		static QVector<QRgb>  sColorTable;

		// only create our color table once
		if (sColorTable.isEmpty())
		{
			for (int i = 0; i < 256; ++i)
				sColorTable.push_back(qRgb(i, i, i));
		}

		QImage image(inMat.data, inMat.cols, inMat.rows, inMat.step, QImage::Format_Indexed8);

		image.setColorTable(sColorTable);

		return image;
	}

	default:
		//qWarning() << "ASM::cvMatToQImage() - cv::Mat image type not handled in switch:" << inMat.type();
		break;
	}

	return QImage();
  }

  inline QPixmap cvMatToQPixmap(const cv::Mat &inMat)
  {
	  return QPixmap::fromImage(cvMatToQImage(inMat));
  }
}



class CMdiChildImage : public QGraphicsView
{
  Q_OBJECT


public:
  CMdiChildImage();
  ~CMdiChildImage();

private:
  QGraphicsScene* scene; 
  QGraphicsPixmapItem* item; 
  Mat m_Img;
  QString m_strCurFile;
  bool isUntitled;

public:
  void newFile();
  bool loadFile(const QString &fileName);
  QString  currentFile() { return m_strCurFile; }
  bool save();
  bool saveAs();
  bool saveFile(const QString &fileName);


private:
  void setItemScene(Mat img);
};

