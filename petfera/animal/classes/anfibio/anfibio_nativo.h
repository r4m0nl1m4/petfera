
//Main for "anfibioNativo" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Guarda
#ifndef ANFIBIO_NATIVO_H
#define ANFIBIO_NATIVO_H

//Bibliotecas novas
#include "./anfibio.h"
#include "../animal_nativo.h"

class Anfibio_Nativo : public Anfibio, public Animal_Nativo
{
    public:
    Anfibio_Nativo();
    Anfibio_Nativo(int id,                 
                   string nome_cienctifico,
                   char sexo,               
                   double tamanho_cm,      
                   string dieta,           
                   int veterinario,        
                   int tratador,           
                   string nome_batismo,    
                   int total_de_mudas,     
                   string ultima_muda,     
                   string uf_de_origem,    
                   string autorizacao,     
                   string autorizacao_ibama);
    ~Anfibio_Nativo();

    string get_legalidades();
};



#endif