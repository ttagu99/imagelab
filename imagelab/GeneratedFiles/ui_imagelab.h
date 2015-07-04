/********************************************************************************
** Form generated from reading UI file 'imagelab.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGELAB_H
#define UI_IMAGELAB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_imagelabClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *imagelabClass)
    {
        if (imagelabClass->objectName().isEmpty())
            imagelabClass->setObjectName(QStringLiteral("imagelabClass"));
        imagelabClass->resize(600, 400);
        menuBar = new QMenuBar(imagelabClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        imagelabClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(imagelabClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        imagelabClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(imagelabClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        imagelabClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(imagelabClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        imagelabClass->setStatusBar(statusBar);

        retranslateUi(imagelabClass);

        QMetaObject::connectSlotsByName(imagelabClass);
    } // setupUi

    void retranslateUi(QMainWindow *imagelabClass)
    {
        imagelabClass->setWindowTitle(QApplication::translate("imagelabClass", "imagelab", 0));
    } // retranslateUi

};

namespace Ui {
    class imagelabClass: public Ui_imagelabClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGELAB_H
