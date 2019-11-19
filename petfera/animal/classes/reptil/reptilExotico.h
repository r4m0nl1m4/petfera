
//Main for "reptilExotico" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Guarda
#ifndef reptilExotico_H
#define reptilExotico_H

//Bibliotecas novas
#include "./reptil.h"
#include "../animalExotico.h"

class reptilExotico : public reptil, animalExotico  
{
    public:
        //contador objetos
        static int total;
    public:        
        //Construtores
        reptilExotico( int _id,                       \
                       std::string _classe,           \
                       std::string _nome_cientifico,  \
                       char _sexo,                    \
                       double _tamanho,               \
                       std::string _dieta,            \
                       Veterinario _veterinario,      \
                       Tratador _tratador,            \
                       bool _venenoso,                \
                       std::string _tipo_veneno,      \
                       std::string _autorizacao_ibama,\ 
                       std::string _pais_origem,      \
                       std::string _autorizacao       ) : reptil( _id,             \
                                                                  _classe,         \
                                                                  _nome_cientifico,\
                                                                  _sexo,           \
                                                                  _tamanho,        \
                                                                  _dieta,          \
                                                                  _veterinario,    \
                                                                  _tratador,       \
                                                                  _venenoso,       \
                                                                  _tipo_veneno     ) : animalExotico( _autorizacao_ibama,\
                                                                                                      _pais_origem,      \
                                                                                                      _autorizacao       ) { total++; }
        reptilExotico() { total++; }
        //Destrutor
        ~reptilExotico() {}
        //Inserção e obtenção
        static int getTotal() { return total; }
};

#endif    /* reptilExotico_H */