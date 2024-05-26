#include <iostream>
#include <string>
#include "word.h"

using namespace std;

void word::rand_word() //random word for quest
{
    v.readVocab();
    if(category=="1")
        quest = v.animal[rand()%10];
    else
        quest = v.classroom[rand()%10];

    working_word = quest;
    for(int i=0; i < quest.length(); i++)
    {
        if(quest[i] == 'a'||quest[i] == 'e'||quest[i] == 'i'||quest[i] == 'o'||quest[i] == 'u')
            working_word[i] = quest[i];
        else
            working_word[i] = '_';
    }
}

void word::show_word(char c) // show hint
{
    for(int i=0; i<quest.length(); i++)
        if(c == quest[i])
        {
            working_word[i] = quest[i];
            cout << working_word[i] << " " ;
        }
        else
            cout << working_word[i] << " " ;
}

bool word::compare_word() //compare quest & hint
{
    return (working_word == quest);
}

bool word::check_word(string in) // check alphabet you cin
{
	bool won = true;
    string correct;
    for(int i = 0 ; i < quest.length() ; i++)
    {
        if (quest.find(in[i]) != string::npos)
        {
        	won = false;
            correct += ' ';
			return false;
        }
        else
        {
            correct += in[i];
            correct += ' ';
            return true;
        }
    }
    return won;
}

void word::alphabet(string gu, char start , char last) // show alphabet
{
    for(int i = start ; i <= last ; i++ )
    {
        if(gu.find(i) == string::npos)
            cout << char(i) << ' ' ;
        else
            cout << "  ";
    }
    cout << endl;
}

void word::choose_category() //choose category
{
    do
        {
            cout << "Choose category to play: " << endl;
            cout << "Animals   (press 1)" << endl;
            cout << "Classroom (press 2)" << endl;
            cout << "=> " ;
            cin >> category;
            if(!(category=="1" || category=="2"))
                cout << endl << "Wrong input. Please try again " << endl << endl;
        } while (!(category == "1" || category == "2"));
}

void word::show_category() //show category
{
    if(category == "1")
            	{
				  cout << "---NOW : Your category is Animals---";
            	  cout << "\n\n";
                }
            else if(category == "2")
            	{
				  cout << "---NOW : Your category is Classroom---";
            	  cout << "\n\n";
                }
            else
                cout << "Wrong input. Please try again " << endl << endl;
}
