
//Main for "reptil" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Guarda
#ifndef REPTIL_H
#define REPTIL_H

//Bibliotecas novas
#include "../../animal.h"

class Reptil : public Animal{
    protected:
    bool _venenoso;
    string _tipo_veneno;
    
    public:
    Reptil();
    
    Reptil(int id,
        string nome_cienctifico,
        char sexo,
        double tamanho_cm,
        string dieta,
        int veterinario,
        int tratador,
        string nome_batismo,
        bool venenoso,
        string tipo_veneno);

    ~Reptil();
    string get_reino();
    string get_especificidades();
};

#endif
