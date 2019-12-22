//
// Created by ROVERDOGE on 2019/12/15.
//

#include <fstream>
#include <string>
#include <vector>
#include "LinkedList.h"
#ifndef PROJECT_FILE_H
#define PROJECT_FILE_H
using namespace std;

class File {
public:
    template <class T1/*LinkedList*/,class T2/*Person*/>
    void writeFile_Managers(string fname);
    template <class T1/*LinkedList*/,class T2/*Person*/>
    void writeFile_Technicians(string fname);
    template <class T1/*LinkedList*/,class T2/*Person*/>
    void writeFile_SalesMans(string fname);
    template <class T1/*LinkedList*/,class T2/*Person*/>
    void writeFile_SalesManagers(string fname);
    template <class T1,class T2>
    void readFile_Managers(string fname,ifstream &infile);
    template <class T1,class T2>
    void readFile_Technicians(string fname,ifstream &infile);
    template <class T1,class T2>
    void readFile_SalesMans(string fname,ifstream &infile);
    template <class T1,class T2>
    void readFile_SalesManagers(string fname,ifstream &infile);
private:
    string data;
};


#endif //PROJECT_FILE_H
