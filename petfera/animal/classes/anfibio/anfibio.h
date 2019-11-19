
//Main for "anfibio" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Guarda
#ifndef anfibio_H
#define anfibio_H

//Bibliotecas novas
#include ".../animal.h"

class anfibio : public animal 
{
    public:
        //contador objetos
        static int total;
    protected:
        //propriedades
        int total_de_mudas;
        time_t ultima_muda;
    public:        
        //Construtores
        anfibio( int _id,                     \
                 std::string _classe,         \
                 std::string _nome_cientifico,\
                 char _sexo,                  \
                 double _tamanho,             \
                 std::string _dieta,          \
                 Veterinario _veterinario,    \
                 Tratador _tratador,          \
                 int _total_de_mudas,         \
                 time_t _ultima_muda          ) : animal( _id,             \
                                                          _classe,         \
                                                          _nome_cientifico,\
                                                          _sexo,           \
                                                          _tamanho,        \
                                                          _dieta,          \
                                                          _veterinario,    \
                                                          _tratador        )
                {
                    total_de_mudas = _total_de_mudas;
                    ultima_muda = _ultima_muda;
                    total++;
                }
        anfibio() { total++; }
        //Destrutor
        ~anfibio() {}
        //Inserção e obtenção
        static int getTotal() { return total; }
};

#endif    /* anfibio_H */