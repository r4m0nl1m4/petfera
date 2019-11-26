
//Main for "ave" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Guarda
#ifndef AVE_EXOTICO_H
#define AVE_EXOTICO_H

//Bibliotecas novas
#include "./ave.h"
#include "../animal_exotico.h"

class Ave_Exotico : public Ave, public Animal_Exotico{
    public:
    Ave_Exotico();
    Ave_Exotico(int id,
                string nome_cienctifico,
                char sexo,
                double tamanho_cm,
                string dieta,
                int veterinario,
                int tratador,
                string nome_batismo,
                double tamanho_do_bico_cm,
                double envergadura_cm,
                string pais_de_origem,
                string autorizacao_ibama);
    ~Ave_Exotico();
    
    string get_naturalidade();
    string get_legalidades();
};



#endif