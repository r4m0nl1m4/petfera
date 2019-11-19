
//Main for "aveExotico" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Guarda
#ifndef aveExotico_H
#define aveExotico_H

//Bibliotecas novas
#include "./ave.h"
#include "../animalExotico.h"

class aveExotico : public ave, animalExotico  
{
    public:
        //contador objetos
        static int total;
    public:        
        //Construtores
        aveExotico( int _id,                       \
                    std::string _classe,           \
                    std::string _nome_cientifico,  \
                    char _sexo,                    \
                    double _tamanho,               \
                    std::string _dieta,            \
                    Veterinario _veterinario,      \
                    Tratador _tratador,            \
                    double _tamanho_do_bico_cm,    \
                    double _envergadura_das_asas,  \
                    std::string _autorizacao_ibama,\
                    std::string _pais_origem,      \
                    std::string _autorizacao       ) : ave( _id,                  \
                                                            _classe,              \
                                                            _nome_cientifico,     \
                                                            _sexo,                \
                                                            _tamanho,             \
                                                            _dieta,               \
                                                            _veterinario,         \
                                                            _tratador,            \
                                                            _tamanho_do_bico_cm,  \
                                                            _envergadura_das_asas ) : animalExotico( _autorizacao_ibama,\ 
                                                                                                     _pais_origem,      \
                                                                                                     _autorizacao       ) { total++; }
        aveExotico() { total++; }
        //Destrutor
        ~aveExotico() {}
        //Inserção e obtenção
        static int getTotal() { return total; }
};

#endif    /* aveExotico_H */