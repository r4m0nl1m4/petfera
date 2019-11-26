
//Main for "anfibio" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Guarda
#ifndef ANFIBIO_H
#define ANFIBIO_H

//Bibliotecas novas
#include "../../animal.h"

class Anfibio : public Animal
{
    protected:
        int _total_de_mudas;
        string _ultima_muda; // deve ser uma data ; ideia -> usar um struct, uma classe ou regex
    public:
        Anfibio();
        Anfibio(int id,                  
                string nome_cienctifico,
                char sexo,               
                double tamanho_cm,      
                string dieta,           
                int veterinario,        
                int tratador,           
                string nome_batismo,    
                int total_de_mudas,     
                string ultima_muda      );    
        ~Anfibio();
        string get_reino();
        string get_especificidades();
};

#endif