#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED

#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include "DirtyBooks.h"


class Book
{
private:
    short ger;
    std::string author;
    std::string title;
    std::string cityPubl;
    std::string publisher;
    short yearPubl;
    short index;
    bool readerCheck;
    std::string reader;
public:
    Book(const string& str = "");

    short getGer() const {return ger;}
    std::string getAuthor() const {return author;}
    std::string getTitle() const {return title;}
    std::string getCityPubl() const {return cityPubl;}
    std::string getPublisher() const {return publisher;}
    short getYearPubl() const {return yearPubl;}
    short getIndex() const {return index;}
    bool getReaderCheck() {if(!reader.empty()) readerCheck = true; return readerCheck;}
    std::string getReader() const {return reader;}

    void setGer(int g) {ger = static_cast<short>(g);}
    void setAuthor(const string& a) {author = a;}
    void setTitle(const string& t) {title = t;}
    void setCityPubl(const string& cp) {cityPubl = cp;}
    void setPublisher(const string& p) {publisher = p;}
    void setYearPubl(int yp) {yearPubl = static_cast<short>(yp);}
    void setIndex(int id) {index = id;}
    void setReaderCheck() {if(!reader.empty()) readerCheck = true;}
    void setReader(const string& r) {reader = r;}

    bool stringToBook(const std::string& dirtyString);
    void showBook() const;
    friend void trimString(string& modStr);
    friend std::istream& operator>>(std::istream& is, Book& b);//вводить у книгу з файла
    friend std::ostream& operator<<(std::ostream& os, const Book& b);//виводить з книги на екран
};


void trimString(string& modStr);
std::istream& operator>>(std::istream& is, Book& b);//вводить у книгу з файла
std::ostream& operator<<(std::ostream& os, const Book& b);//виводить з книги на екран

#endif // BOOK_H_INCLUDED
