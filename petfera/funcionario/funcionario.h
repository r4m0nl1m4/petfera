
//Main for "funcionario" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Guarda
#ifndef funcionario_H
#define funcionario_H

//Bibliotecas
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdlib.h>

class funcionario
{
    public:
        //contador objetos
        static int total;
    protected:
        //propriedades
        int id;
        std::string nome, cpf, especialidade;
        short idade, tipo_sanguineo;
        char fator_rh;
    public:        
        //Construtores
        funcionario( int _id,                   \
                     std::string _nome,         \
                     std::string _cpf,          \
                     short _idade,              \ 
                     short _tipo_sanguineo,     \
                     char _fator_rh,            \
                     std::string _especialidade )
        {
            id = _id,                        \
            nome = _nome,                    \
            cpf = _cpf,                      \
            idade = _idade,                  \ 
            tipo_sanguineo = _tipo_sanguineo,\
            fator_rh = _fator_rh,            \
            especialidade = _especialidade
        }
        funcionario() { total++; }
        //Destrutor
        ~funcionario() {}
        //Inserção e obtenção
        static int getTotal() { return total; }
};

#endif    /* funcionario_H */