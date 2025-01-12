
#define _CRT_SECURE_NO_WARNINGS
#include "EpubReaderQt.h"
#include <QtWidgets/QApplication>

#include <iostream>
#include <chrono>
#include <thread>
#include <zip.h>
#include "boost/filesystem.hpp"



#include "BookDEF.h"
#include "Book.h"

epub* epb = new epub;
Book* book = new Book;

using namespace boost::filesystem;



path ph = temp_directory_path() / unique_path();


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    EpubReaderQt w;
    create_directories(ph);
    epb->tempPath = ph.string();

    w.show();



    return a.exec();
}
