
//Main for "tratador" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Guarda
#ifndef tratador_H
#define tratador_H

//Bibliotecas novas
#include "../funcionario.h"

class tratador : public funcionario 
{
    public:
        //contador objetos
        static int total;
    protected:
        //propriedades
        int nivel_de_seguranca;
    public:        
        //Construtores
        tratador( int _id,                   \
                  std::string _nome,         \
                  std::string _cpf,          \
                  short _idade,              \ 
                  short _tipo_sanguineo,     \
                  char _fator_rh,            \
                  std::string _especialidade,\
                  int _nivel_de_seguranca    ) : funcionario( _id,            \
                                                              _nome,          \
                                                              _cpf,           \
                                                              _idade,         \ 
                                                              _tipo_sanguineo,\
                                                              _fator_rh,      \
                                                              _especialidade  )
        {
            nivel_de_seguranca = _nivel_de_seguranca;
            total++;
        }
        tratador() { total++; }
        //Destrutor
        ~tratador() {}
        //Inserção e obtenção
        static int getTotal() { return total; }
};

#endif    /* tratador_H */