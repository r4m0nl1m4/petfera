
//Main for "funcionario" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Guarda
#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

//Bibliotecas
#include <string>
using std::string;
using std::to_string;
#include <iostream>
using std::ostream;

class Funcionario
{
    protected:
        int _id;
        string _nome;
        string _cpf;
        short _idade;
        char _tipo_sanguineo;
        char _fator_rh;
        string _especialidade;
    public:
        Funcionario();
        Funcionario(int id,
                    string nome,
                    string cpf,
                    short idade,
                    char tipo_sanguineo,
                    char fator_rh,
                    string especialidade);
        ~Funcionario();        
        int get_id();
        virtual string get_profissao() = 0;
        virtual string get_especificidade() = 0;
        virtual void set_especificidade(string especificidade) = 0;
        Funcionario* operator=(Funcionario* obj);
        friend ostream& operator<<(ostream& o, Funcionario* obj);
};

#endif