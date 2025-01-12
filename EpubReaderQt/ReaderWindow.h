#pragma once
#ifndef READERWINDOW_H
#define READERWINDOW_H

#include <QMainWindow>
#include "ui_ReaderWindow.h"  // Include the generated UI header

class ReaderWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ReaderWindow(QWidget* parent = nullptr);
    ~ReaderWindow();

    void ShowInfo();
    void DisplayText();
private:
    Ui::MainWindow ui;  // Use the generated UI class for this window
};

#endif // READERWINDOW_H