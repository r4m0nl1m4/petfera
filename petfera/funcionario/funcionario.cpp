
//Main for "funcionario" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Cabeçalho
#include "./funcionario.h"

Funcionario::Funcionario()
{
    this->_id = 0;
    this->_nome = "Bla";
    this->_cpf = "123";
    this->_idade = 0;
    this->_tipo_sanguineo = 'a';
    this->_fator_rh = '+';
    this->_especialidade = "nada";
}

Funcionario::Funcionario(int id,
                         string nome,
                         string cpf,
                         short idade,
                         char tipo_sanguineo,
                         char fator_rh,
                         string especialidade)
{
    this->_id = id;
    this->_nome = nome;
    this->_cpf = cpf;
    this->_idade = idade;
    this->_tipo_sanguineo = tipo_sanguineo;
    this->_fator_rh = fator_rh;
    this->_especialidade = especialidade;
}

Funcionario::~Funcionario(){}

Funcionario* Funcionario::operator=(Funcionario* obj)
{
    this->_id = obj->_id;
    this->_nome = obj->_nome;
    this->_cpf = obj->_cpf;
    this->_idade = obj->_idade;
    this->_tipo_sanguineo = obj->_tipo_sanguineo;
    this->_fator_rh = obj->_fator_rh;
    this->_especialidade = obj->_especialidade;
    this->set_especificidade(obj->get_especificidade());
}

int Funcionario::get_id()
{
    return this->_id;
}

ostream& operator<<(ostream& o, Funcionario* obj)
{
    o << obj->_id << ";";
    o << obj->get_profissao() << ";";
    o << obj->_nome << ";";
    o << obj->_cpf << ";";
    o << obj->_idade << ";";
    o << obj->_tipo_sanguineo << ";";
    o << obj->_fator_rh << ";";
    o << obj->_especialidade << ";";
    o << obj->get_especificidade() << ";";

    o << "\n";

    return o;
}