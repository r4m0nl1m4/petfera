
//Main for "mamifero" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Cabeçalho
#include "./mamifero.h"

//Contrutores
Mamifero::Mamifero() : Animal()
{
    this->_cor_do_pelo = "-";
}

Mamifero::Mamifero(int id,                 \
                   string nome_cienctifico,\
                   char sexo,              \
                   double tamanho_cm,      \
                   string dieta,           \
                   int veterinario,        \
                   int tratador,           \
                   string nome_batismo,    \
                   string cor_do_pelo      ) : Animal(id,              \
                                                      nome_cienctifico,\ 
                                                      sexo,            \
                                                      tamanho_cm,      \
                                                      dieta,           \
                                                      veterinario,     \
                                                      tratador,        \
                                                      nome_batismo     )
{
    this->_cor_do_pelo = cor_do_pelo;
}
//Destrutor
Mamifero::~Mamifero() { /*Usaremos o destrutor padrão*/ }

//Getters
string Mamifero::get_reino()
{
    return "Mamifero";
}
string Mamifero::get_especificidades()
{
    return this->_cor_do_pelo;
}