#include <iostream>
#include <string>
#include "HangMan.h"

using namespace std;


void HangMan::draw_next(int mistake) // print body of Hangman
{
	for(int i=0;i<8;i++)
  	{
        cout << "\t\t\t\t";
        cout << hangman[mistake][i] << endl;
  	}
    cout << endl;
}

