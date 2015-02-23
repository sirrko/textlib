#include "DirtyBooks.h"

DirtyBooks::DirtyBooks(char* nameTextFile)
{

    bookFile.open(nameTextFile);
    if( bookFile.is_open() )

    while(bookFile)
    {
        string temp;
        getline( bookFile, temp );
        dirtyBooks.push_back(temp);
    }
}



DirtyBooks::~DirtyBooks()
{
    bookFile.close();
}






