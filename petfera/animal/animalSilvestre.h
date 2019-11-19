
//Main for "animalSilvestre" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Guarda
#ifndef animalSilvestre_H
#define animalSilvestre_H

//Bibliotecas
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdlib.h>

class animalSilvestre
{
    public:
        //contador objetos
        static int total;
    protected:
        //propriedades
        std::string autorizacao_ibama;
    public:        
        //Construtores
        animalSilvestre(std::string _autorizacao_ibama)
        {
            autorizacao_ibama = __autorizacao_ibama;
            total++;
        }
        animalSilvestre() { total++; }
        //Destrutor
        ~animalSilvestre() {}
        //Inserção e obtenção
        static int getTotal() { return total; }
};

#endif    /* animalSilvestre_H */