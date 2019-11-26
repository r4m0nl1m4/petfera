
//Main for "ui" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Guarda
#ifndef UI_H
#define UI_H

//Bibliotecas
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <algorithm>
using std::none_of;
using std::any_of;
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::fixed;
#include <iomanip>
using std::setprecision;
#include <sstream>
using std::stringstream;

string formate_decimal(float decimal);

void clear(); // limpa a tela

void wait(); // espera por o usuario teclar ENTER

#endif