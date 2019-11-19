
//Main for "anfibioNativo" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Guarda
#ifndef anfibioNativo_H
#define anfibioNativo_H

//Bibliotecas novas
#include "./anfibio.h"
#include "../animalNativo.h"

class anfibioNativo : public anfibio, animalNativo  
{
    public:
        //contador objetos
        static int total;
    public:        
        //Construtores
        anfibioNativo( int _id,                       \
                       std::string _classe,           \
                       std::string _nome_cientifico,  \
                       char _sexo,                    \
                       double _tamanho,               \
                       std::string _dieta,            \
                       Veterinario _veterinario,      \
                       Tratador _tratador,            \
                       int _total_de_mudas,           \
                       time_t _ultima_muda,           \ 
                       std::string _autorizacao_ibama,\
                       std::string _uf_origem,        \
                       std::string _autorizacao       ) : anfibio( _id,             \
                                                                   _classe,         \
                                                                   _nome_cientifico,\
                                                                   _sexo,           \
                                                                   _tamanho,        \
                                                                   _dieta,          \
                                                                   _veterinario,    \
                                                                   _tratador,       \
                                                                   _total_de_mudas, \
                                                                   _ultima_muda     ) : animalNativo( _autorizacao_ibama,\
                                                                                                      _uf_origem,        \
                                                                                                      _autorizacao       ) { total++; }
        anfibioNativo() { total++; }
        //Destrutor
        ~anfibioNativo() {}
        //Inserção e obtenção
        static int getTotal() { return total; }
};

#endif    /* anfibioNativo_H */