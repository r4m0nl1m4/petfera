
//Main for "reptilNativo" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Guarda
#ifndef reptilNativo_H
#define reptilNativo_H

//Bibliotecas novas
#include "./reptil.h"
#include "../animalNativo.h"

class reptilNativo : public reptil, animalNativo 
{
    public:
        //contador objetos
        static int total;
    public:        
        //Construtores
        reptilNativo( int _id,                       \
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
                      std::string _uf_origem,        \
                      std::string _autorizacao       ) : reptil( _id,             \
                                                                 _classe,         \
                                                                 _nome_cientifico,\
                                                                 _sexo,           \
                                                                 _tamanho,        \
                                                                 _dieta,          \
                                                                 _veterinario,    \
                                                                 _tratador,       \
                                                                 _venenoso        ) : animalNativo( _autorizacao_ibama,\
                                                                                                    _uf_origem,        \
                                                                                                    _autorizacao       ) { total++; }
        reptilNativo() { total++; }
        //Destrutor
        ~reptilNativo() {}
        //Inserção e obtenção
        static int getTotal() { return total; }
};

#endif    /* reptilNativo_H */