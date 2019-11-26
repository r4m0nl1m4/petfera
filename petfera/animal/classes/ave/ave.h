
//Main for "ave" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Guarda
#ifndef AVE_H
#define AVE_H

//Bibliotecas novas
#include "../../animal.h"

class Ave : public Animal
{
    protected:
        double _tamanho_do_bico_cm;
        double _envergadura_cm;
    public:
        Ave();
        Ave(int id,                   \
            string nome_cienctifico,  \
            char sexo,                \
            double tamanho_cm,        \   
            string dieta,             \
            int veterinario,          \
            int tratador,             \
            string nome_batismo,      \
            double tamanho_do_bico_cm,\
            double envergadura_cm     );
        ~Ave();
        string get_reino();
        string get_especificidades();
};

#endif