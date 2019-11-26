
//Main for "rexpression" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Guarda
#ifndef REXPRESSION_H
#define REXPRESSION_H

//Bibliotecas
#include <string>
using std::string;
#include <regex>
using std::regex;
using std::regex_match;

// testa se a string tem o formato de um dia
bool ehDia(string str);
// testa se a string tem o formato de um mes
bool ehMes(string str);
// testa se a string tem o formato de um ano
bool ehAno(string str);

// testa se a string tem o formato de um número
bool ehNum(string str);
// testa se a string tem o formato de um nome
bool ehNome(string str);
// testa se é um tipo sanguineo
bool ehTipoSangue(string str);
// testa se é umfato sanguineo
bool ehRh(string str);

// testa se a string tem o formato de um CPF
bool ehCpf(string str);
// testa se a string tem o formato de um CRMV
bool ehCrmv(string str);

#endif