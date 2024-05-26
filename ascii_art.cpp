#include <iostream>
#include <fstream>
#include <string>
#include "ascii_art.h"

using namespace std;

void ascii_art(string welcome) //ascii art
{
    string line = "";
    ifstream infile;
    infile.open("banner.txt");

    if(infile.is_open())
    {
        while(getline(infile, line))
        {
            cout << line << endl;
        }
    }

    infile.close();
}
