
//Main for "ave" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Guarda
#ifndef ave_H
#define ave_H

//Bibliotecas novas
#include ".../animal.h"

class ave : public animal 
{
    public:
        //contador objetos
        static int total;
    protected:
        //propriedades
        double tamanho_do_bico_cm, envergadura_das_asas;
    public:        
        //Construtores
        ave( int _id,                     \
             std::string _classe,         \
             std::string _nome_cientifico,\
             char _sexo,                  \
             double _tamanho,             \
             std::string _dieta,          \
             Veterinario _veterinario,    \
             Tratador _tratador,          \
             double _tamanho_do_bico_cm,  \
             double _envergadura_das_asas ) : animal( _id,             \
                                                      _classe,         \
                                                      _nome_cientifico,\
                                                      _sexo,           \
                                                      _tamanho,        \
                                                      _dieta,          \
                                                      _veterinario,    \
                                                      _tratador        )
        {
            tamanho_do_bico_cm = _tamanho_do_bico_cm;
            envergadura_das_asas = _envergadura_das_asas;
            total++;
        }
        ave() { total++; }
        //Destrutor
        ~ave() {}
        //Inserção e obtenção
        static int getTotal() { return total; }
};

#endif    /* ave_H */