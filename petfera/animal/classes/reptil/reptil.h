
//Main for "reptil" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Guarda
#ifndef reptil_H
#define reptil_H

//Bibliotecas novas
#include ".../animal.h"

class reptil : public veiculo 
{
    public:
        //contador objetos
        static int total;
    protected:
        //propriedades
        bool venenoso;
        std::string tipo_veneno;
    public:        
        //Construtores
        reptil( int _id,                     \
                std::string _classe,         \
                std::string _nome_cientifico,\
                char _sexo,                  \
                double _tamanho,             \
                std::string _dieta,          \
                Veterinario _veterinario,    \
                Tratador _tratador,          \
                bool _venenoso,              \
                std::string _tipo_veneno     ) : animal( _id,             \
                                                         _classe,         \
                                                         _nome_cientifico,\
                                                         _sexo,           \
                                                         _tamanho,        \
                                                         _dieta,          \
                                                         _veterinario,    \
                                                         _tratador        )
        {
            venenoso = _venenoso;
            tipo_veneno = _tipo_veneno;
            total++;
        }
        reptil() { total++; }
        //Destrutor
        ~reptil() {}
        //Inserção e obtenção
        static int getTotal() { return total; }
};

#endif    /* reptil_H */