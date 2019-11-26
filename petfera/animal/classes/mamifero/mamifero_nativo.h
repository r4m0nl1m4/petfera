
//Main for "mamifero" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Guarda
#ifndef MAMIFERO_NATIVO_H
#define MAMIFERO_NATIVO_H

//Bibliotecas novas
#include "./mamifero.h"
#include "../animal_nativo.h"

class Mamifero_Nativo : public Mamifero, public Animal_Nativo{
    public:
    Mamifero_Nativo();
    Mamifero_Nativo(int id,
                    string nome_cienctifico,
                    char sexo,
                    double tamanho_cm,
                    string dieta,
                    int veterinario,
                    int tratador,
                    string nome_batismo,
                    string cor_do_pelo,
                    string uf_de_origem,
                    string autorizacao,
                    string autorizacao_ibama);
    ~Mamifero_Nativo();

    string get_naturalidade();
    string get_legalidades();
};



#endif
