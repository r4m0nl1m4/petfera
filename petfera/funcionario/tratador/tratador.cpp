
//Main for "tratador" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Cabeçalho
#include "./tratador.h"

Tratador::Tratador() : Funcionario() { this->_nivel_de_seguranca = 0; }

Tratador::Tratador(int id,
                string nome,
                string cpf,
                short idade,
                char tipo_sanguineo,
                char fator_rh,
                string especialidade,
                int nivel_de_seguranca)
        : Funcionario(id,
                    nome,
                    cpf,
                    idade,
                    tipo_sanguineo,
                    fator_rh,
                    especialidade)
{
    this->_nivel_de_seguranca = nivel_de_seguranca;
}

Tratador::~Tratador(){/* Usaremos o detrutor padrão */}

string Tratador::get_profissao(){ return "tratador"; }

string Tratador::get_especificidade(){ return to_string(this->_nivel_de_seguranca); }

int Tratador::get_nivel_seguranca(){ return this->_nivel_de_seguranca; }

void Tratador::set_especificidade(string especificidade){ this->_nivel_de_seguranca = stoi(especificidade); }