/********************************************************************************
** Form generated from reading UI file 'EpubReaderQt.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EPUBREADERQT_H
#define UI_EPUBREADERQT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EpubReaderQtClass
{
public:
    QWidget *centralWidget;
    QPushButton *selectBookBtn;
    QFrame *DisplayFrame;
    QLineEdit *titleLine;
    QLabel *TitleLabel;
    QLabel *AuthorLabel;
    QLineEdit *authorLine;
    QLineEdit *publisherLine;
    QLabel *PublisherLabel;
    QGraphicsView *graphicsView;
    QPushButton *readBtn;
    QLineEdit *PathLine;
    QLabel *PathLabel;
    QPushButton *importBtn;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *EpubReaderQtClass)
    {
        if (EpubReaderQtClass->objectName().isEmpty())
            EpubReaderQtClass->setObjectName("EpubReaderQtClass");
        EpubReaderQtClass->resize(600, 400);
        EpubReaderQtClass->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::FolderOpen));
        EpubReaderQtClass->setWindowIcon(icon);
        EpubReaderQtClass->setAutoFillBackground(false);
        centralWidget = new QWidget(EpubReaderQtClass);
        centralWidget->setObjectName("centralWidget");
        selectBookBtn = new QPushButton(centralWidget);
        selectBookBtn->setObjectName("selectBookBtn");
        selectBookBtn->setGeometry(QRect(10, 10, 201, 51));
        DisplayFrame = new QFrame(centralWidget);
        DisplayFrame->setObjectName("DisplayFrame");
        DisplayFrame->setGeometry(QRect(219, 9, 361, 261));
        DisplayFrame->setFrameShape(QFrame::Shape::StyledPanel);
        DisplayFrame->setFrameShadow(QFrame::Shadow::Raised);
        titleLine = new QLineEdit(DisplayFrame);
        titleLine->setObjectName("titleLine");
        titleLine->setEnabled(false);
        titleLine->setGeometry(QRect(80, 10, 113, 24));
        TitleLabel = new QLabel(DisplayFrame);
        TitleLabel->setObjectName("TitleLabel");
        TitleLabel->setGeometry(QRect(10, 10, 51, 20));
        AuthorLabel = new QLabel(DisplayFrame);
        AuthorLabel->setObjectName("AuthorLabel");
        AuthorLabel->setGeometry(QRect(10, 40, 51, 20));
        authorLine = new QLineEdit(DisplayFrame);
        authorLine->setObjectName("authorLine");
        authorLine->setEnabled(false);
        authorLine->setGeometry(QRect(80, 40, 113, 24));
        publisherLine = new QLineEdit(DisplayFrame);
        publisherLine->setObjectName("publisherLine");
        publisherLine->setEnabled(false);
        publisherLine->setGeometry(QRect(80, 70, 113, 24));
        PublisherLabel = new QLabel(DisplayFrame);
        PublisherLabel->setObjectName("PublisherLabel");
        PublisherLabel->setGeometry(QRect(10, 70, 51, 16));
        graphicsView = new QGraphicsView(DisplayFrame);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(210, 10, 131, 192));
        readBtn = new QPushButton(DisplayFrame);
        readBtn->setObjectName("readBtn");
        readBtn->setGeometry(QRect(210, 210, 131, 24));
        PathLine = new QLineEdit(centralWidget);
        PathLine->setObjectName("PathLine");
        PathLine->setGeometry(QRect(220, 280, 361, 24));
        PathLabel = new QLabel(centralWidget);
        PathLabel->setObjectName("PathLabel");
        PathLabel->setGeometry(QRect(170, 280, 31, 16));
        PathLabel->setTextFormat(Qt::TextFormat::AutoText);
        importBtn = new QPushButton(centralWidget);
        importBtn->setObjectName("importBtn");
        importBtn->setGeometry(QRect(10, 80, 201, 41));
        EpubReaderQtClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(EpubReaderQtClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        EpubReaderQtClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(EpubReaderQtClass);
        mainToolBar->setObjectName("mainToolBar");
        EpubReaderQtClass->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(EpubReaderQtClass);
        statusBar->setObjectName("statusBar");
        EpubReaderQtClass->setStatusBar(statusBar);

        retranslateUi(EpubReaderQtClass);

        selectBookBtn->setDefault(true);


        QMetaObject::connectSlotsByName(EpubReaderQtClass);
    } // setupUi

    void retranslateUi(QMainWindow *EpubReaderQtClass)
    {
        EpubReaderQtClass->setWindowTitle(QCoreApplication::translate("EpubReaderQtClass", "EpubReaderQt", nullptr));
        selectBookBtn->setText(QCoreApplication::translate("EpubReaderQtClass", "Select Book", nullptr));
        TitleLabel->setText(QString());
        AuthorLabel->setText(QString());
        PublisherLabel->setText(QString());
        readBtn->setText(QCoreApplication::translate("EpubReaderQtClass", "Read", nullptr));
        PathLabel->setText(QCoreApplication::translate("EpubReaderQtClass", "Path:", nullptr));
        importBtn->setText(QCoreApplication::translate("EpubReaderQtClass", "Import", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EpubReaderQtClass: public Ui_EpubReaderQtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EPUBREADERQT_H
