
//Main for "ave" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Cabeçalho
#include "./ave_nativo.h"

Ave_Nativo::Ave_Nativo() : Ave(), Animal_Nativo() {}

Ave_Nativo::Ave_Nativo(int id,                   \
                       string nome_cienctifico,  \
                       char sexo,                \
                       double tamanho_cm,        \
                       string dieta,             \
                       int veterinario,          \
                       int tratador,             \
                       string nome_batismo,      \
                       double tamanho_do_bico_cm,\
                       double envergadura_cm,    \
                       string uf_de_origem,      \
                       string autorizacao,       \
                       string autorizacao_ibama  ) : Ave(id,                \
                                                         nome_cienctifico,  \
                                                         sexo,              \
                                                         tamanho_cm,        \
                                                         dieta,             \
                                                         veterinario,       \
                                                         tratador,          \
                                                         nome_batismo,      \
                                                         tamanho_do_bico_cm,\
                                                         envergadura_cm     ), Animal_Nativo(uf_de_origem,
                                                                                             autorizacao,
                                                                                             autorizacao_ibama){}

Ave_Nativo::~Ave_Nativo() { /*Usaremos o destrutor padrão*/ }

string Ave_Nativo::get_legalidades()
{
    return this->get_especificacoes_legais();
}