#include "Book.h"

void Book::SetBook(std::string path, const char* title, const char* author, const char* publisher) {

	Book::bookPath = path;

	Book::title = title;
	Book::author = author;
	Book::publisher = publisher;


}

Book::Book()
{


}