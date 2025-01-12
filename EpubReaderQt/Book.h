#pragma once


#include <iostream>
#include <string>
#include <qstring.h>
#include "BookDEF.h"


class Book
{
private:

	std::string title;
	std::string author;
	std::string publisher;

	

	int pageNumber;


public:
	void SetBook(std::string path, const char* title, const char* author, const char* publisher);
	Book();

	std::string bookPath;
	const char* getName() {
		return title.c_str();
	}

	const char* getAuthor() {
		return author.c_str();
	}

	const char* getPublisher() {
		return publisher.c_str();
	}

	int getPageNumber() {
		return pageNumber;
	}

};



