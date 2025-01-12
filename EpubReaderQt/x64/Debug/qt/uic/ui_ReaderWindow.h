/********************************************************************************
** Form generated from reading UI file 'ReaderWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_READERWINDOW_H
#define UI_READERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QTextBrowser *textBrowser;
    QScrollBar *readerScroll;
    QLabel *label;
    QLineEdit *displayTitle;
    QProgressBar *progressBar;
    QCheckBox *c_Fullscreen;
    QCheckBox *c_ShowProgress;
    QCheckBox *c_NightMode;
    QLabel *imageLabel;
    QCheckBox *checkBox;
    QPushButton *tocBtn;
    QPushButton *bookmarkBtn;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1279, 774);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(140, 10, 1131, 711));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        textBrowser = new QTextBrowser(frame);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(0, 0, 1131, 711));
        readerScroll = new QScrollBar(centralwidget);
        readerScroll->setObjectName("readerScroll");
        readerScroll->setGeometry(QRect(140, 720, 1131, 16));
        readerScroll->setOrientation(Qt::Orientation::Horizontal);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 190, 71, 16));
        displayTitle = new QLineEdit(centralwidget);
        displayTitle->setObjectName("displayTitle");
        displayTitle->setGeometry(QRect(0, 210, 113, 24));
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(0, 240, 118, 16));
        progressBar->setValue(24);
        c_Fullscreen = new QCheckBox(centralwidget);
        c_Fullscreen->setObjectName("c_Fullscreen");
        c_Fullscreen->setGeometry(QRect(0, 260, 77, 22));
        c_ShowProgress = new QCheckBox(centralwidget);
        c_ShowProgress->setObjectName("c_ShowProgress");
        c_ShowProgress->setGeometry(QRect(0, 280, 101, 22));
        c_NightMode = new QCheckBox(centralwidget);
        c_NightMode->setObjectName("c_NightMode");
        c_NightMode->setGeometry(QRect(0, 300, 91, 22));
        imageLabel = new QLabel(centralwidget);
        imageLabel->setObjectName("imageLabel");
        imageLabel->setGeometry(QRect(10, 20, 111, 161));
        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(0, 320, 101, 22));
        tocBtn = new QPushButton(centralwidget);
        tocBtn->setObjectName("tocBtn");
        tocBtn->setGeometry(QRect(0, 400, 131, 24));
        bookmarkBtn = new QPushButton(centralwidget);
        bookmarkBtn->setObjectName("bookmarkBtn");
        bookmarkBtn->setGeometry(QRect(0, 430, 131, 24));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1279, 21));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Book Name", nullptr));
        c_Fullscreen->setText(QCoreApplication::translate("MainWindow", "Fullscreen", nullptr));
        c_ShowProgress->setText(QCoreApplication::translate("MainWindow", "Show Progress", nullptr));
        c_NightMode->setText(QCoreApplication::translate("MainWindow", "Night Mode", nullptr));
        imageLabel->setText(QString());
        checkBox->setText(QCoreApplication::translate("MainWindow", "Japanese Mode", nullptr));
        tocBtn->setText(QCoreApplication::translate("MainWindow", "Table of Contents", nullptr));
        bookmarkBtn->setText(QCoreApplication::translate("MainWindow", "Bookmark", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_READERWINDOW_H
