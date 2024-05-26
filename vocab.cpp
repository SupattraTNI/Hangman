#include <iostream>
#include <string>
#include <fstream>
#include "vocab.h"

using namespace std;

void vocab::readVocab()
{
    int a=0, b=0;
    ifstream myfile;
    string line;
    myfile.open ("animal.txt");
    while (getline(myfile,line))
    {
        animal[a] = line;
        a++;
    }
    myfile.close();

    myfile.open ("classroom.txt");
    while (getline(myfile,line))
    {
        classroom[b] = line;
        b++;
    }
    myfile.close();

    // show word in vocab
/*
    for(int j=0;j<10;j++)
    {
        cout << animal[j] << endl ;
    }
    for(int k=0;k<10;k++)
    {
        cout << classroom[k] << endl ;
    }*/
}
