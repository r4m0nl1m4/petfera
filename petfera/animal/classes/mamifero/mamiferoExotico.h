
//Main for "mamiferoExotico" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Guarda
#ifndef mamiferoExotico_H
#define mamiferoExotico_H

//Bibliotecas novas
#include "./mamifero.h"
#include "../animalExotico.h"

class mamiferoExotico : public mamifero, animalExotico  
{
    public:
        //contador objetos
        static int total;
    public:        
        //Construtores
        mamiferoExotico( int _id,                       \
                         std::string _classe,           \
                         std::string _nome_cientifico,  \
                         char _sexo,                    \
                         double _tamanho,               \
                         std::string _dieta,            \
                         Veterinario _veterinario,      \
                         Tratador _tratador,            \
                         std::string _cor_pelo,         \
                         std::string _autorizacao_ibama,\   
                         std::string _pais_origem,      \
                         std::string _autorizacao       ) : mamifero( _id,             \
                                                                      _classe,         \
                                                                      _nome_cientifico,\
                                                                      _sexo,           \
                                                                      _tamanho,        \
                                                                      _dieta,          \
                                                                      _veterinario,    \
                                                                      _tratador,       \
                                                                      _cor_pelo        ) : animalExotico( _autorizacao_ibama,\
                                                                                                          _pais_origem,      \
                                                                                                          _autorizacao       ) { total++; }
        mamiferoExotico() { total++; }
        //Destrutor
        ~mamiferoExotico() {}
        //Inserção e obtenção
        static int getTotal() { return total; }
};

#endif    /* mamiferoExotico_H */