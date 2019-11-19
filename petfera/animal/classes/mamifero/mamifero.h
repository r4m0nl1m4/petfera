
//Main for "mamifero" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Guarda
#ifndef mamifero_H
#define mamifero_H

//Bibliotecas novas
#include ".../animal.h"

class mamifero : public animal 
{
    public:
        //contador objetos
        static int total;
    protected:
        //propriedades
        std::string cor_pelo;
    public:        
        //Construtores
        mamifero( int _id,                     \
                  std::string _classe,         \
                  std::string _nome_cientifico,\
                  char _sexo,                  \
                  double _tamanho,             \
                  std::string _dieta,          \
                  Veterinario _veterinario,    \
                  Tratador _tratador,          \
                  std::string _cor_pelo        ) : animal( _id,             \
                                                           _classe,         \
                                                           _nome_cientifico,\
                                                           _sexo,           \
                                                           _tamanho,        \
                                                           _dieta,          \
                                                           _veterinario,    \
                                                           _tratador        )
        {
            cor_pelo = _cor_pelo;
            total++;
        }
        mamifero() { total++; }
        //Destrutor
        ~mamifero() {}
        //Inserção e obtenção
        static int getTotal() { return total; }
};

#endif    /* mamifero_H */