#ifndef MDICHILDTEXT_H
#define MDICHILDTEXT_H
#include <QTextEdit>

class CMdiChildText : public QTextEdit
{
	Q_OBJECT
public:
	CMdiChildText();


	void newFile();
	bool loadFile(const QString &fileName);
	bool save();
	bool saveAs();
	bool saveFile(const QString &fileName);
	QString userFriendlyCurrentFile();
	QString currentFile() { return curFile; }

protected:
	void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;

	private slots:
	void documentWasModified();

private:
	bool maybeSave();
	void setCurrentFile(const QString &fileName);
	QString strippedName(const QString &fullFileName);

	QString curFile;
	bool isUntitled;

};

#endif