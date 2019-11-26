
//Main for "ave" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Guarda
#ifndef AVE_NATIVO_H
#define AVE_NATIVO_H

//Bibliotecas novas
#include "./ave.h"
#include "../animal_nativo.h"

class Ave_Nativo : public Ave, public Animal_Nativo{
    public:
    Ave_Nativo();
    Ave_Nativo(int id,
            string nome_cienctifico,
            char sexo,
            double tamanho_cm,
            string dieta,
            int veterinario,
            int tratador,
            string nome_batismo,
            double tamanho_do_bico_cm,
            double envergadura_cm,
            string uf_de_origem,
            string autorizacao,
            string autorizacao_ibama);
    ~Ave_Nativo();

    string get_naturalidade();
    string get_legalidades();
};



#endif