
//Main for "veterinario" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Cabeçalho
#include "./veterinario.h"

Veterinario::Veterinario() : Funcionario() { this->_crmv = "?????"; }

Veterinario::Veterinario(int id,
                        string nome,
                        string cpf,
                        short idade,
                        char tipo_sanguineo,
                        char fator_rh,
                        string especialidade,
                        string crmv)
            : Funcionario(id,
                        nome,
                        cpf,
                        idade,
                        tipo_sanguineo,
                        fator_rh,
                        especialidade)
{
    this->_crmv = crmv;
}

Veterinario::~Veterinario(){/* Usaremos o detrutor padrão */}

string Veterinario::get_profissao(){ return "veterinario"; }

string Veterinario::get_especificidade(){ return this->_crmv; }

void Veterinario::set_especificidade(string especificidade){ this->_crmv = especificidade; }