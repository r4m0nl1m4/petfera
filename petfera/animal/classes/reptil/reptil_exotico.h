
//Main for "reptil_exotico" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Guarda
#ifndef REPTIL_EXOTICO_H
#define REPTIL_EXOTICO_H

//Bibliotecas novas
#include "./reptil.h"
#include "../animal_exotico.h"

class Reptil_Exotico : public Reptil, public Animal_Exotico
{
    public:
    Reptil_Exotico();

    Reptil_Exotico(int id,                  
                   string nome_cienctifico,
                   char sexo,              
                   double tamanho_cm,      
                   string dieta,           
                   int veterinario,         
                   int tratador,           
                   string nome_batismo,     
                   bool venenoso,          
                   string tipo_veneno,     
                   string pais_de_origem,  
                   string autorizacao_ibama);

    ~Reptil_Exotico();

    string get_legalidades();
};

#endif