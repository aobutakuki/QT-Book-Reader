#include "ReaderWindow.h"
#include "Book.h"


#include <qimagereader.h>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <qtextbrowser.h>
#include <qtextstream.h>
#include <qdir.h>
#include <qfile.h>
#include <qstringlist.h>
#include <qprocess.h>

extern Book* book;

ReaderWindow::ReaderWindow(QWidget* parent) :
    QMainWindow(parent)//, ui(new Ui::MainWindow)
{
    ui.setupUi(this); 
    

    QVector<QString> chapters;
    int currentChapter = 0;


    ShowInfo();
    DisplayText();
}

ReaderWindow::~ReaderWindow()
{


}

void ReaderWindow::ShowInfo() {

    std::string FullCoverPath = "\\cover.jpeg";

    std::string CoverOutputPath = epb->tempPath + FullCoverPath;

    QImage image(QString::fromStdString(CoverOutputPath.c_str()));

    QLabel *label = ui.imageLabel;
    QPixmap pixmap(CoverOutputPath.c_str());
    label->setPixmap(pixmap);

    label->setScaledContents(true);
    label->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);

    label->setMask(pixmap.mask());


    label->show();

    //Text
    QString title = book->getName();
    ui.displayTitle->setText(title);
}

void ReaderWindow::DisplayText()
{
    //CONTENTS
   const std::string ContentFullPath = epb->tempPath + "\\text\\";
   QString directory = QString::fromStdString(ContentFullPath);

//Open text path
   QString currentHtml;

   QString titleXhtmlPath = QString::fromStdString(epb->tempPath) + "\\titlepage.xhtml";

   QFile titleHTML(titleXhtmlPath);
   titleHTML.open(QIODevice::ReadOnly);

   QTextStream in(&titleHTML);
   while (!in.atEnd()) {
       QString line = in.readLine();

       currentHtml.append(line);

       qDebug() << "DISPLAYING..";

   }

   titleHTML.close();

   QDir dir(directory);
   qDebug() << "DIR: " << directory;
   
   QStringList files = dir.entryList(QDir::Files);

   qDebug() << "QSLIST: " << files;



   //Fetch all html files 
   for (qsizetype i = 0; i < files.size(); i++)
   {
       QString path = directory + files.at(i);
       QFile file(path);
       if (!file.open(QIODevice::ReadOnly)) {
           qDebug() << "Failed to open file: " << path << ", Error: " << file.errorString();

           return;
       }

       qDebug() << "READING : " << "INDEX <" << i << ">   :" << file.fileName();

       QTextStream in(&file);
      
       while (!in.atEnd()) {
           QString line = in.readLine();

           currentHtml.append(line);
           
           qDebug() << "DISPLAYING..";

       }


   }

  // QString CSS = QString::fromStdString(epb->tempPath) + "\\stylesheet.css";
   //ui.textBrowser->setStyleSheet(CSS);
   

   //NEED to find solution for TOC links
   //Maybe find character count, and jump to chapter character?? 
   QUrl baseUrl = QUrl::fromLocalFile(QString::fromStdString(epb->tempPath) + "\\");
  ui.textBrowser->setSource(baseUrl.resolved(QUrl("text/part0000.html")));
  qDebug() << "URL: " << baseUrl << "PATH: " << directory;
   ui.textBrowser->setHtml(currentHtml);
   
}