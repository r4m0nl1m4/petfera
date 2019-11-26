
//Main for "tratador" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Guarda
#ifndef TRATADOR_H
#define TRATADOR_H

//Bibliotecas
#include "../funcionario.h"

class Tratador : public Funcionario
{
    private:
        int _nivel_de_seguranca;
    public:
        Tratador();
        Tratador(int id,
                 string nome,
                 string cpf,
                 short idade,
                 char tipo_sanguineo,
                 char fator_rh,
                 string especialidade,
                 int nivel_de_seguranca);
        ~Tratador();
        string get_profissao();
        string get_especificidade();
        void set_especificidade(string especificidade);
};

#endif