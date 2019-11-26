
//Main for "reptil" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Cabeçalho
#include "./reptil.h"

//Contrutores
Reptil::Reptil() : Animal()
{
    this->_venenoso = false;
    this->_tipo_veneno = "-";
}

Reptil::Reptil(int id,                 \
               string nome_cienctifico,\
               char sexo,              \
               double tamanho_cm,      \
               string dieta,           \
               int veterinario,        \
               int tratador,           \
               string nome_batismo,    \
               bool venenoso,          \
               string tipo_veneno      ) : Animal(id,              \
                                                  nome_cienctifico,\
                                                  sexo,            \ 
                                                  tamanho_cm,      \ 
                                                  dieta,           \
                                                  veterinario,     \
                                                  tratador,        \
                                                  nome_batismo     ) 
{
    this->_venenoso = venenoso;
    this->_tipo_veneno = tipo_veneno;
}

//Destrutor
Reptil::~Reptil() { /*Usaremos o destrutor padrão*/ }

//Getters
string Reptil::get_reino()
{
    return "Reptil";
}
string Reptil::get_especificidades()
{
    return to_string(this->_venenoso) + ";" + this->_tipo_veneno;
}