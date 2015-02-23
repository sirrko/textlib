#include <iostream>
#include "book.h"
using std::cout;
using std::endl;
using std::string;
using std::istream;
using std::ostream;
using std::setw;

void trimString(string& modStr);

Book::Book(const string& str): ger(0), author("\"no author\""), title("\"no title\""), cityPubl("\"no city\""),
                publisher("\"no publ\""), yearPubl(0), index(0), readerCheck(false),
                reader("\"no reader\"")
{
    if( !str.empty() )
        stringToBook(str);
}

bool Book::stringToBook(const string& dirtyString)
{
    int typeField = 0;
    size_t checkPoint = 0;
    for(size_t i=0; i<dirtyString.length(); ++i)
    {
        while(i<dirtyString.length() && dirtyString.at(i) != ';')
            ++i;
        typeField++;
        switch(typeField)
        {
            case 1: // ger
                for( size_t j = checkPoint; j<i; ++j )
                    while( isdigit(dirtyString.at(j)) )
                        ger = static_cast<short>( dirtyString.at(j++) - '0' ) + ger*10;
                checkPoint = i;
                break;
            case 2: // autor
                author = dirtyString.substr( checkPoint+1, i-checkPoint-1 );
                trimString(author);
                checkPoint = i;
                break;
            case 3: // title
                title = dirtyString.substr( checkPoint+1, i-checkPoint-1 );
                trimString(title);
                checkPoint = i;
                break;
            case 4: // city and publ and year
                if( isdigit(dirtyString[checkPoint+1]) )
                    for( size_t j = checkPoint+1; j<i; ++j )
                        while( isdigit(dirtyString.at(j)) )
                            yearPubl = static_cast<short>( dirtyString.at(j++) - '0' ) +
                                yearPubl*10;
                else
                {
                    size_t jInt = checkPoint+1;//позиція після ;
                    size_t internalCheckPoint = checkPoint;
                    for( ; jInt<i; ++jInt )
                    {
                        if( dirtyString[jInt] == ':' )//шукаю знак ":" місто видання
                        {
                            cityPubl = dirtyString.substr( checkPoint+1, jInt-checkPoint-1 );
                            internalCheckPoint = jInt;
                            break;
                        }
                    }
                    for( size_t j = internalCheckPoint+1; j<i; ++j )
                        if( isdigit(dirtyString[j]) )//знайшов цифру і розбиваю на два
                        {//...можна орієнтуватися по комі і стерти перевірку
                            publisher = dirtyString.substr( internalCheckPoint+1,
                                                           j-internalCheckPoint-1 );
                            //publisher.erase( std::remove( publisher.begin(), publisher.end(),
                             //                            ' ' ), publisher.end() );
                            /*publisher.erase(std::find_if(publisher.rbegin(), publisher.rend(),
                                std::not1(std::ptr_fun<int, int>(std::isspace))).base(),
                                            publisher.end());
                            publisher.erase(publisher.begin(), std::find_if(publisher.begin(),
                                publisher.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
                            */
                            if( !isalpha( dirtyString.back() ) )
                                publisher.pop_back();
                            yearPubl = static_cast<short>( stoi( dirtyString.substr( j, 4 ) ) );
                            trimString(cityPubl);
                            trimString(publisher);
                            if(publisher.back() == ',')
                                publisher.pop_back();
                            break;
                        }
                }
                checkPoint = i;
                break;
            case 5://index
                for( size_t j = checkPoint+1; j<i; ++j )
                        while( isdigit(dirtyString.at(j)) )
                            index = static_cast<short>( dirtyString.at(j++) - '0' ) +
                                index*10;
                checkPoint = i;
                break;
            case 6://reader
                if( dirtyString.at(checkPoint+1) != '*' )
                {
                    reader = dirtyString.substr( checkPoint+1,
                                                dirtyString.length() - checkPoint - 2);
                    //cout << "\n" << dirtyString.length()-1 - checkPoint-1 << endl;
                    //cout << dirtyString[dirtyString.length()-1];
                }
                trimString(reader);
                break;
        }

    }
    return true;
}

void Book::showBook() const
{
    std::cout << "Ger " << ger <<
    "\nAuthor " << author <<
    "\nTitle " << title <<
    "\nCityPubl " << cityPubl <<
    "\nPublisher " << publisher <<
    "\nPubl year " << yearPubl <<
    "\nIndex " << index <<
    "\nReader " << reader;

}

istream& operator>>(istream& is, Book& b)
{
    string temp;
    getline( is, temp );
    b.stringToBook(temp);
    return is;
}

ostream& operator<<(ostream& os, const Book& b)
{
    os <<
    "Ger " << b.ger <<
    "\nAuthor " << b.author <<
    "\nTitle " << b.title <<
    "\nCityPubl "  << b.cityPubl <<
    "\nPublisher "  << b.publisher <<
    "\nPubl year " << b.yearPubl <<
    "\nIndex " << b.index <<
    "\nReader "  << b.reader << endl << endl;
    return os;
}

void trimString(string& modStr)
{
    size_t len = modStr.length();
    /*for(size_t i = 1; i<len; ++i)
        if( modStr[i-1] == ' ' && modStr[i] == ' ' )
        {
            modStr.erase(i, 1);
            i=i-1;
        }*/
    size_t i = 1;
    for( ; i<len; ++i)
        if( modStr[i-1] == ' ' && modStr[i] == ' ' )
        {
            modStr.erase(i, 1);
            i=i-1;
            len--;
        }
    if(modStr.front() == ' ')
    {
        modStr.erase(0, 1);
        len--;
    }
    if(isspace(modStr[len-1]))
        modStr.pop_back();
}






