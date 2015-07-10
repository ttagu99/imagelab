#ifndef IMAGELAB_H
#define IMAGELAB_H

#include <QMainWindow>
#include "ui_imagelab.h"

class CMdiChildText;
class CMdiChildImage;
QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
class QMdiArea;
class QMdiSubWindow;
class QSignalMapper;
QT_END_NAMESPACE

class imagelab : public QMainWindow
{
	Q_OBJECT

public:
	imagelab(QWidget *parent = 0);
	~imagelab();

private:
	Ui::imagelabClass ui;

	bool openFile(const QString &fileName);
	CMdiChildText *activeMdiChild();
protected:
	void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;

private:
	QMdiArea *mdiArea;
	QSignalMapper *windowMapper;
	QMenu *windowMenu;

	QMenu *fileMenu;
	QMenu *editMenu;
	QMenu *helpMenu;

	QAction *closeAct;
	QAction *closeAllAct;
	QAction *tileAct;
	QAction *cascadeAct;
	QAction *nextAct;
	QAction *previousAct;
	QAction *separatorAct;

	QAction *newAct;
	QAction *openAct;
	QAction *saveAct;
	QAction *saveAsAct;
	QAction *exitAct;
#ifndef QT_NO_CLIPBOARD
	QAction *cutAct;
	QAction *copyAct;
	QAction *pasteAct;
#endif
	QAction *aboutAct;
	//QAction *aboutQtAct;

	void writeSettings();
	void createActions();
	void createMenus();
	void createToolBars();
	void createStatusBar();

	private slots:
	void updateWindowMenu();
	void newFile();

	CMdiChildText *createMdiChildText();
	CMdiChildImage *createMdiChildImage();

};

#endif // IMAGELAB_H
