
//Main for "anfibioExotico" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Guarda
#ifndef anfibioExotico_H
#define anfibioExotico_H

//Bibliotecas novas
#include "./anfibio.h"
#include "../animalExotico.h"

class anfibioExotico : public anfibio, animalExotico
{
    public:
        //contador objetos
        static int total;
    public:        
        //Construtores
        anfibioExotico( int _id,                       \
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
                        std::string _pais_origem,      \
                        std::string _autorizacao       ) : anfibio( _id,             \
                                                                    _classe,         \
                                                                    _nome_cientifico,\
                                                                    _sexo,           \
                                                                    _tamanho,        \
                                                                    _dieta,          \
                                                                    _veterinario,    \
                                                                    _tratador,       \
                                                                    _total_de_mudas, \
                                                                    _ultima_muda     ) : animalExotico( _autorizacao_ibama,\
                                                                                                        _pais_origem,      \
                                                                                                        _autorizacao       ) { total++; }
        anfibioExotico() { total++; }
        //Destrutor
        ~anfibioExotico() {}
        //Inserção e obtenção
        static int getTotal() { return total; }
};

#endif    /* anfibioExotico_H */