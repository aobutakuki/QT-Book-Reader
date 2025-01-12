# QT-Book-Reader

This was my first QT project and I tried to make an epub reader based on a epub xml reader project I had made before. 

This project can read epub files and display then in a scroll like interface, the images are loaded properly and the file explorer also works. The program can correctly read the epub xml files and fetch information like author, title, etc. However there are a **few things lacking** in the program. 

The program can display the epub content perfectly but the content table does not work. That is related to the way I parsed the book html and the way the program is displaying it, and probably could be fixed by correcting the method which the program uses to arrange the html files. The program also does not support 縦読み (tateyomi) or asian-style reading, up down and right to left. That means that parsing JP, CH books will result in unwanted western-style formatting. 

My plan was to develop this program a bit futher but I decided to stop this development and focus on other projects. I will, in the future, most likely re-develop this program formatting the code and using a better method. It is probably spaghetti code right now, but it was a interesting learning experience.


Compiled on VS Community 2022
## Requirements:

-QT 6.8.0

Packages:

-Boost filesystem

-Libzip (including libzip redist and libzip symbols)

-Pugixml

