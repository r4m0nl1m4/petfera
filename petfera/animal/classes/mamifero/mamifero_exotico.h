
//Main for "mamifero" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Guarda
#ifndef MAMIFERO_EXOTICO_H
#define MAMIFERO_EXOTICO_H

//Bibliotecas novas
#include "./mamifero.h"
#include "../animal_exotico.h"

class Mamifero_Exotico : public Mamifero, public Animal_Exotico
{
    public:
        Mamifero_Exotico();
        Mamifero_Exotico(int id,                 \
                         string nome_cienctifico,\
                         char sexo,              \
                         double tamanho_cm,      \ 
                         string dieta,           \
                         int veterinario,        \
                         int tratador,           \  
                         string nome_batismo,    \
                         string cor_do_pelo,     \
                         string pais_de_origem,  \
                         string autorizacao_ibama);
        ~Mamifero_Exotico();
        string get_legalidades();
};

#endif