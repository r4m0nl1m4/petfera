
//Main for "anfibioNativo" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Cabeçalho
#include "./anfibio_nativo.h"

Anfibio_Nativo::Anfibio_Nativo() : Anfibio(), Animal_Nativo() {}

Anfibio_Nativo::Anfibio_Nativo(int id,                 \
                               string nome_cienctifico,\
                               char sexo,              \
                               double tamanho_cm,      \
                               string dieta,           \
                               int veterinario,        \
                               int tratador,           \
                               string nome_batismo,    \
                               int total_de_mudas,     \
                               string ultima_muda,     \
                               string uf_de_origem,    \
                               string autorizacao,     \
                               string autorizacao_ibama) : Anfibio(id,              \
                                                                   nome_cienctifico,\
                                                                   sexo,            \
                                                                   tamanho_cm,      \
                                                                   dieta,           \
                                                                   veterinario,     \
                                                                   tratador,        \
                                                                   nome_batismo,    \
                                                                   total_de_mudas,  \
                                                                   ultima_muda      ), Animal_Nativo(uf_de_origem,\
                                                                                                     autorizacao, \
                                                                                                     autorizacao_ibama){}

Anfibio_Nativo::~Anfibio_Nativo() { /*Usaremos o destrutor padrão*/ }

string Anfibio_Nativo::get_legalidades(){ return this->get_especificacoes_legais(); }