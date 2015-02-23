#include <fstream>
#include "Library.h"

using namespace std;

int main()
{
    const char* fileName = "start.txt";
    ifstream bkFile;
    bkFile.open(fileName);
    ofstream newFile;
    newFile.open("newFile.txt");

    Library lib;
    bkFile >> lib;
    //cout << lib.getNumBooks() << endl;
    /*for(int i=0; i<lib.getNumBooks() ; ++i)
    {
        lib.showBook(i);
        cout << endl;
    }*/
    lib.sortGer();
    for(int i=0; i<lib.getNumBooks() ; ++i)
    {
        lib.showBook(i);
        cout << endl;
    }
    newFile << lib;












    cout << endl << endl;
    return 0;
}
