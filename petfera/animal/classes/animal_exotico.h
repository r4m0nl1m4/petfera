
//Main for "animalExotico" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Guarda
#ifndef ANIMAL_EXOTICO_H
#define ANIMAL_EXOTICO_H

#include "../animal_silvestre.h"

class Animal_Exotico : public Animal_Silvestre{
    protected:
    string _pais_de_origem;
    string _nacionalidade;

    public:
    Animal_Exotico();
    Animal_Exotico(string pais_de_origem, string autorizacao_ibama);
    ~Animal_Exotico();

    string get_especificacoes_legais();
};


#endif 