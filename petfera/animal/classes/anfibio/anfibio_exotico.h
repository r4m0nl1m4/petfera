
//Main for "anfibioExotico" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Guarda
#ifndef ANFIBIO_EXOTICO_H
#define ANFIBIO_EXOTICO_H

//Bibliotecas novas
#include "./anfibio.h"
#include "../animal_exotico.h"

class Anfibio_Exotico : public Anfibio, public Animal_Exotico
{
    public:
        Anfibio_Exotico();
        Anfibio_Exotico(int id,                 \
                        string nome_cienctifico,\
                        char sexo,              \
                        double tamanho_cm,      \
                        string dieta,           \ 
                        int veterinario,        \
                        int tratador,           \ 
                        string nome_batismo,    \
                        int total_de_mudas,     \
                        string ultima_muda,     \ 
                        string pais_de_origem,  \
                        string autorizacao_ibama);
        ~Anfibio_Exotico();
        string get_legalidades();
};

#endif