#ifndef DIRTYBOOKS_H_INCLUDED
#define DIRTYBOOKS_H_INCLUDED

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
using std::fstream; using std::vector; using std::string; using std::cerr;

class DirtyBooks//як зробити, щоб створювався лише один об’єкт (крім перевірки)
{
    fstream bookFile;
    vector<string> dirtyBooks;
public:
    DirtyBooks(char* nameTextFile);
    ~DirtyBooks();
    int addDirtyBook();
    int remDirtyBook();
    inline int getNumDirtyBooks() const;
    inline string getDirtyBook(int num) const;
};

int DirtyBooks::getNumDirtyBooks() const
{
    return dirtyBooks.size();
}

string DirtyBooks::getDirtyBook(int num) const
{
    return dirtyBooks.at(num);
}

#endif // DIRTYBOOKS_H_INCLUDED
