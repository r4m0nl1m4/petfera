
//Main for "veterinario" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Guarda
#ifndef VETERINARIO_H
#define VETERINARIO_H

#include "../funcionario.h"

class Veterinario : public Funcionario {
    private:
    string _crmv;

    public:
    Veterinario();
    Veterinario(int id,
                string nome,
                string cpf,
                short idade,
                char tipo_sanguineo,
                char fator_rh,
                string especialidade,
                string crmv);
    ~Veterinario();

    string get_profissao();
    string get_especificidade();
    void set_especificidade(string especificidade);
};


#endif