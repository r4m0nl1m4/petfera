
//Main for "reptil_exotico" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Cabeçalho
#include "./reptil_exotico.h"

Reptil_Exotico::Reptil_Exotico() : Reptil(), Animal_Exotico() {}

Reptil_Exotico::Reptil_Exotico(int id,                 \
                               string nome_cienctifico,\
                               char sexo,              \
                               double tamanho_cm,      \
                               string dieta,           \
                               int veterinario,        \
                               int tratador,           \
                               string nome_batismo,    \
                               bool venenoso,          \
                               string tipo_veneno,     \
                               string pais_de_origem,  \
                               string autorizacao_ibama) : Reptil(id,              \
                                                                  nome_cienctifico,\
                                                                  sexo,            \
                                                                  tamanho_cm,      \
                                                                  dieta,           \
                                                                  veterinario,     \
                                                                  tratador,        \
                                                                  nome_batismo,    \
                                                                  venenoso,        \
                                                                  tipo_veneno      ), Animal_Exotico(pais_de_origem,  \
                                                                                                     autorizacao_ibama){}

Reptil_Exotico::~Reptil_Exotico() { /*Usaremos o destrutor padrão*/ }

string Reptil_Exotico::get_legalidades()
{
    return this->get_especificacoes_legais();
}