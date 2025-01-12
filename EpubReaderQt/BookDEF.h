#pragma once
#include <zip.h>
#include <thread>
#include <chrono>
#include <pugixml.hpp>

#include <QtWidgets/QMainWindow>
#include <qerrormessage.h>
#include "ui_EpubReaderQt.h"

#include <iostream>
#include <cstring>
#include <fstream>
#include "pugixml.hpp"
#include "boost\filesystem.hpp"

using std::cout;

struct epub {
	std::string tempPath;

	const char* metadataINF = "META-INF/container.xml";
	const char* metadata = "content.opf";
	size_t metadataSize = 0;
	int metadataIndex = 0;
	const char* pathToMD = "";

	const char* cover = "cover.jpeg";
	
	int coverIndex = 0;
	const char* pathToCover = "";

	//BOOK
	const char* path2Book;
	std::string title;
	std::string author;
	std::string publisher;

};

extern epub* epb;

struct ParseFile {
public:

	zip_t* za;




	bool extractEpub(const QString& epubPath, const std::string& tempPath) {
		int err = 0;
		zip* archive = zip_open(epubPath.toStdString().c_str(), 0, &err);

		if (!archive) {
			return false;
		}

		// Get number of entries in zip
		zip_int64_t numEntries = zip_get_num_entries(archive, 0);

		// First pass: create all directories
		for (zip_int64_t i = 0; i < numEntries; i++) {
			const char* name = zip_get_name(archive, i, 0);
			if (!name) continue;

			std::string fullPath = tempPath + "/" + std::string(name);
			boost::filesystem::path filePath(fullPath);

			// Create directory for this entry
			if (name[strlen(name) - 1] == '/') {
				// It's a directory entry
				boost::filesystem::create_directories(fullPath);
				qDebug() << "Create Directory 1: " << fullPath;
			}
			else {
				// It's a file, but still create its parent directory
				boost::filesystem::create_directories(filePath.parent_path());
			}
		}

		// Second pass: extract all files
		for (zip_int64_t i = 0; i < numEntries; i++) {
			const char* name = zip_get_name(archive, i, 0);
			if (!name) continue;

			// Skip directories in second pass
			if (name[strlen(name) - 1] == '/') continue;

			std::string fullPath = tempPath + "/" + std::string(name);
			qDebug() << "Create Directory 2: " << fullPath;
			// Open the file in the archive
			zip_file* file = zip_fopen_index(archive, i, 0);
			if (!file) continue;

			// Create and open output file
			std::ofstream output(fullPath, std::ios::binary);
			if (!output.is_open()) {
				zip_fclose(file);
				continue;
			}

			// Read and write in chunks
			char buffer[4096];
			zip_int64_t len;
			while ((len = zip_fread(file, buffer, sizeof(buffer))) > 0) {
				output.write(buffer, len);
			}

			output.close();
			zip_fclose(file);
		}

		zip_close(archive);
		return true;
	}
	

	void FindMetadata(std::string path) {
		const char* progname = "Book";
		using std::cout;

		int err;


		const char* rPath = path.c_str();
		qDebug() << rPath;

		za = zip_open(rPath, 0, &err);

		if (za == NULL) {
			zip_error_t error;
			zip_error_init_with_code(&error, err);

			qDebug() << "error opening file " << err;

			//fprintf(stderr, "%s: cannot open zip archive '%s': %s\n",
				//progname, rPath, zip_error_strerror(&error));
			zip_error_fini(&error);
			std::exit(-1);
		}
		else {
			int nFiles = zip_get_num_files(za);

			qDebug("Read Sucessful!\n");

			epb->path2Book = rPath;

			//cout << nFiles << " files found!\n";

			zip_stat_t sb;

			zip_stat(za, epb->metadata, 0, &sb);

			//cout << "Looking for file:" << epb->metadata << "\n";
			for (int i = 0; i <= nFiles; i++) {

				//std::cout << "\nParsing through file " << i + 1 << " of " << nFiles;

				zip_stat_index(za, i, 0, &sb);


				//std::cout << "\nFILE:" << sb.name;

				if (strcmp(epb->metadata, sb.name) == 0) {
					//cout << "\nFILE FOUND!";
					epb->metadataIndex = i;
					epb->metadataSize = sb.size;


					break;
				}

			}

		}

	}






	//Start Debug

	void PrintBuffer(const char* buffer, size_t size) {
		// Output the buffer directly to stdout
		std::cout.write(buffer, size);
		std::cout << std::endl;  // Ensure newline after the output
	}

	void PrintRawBuffer(const char* buffer, size_t size) {
		std::cout << "Raw Buffer (Hex): ";
		for (size_t i = 0; i < size; ++i) {
			std::cout << std::hex << (unsigned int)(unsigned char)buffer[i] << " ";
		}
		std::cout << std::endl;
	}

	//End Debug 



	void ParseMetadata() {

		//cout << "\nOpening File: " << zip_get_name(za, epb->metadataIndex, 0);

		zip_file_t* file = zip_fopen_index(za, epb->metadataIndex, 0);

		char* buffer = new char[epb->metadataSize];

		zip_fread(file, buffer, epb->metadataSize);

		pugi::xml_document doc;

		pugi::xml_parse_result result = doc.load_buffer(buffer, epb->metadataSize);

		const char* nsDC = "http://purl.org/dc/elements/1.1/";


		//To get node element
		pugi::xml_node root = doc.document_element();

		if (root) {

			//cout << "Reading through metadata...\n";
			//cout << "Root Element: " << root.name() << std::endl;

			pugi::xml_node metadata = root.first_child();

			std::this_thread::sleep_for(std::chrono::milliseconds(400));

			//system("cls");

			pugi::xml_node titleNode = metadata.child("dc:title");
			pugi::xml_node creatorNode = metadata.child("dc:creator"); //aka author
			pugi::xml_node publisherNode = metadata.child("dc:publisher");


			if (titleNode) {
				//std::cout << "Title: " << titleNode.child_value() << std::endl;
				epb->title = titleNode.child_value();
			}
			else {
				//std::cerr << "Title not found in the XML!" << std::endl;
			}

			if (creatorNode) {
				//std::cout << "Creator (Author): " << creatorNode.child_value() << std::endl;
				epb->author = creatorNode.child_value();
			}
			else {
				//std::cerr << "Creator (Author) not found in the XML!" << std::endl;
			}
			if (publisherNode) {
				//std::cout << "Publisher: " << publisherNode.child_value() << std::endl;
				epb->publisher = publisherNode.child_value();
			}
			else {
				//std::cerr << "Publisher not found in the XML!" << std::endl;
			}
		}
		else {
			//std::cerr << "No root element found!" << std::endl;
		}


	}

	int countFilesInFolder(const std::string& epubPath,const char *count) {
		int err;
		int fileCount = 0;

		// Open the EPUB (ZIP archive)
		zip_t* zip = zip_open(epubPath.c_str(), 0, &err);
		if (!zip) {
			qDebug() << "Error opening EPUB file:" << zip_strerror(zip);
			return -1;
		}

		// Get the total number of files in the ZIP archive
		int numEntries = zip_get_num_entries(zip, 0);

		// Iterate over all files in the archive
		for (int i = 0; i < numEntries; ++i) {
			// Get the name of the file at index i
			const char* fileName = zip_get_name(zip, i, 0);

			if (fileName) {
				// Check if the file is in the "count" folder
				if (strncmp(fileName, count, 5) == 0) {  // "text/" folder path :: count 
					++fileCount;  
				}
			}
		}

		
		zip_close(zip);

		return fileCount;
	}



};

