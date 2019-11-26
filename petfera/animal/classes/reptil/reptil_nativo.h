
//Main for "reptil_nativo" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Guarda
#ifndef REPTIL_NATIVO_H
#define REPTIL_NATIVO_H

//Bibliotecas novas
#include "./reptil.h"
#include "../animal_nativo.h"

class Reptil_Nativo : public Reptil, public Animal_Nativo
{
    public:
        Reptil_Nativo();
        Reptil_Nativo(int id,                 
                      string nome_cienctifico,
                      char sexo,              
                      double tamanho_cm,      
                      string dieta,           
                      int veterinario,        
                      int tratador,           
                      string nome_batismo,    
                      bool venenoso,          
                      string tipo_veneno,     
                      string uf_de_origem,    
                      string autorizacao,     
                      string autorizacao_ibama);
        ~Reptil_Nativo();
        string get_legalidades();
};

#endif