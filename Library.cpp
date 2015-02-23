#include "Library.h"

using std::istream;
using std::ostream;

istream& operator>>(istream& is, Library& lib)//!!!!!!!!!!!!!
{
    string temp;
    while(getline(is, temp))
    {
        Book b(temp);
        //std::cout << "\n" << b << "\n";
        lib.addBook(b);
    }
    return is;
}

ostream& operator<<(ostream& os, Library& lib)
{
    for(Book b : lib.library)
        os << b;
    return os;
}

void Library::sortGer()
{
    sort( library.begin(), library.end(), [](const Book &b1, const Book &b2)//чому вмлітає з посиланням
         {
             if( b1.getGer() < b2.getGer() )
                return true;
             else
                return false;
         } );
}

void Library::sortTitle()
{
    sort( library.begin(), library.end(), [](Book b1, Book b2)//чому вмлітає з посиланням
         {
             if( b1.getTitle() < b2.getTitle() )
                return true;
             else
                return false;
         } );
}






