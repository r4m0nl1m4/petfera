
//Main for "animalSilvestre" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Guarda
#ifndef ANIMAL_SILVESTRE_H
#define ANIMAL_SILVESTRE_H

//Bibliotecas
#include <string>
using std::string;

class Animal_Silvestre{
    protected:
    string _autorizacao_ibama;
    
    public:
    Animal_Silvestre();
    Animal_Silvestre(string atoriazacao_ibama);
    ~Animal_Silvestre();

    virtual string get_especificacoes_legais() = 0;
};


#endif