
//Main for "mamiferoNativo" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Guarda
#ifndef mamiferoNativo_H
#define mamiferoNativo_H

//Bibliotecas novas
#include "./mamifero.h"
#include "../animalNativo.h"

class mamiferoNativo : public mamifero, animalNativo 
{
    public:
        //contador objetos
        static int total;
    public:        
        //Construtores
        mamiferoNativo( int _id,                       \
                        std::string _classe,           \
                        std::string _nome_cientifico,  \
                        char _sexo,                    \
                        double _tamanho,               \
                        std::string _dieta,            \
                        Veterinario _veterinario,      \
                        Tratador _tratador,            \
                        std::string _cor_pelo,         \
                        std::string _autorizacao_ibama,\
                        std::string _uf_origem,        \
                        std::string _autorizacao       ) : mamifero( _id,             \
                                                                     _classe,         \
                                                                     _nome_cientifico,\
                                                                     _sexo,           \
                                                                     _tamanho,        \
                                                                     _dieta,          \
                                                                     _veterinario,    \
                                                                     _tratador,       \
                                                                     _cor_pelo        ) : animalNativo( _autorizacao_ibama,\
                                                                                                        _uf_origem,        \
                                                                                                        _autorizacao       ) { total++; }
        mamiferoNativo() { total++; }
        //Destrutor
        ~mamiferoNativo() {}
        //Inserção e obtenção
        static int getTotal() { return total; }
};

#endif    /* mamiferoNativo_H */