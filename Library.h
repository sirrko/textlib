#ifndef LIBRARY_H_INCLUDED
#define LIBRARY_H_INCLUDED

#include <iostream>
//#define NDEBUG
#include <cassert>
#include <vector>
#include <algorithm>
#include "book.h"

class Library
{
private:
    int numBooks;
    vector<Book> library;
public:
    Library(): numBooks(0) {}
    int getNumBooks() {return numBooks;}
    inline bool addBook(const Book& book);
    inline void showBook(int n);
    void sortGer();
    void sortTitle();
    friend std::istream& operator>>(std::istream& is, Library& lib);
    friend std::ostream& operator<<(std::ostream& os, Library& lib);
};

bool Library::addBook(const Book& book)
{
    library.push_back(book);
    numBooks++;
    return true;
}

void Library::showBook(int n)
{
    // assert( n>=0 && n<library.size() );
    library.at(n).showBook();
}


#endif // LIBRARY_H_INCLUDED
