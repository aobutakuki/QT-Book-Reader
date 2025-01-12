#include "EpubReaderQt.h"
#include "ReaderWindow.h"
#include "ui_ReaderWindow.h"
#include "ui_EpubReaderQt.h"



#include <string>

#include <qfiledialog.h>
#include <qmessagebox.h>
#include <qimagereader.h>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <qstring.h>

#include "Book.h"
#include "BookDEF.h"
extern epub* epb;
extern Book* book;

QString convertToBackslashPath(const QString& path) {
    QString result = path;
    result.replace("/", "\\");  // Replace all occurrences of '/' with '\\'
    return result;
}

EpubReaderQt::EpubReaderQt(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    ui.titleLine->setVisible(false);
    ui.authorLine->setVisible(false);
    ui.publisherLine->setVisible(false);
    ui.graphicsView->setVisible(false);
    ui.readBtn->setVisible(false);

}

EpubReaderQt::~EpubReaderQt()
{

}

QString bookDir;

void EpubReaderQt::on_selectBookBtn_clicked()
{
    
    qDebug() << "Button clicked";

   bookDir = QFileDialog::getOpenFileName(
        this,
        QObject::tr("Open Book"),
        QDir::currentPath(),
        QObject::tr("Book files (*.epub)"),nullptr);

    qDebug() << "File selected:" << bookDir;

    
    ui.PathLine->setText(bookDir);
    
    if (bookDir != "") {
        fileLoaded = true;
       
    }
    
    
}


void EpubReaderQt::on_importBtn_clicked() {

    if (!fileLoaded) {
        QMessageBox messageBox;
        messageBox.setText("Error: File must first be loaded!");
        messageBox.exec();
    }
    else
    {
        ParseFile parse;
        parse.FindMetadata(bookDir.toStdString().c_str());
        parse.ParseMetadata();

        std::string CoverOutputPath = epb->tempPath + "\\cover.jpeg";
      



        parse.extractEpub(bookDir, epb->tempPath);


        QString ConvertedPath = convertToBackslashPath(bookDir);
        book->SetBook(ConvertedPath.toStdString(), epb->title.c_str(), epb->author.c_str(), epb->publisher.c_str());

        ui.titleLine->setVisible(true);
        ui.authorLine->setVisible(true);
        ui.publisherLine->setVisible(true);
        ui.graphicsView->setVisible(true);
        ui.readBtn->setVisible(true);
        
        QImage image(QString::fromStdString(CoverOutputPath));

        if (image.isNull()) {
            qDebug() << "Failed to load image from path:" << QString::fromStdString(CoverOutputPath);
        }
        else {
            
            image.save("debug_output.jpeg");

            qDebug() << "Image loaded successfully!";
            qDebug() << CoverOutputPath;
            QPixmap pixmap = QPixmap::fromImage(image);


            if (pixmap.isNull()) {
                qDebug() << "Failed to convert QImage to QPixmap.";
            }
            else {
                QGraphicsPixmapItem* pixmapItem = new QGraphicsPixmapItem(pixmap);
                QGraphicsScene* scene = ui.graphicsView->scene();
                if (!scene) {
                    scene = new QGraphicsScene(ui.graphicsView);  
                    ui.graphicsView->setScene(scene);  

                }
                scene->clear();

                scene->addItem(pixmapItem);

                ui.graphicsView->fitInView(pixmapItem->boundingRect(), Qt::KeepAspectRatio);
                ui.graphicsView->show();

            }
        }
       
        ui.TitleLabel->setText("TITLE:");
        QString title = book->getName();
        ui.titleLine->setText(title);

        ui.AuthorLabel->setText("AUTHOR:");
        QString author = book->getAuthor();
        ui.authorLine->setText(author);

        ui.PublisherLabel->setText("PUBLISHER:");
        QString publisher = book->getPublisher();
        ui.publisherLine->setText(publisher);





    }
}

void EpubReaderQt::on_readBtn_clicked() {

    ReaderWindow* readerWindow = new ReaderWindow(this);
    readerWindow->show();

}