#ifndef WORD_H
#define WORD_H

#include <iostream>
#include <string>
#include "vocab.h"

using namespace std;

class word{
public:
    vocab v;
    string alph;
    string quest;
    string working_word;
    string category;
    void rand_word();
    void show_word(char);
    bool compare_word();
    bool check_word(string);
    void alphabet(string gu, char a , char z);
    void choose_category();
    void show_category();
};

#endif

