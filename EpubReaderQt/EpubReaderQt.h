#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_EpubReaderQt.h"


class EpubReaderQt : public QMainWindow
{
    Q_OBJECT

public:
    EpubReaderQt(QWidget *parent = nullptr);
    ~EpubReaderQt();

    bool fileLoaded = false;


private:
    Ui::EpubReaderQtClass ui;


private slots:
    void on_selectBookBtn_clicked();
    void on_importBtn_clicked();
    void on_readBtn_clicked();

};
