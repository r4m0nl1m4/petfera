
//Main for "mamifero" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Guarda
#ifndef MAMIFERO_H
#define MAMIFERO_H

//Bibliotecas novas
#include "../../animal.h"

class Mamifero : public Animal{
    protected:
    string _cor_do_pelo;

    public:
    Mamifero();
    Mamifero(int id,
            string nome_cienctifico,
            char sexo,
            double tamanho_cm,
            string dieta,
            int veterinario,
            int tratador,
            string nome_batismo,
            string cor_do_pelo);
    ~Mamifero();
    string get_reino();
    string get_especificidades();
};

#endif