#include <iostream>
#include <ctime>
#include <cstring>
#include <string>
#include <fstream>
#include "HangMan.h"
#include "vocab.h"
#include "word.h"

using namespace std;

bool restart();
void ascii_art(string);

int main()
{
    HangMan man;
    word all_word;
    srand(time(0));

    string gu,test,use;
    char in;
    int mistake = 0;
    all_word.rand_word();

    warp:
        gu = "a e i o u";
        in = {};
        mistake = 0;
        string welcome = "banner.txt";
        ascii_art(welcome);
        all_word.choose_category();
        all_word.rand_word();
        system("cls");

        while(mistake < 6)
        {
            string welcome = "banner.txt";
            ascii_art(welcome);
            all_word.show_category();
            cout << "Your mistake: "<< mistake << endl;
            man.draw_next(mistake);
            cout << "\t\t\t\t";
            all_word.show_word(in);
            cout << endl << endl;
            cout << "\t\talphabet : ";
            all_word.alphabet(gu, 'a','m');
            cout << "\t\t\t   ";
            all_word.alphabet(gu, 'n','z');
            cout << endl << "\t\t\tEnter alphabet : ";
            if(!(all_word.compare_word()))
                cin >> in;
            test = in;
			//use = in;
            //bool n = false;

			if(gu.find(test) == string::npos)
        	{
        		//n = true;
        		gu += ' ';
        		gu += test;
                if(all_word.check_word(test))
                	++mistake;
			}

			system("cls");
            if(all_word.compare_word())
                break;
            cout << endl;
        };

    man.draw_next(mistake);
    cout << "\t\t\t\t";
    all_word.show_word(in);
    cout << endl;

    if(all_word.compare_word())
        cout << "Congratulation! You win." << endl << endl ;
    else
        cout << endl << "You lose." << endl << endl ;

    if(restart())
    {
        system("cls");
        goto warp;
    }
    return 0;
}

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

bool restart() // ask to play again
{
    string result;
    cout << "Do you want to play again ?" << endl
         << "==> If yes type 'Y' / No type 'N' : " ;

    do
    {
        cin >> result;
        if (result == "Y" || result == "y")
            {
                return true;
            }
        else if (result == "N" || result == "n")
            {
                cout << endl
                     << "Thanks for enjoy our game ^^" << endl;
                return false;
            }
        else
            cout << "Wrong input. Please try again : ";
    } while (!(result == "Y" || result == "N" || result == "y" || result == "n"));
}
