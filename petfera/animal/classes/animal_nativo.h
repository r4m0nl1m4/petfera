
//Main for "animalNativo" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Guarda
#ifndef ANIMAL_NATIVO_H
#define ANIMAL_NATIVO_H

#include "../animal_silvestre.h"

class Animal_Nativo : public Animal_Silvestre{
    protected:
    string _uf_de_origem;
    string _autorizacao;
    string _nacionalidade;

    public:
    Animal_Nativo();
    Animal_Nativo(string uf_de_origem, string autorizacao, string autorizacao_ibama);
    ~Animal_Nativo();

    string get_especificacoes_legais();
};


#endif 