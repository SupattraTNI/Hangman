#include <iostream>
#include <string>
#include "restart.h"

using namespace std;

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
