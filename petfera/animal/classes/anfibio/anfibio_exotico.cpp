
//Main for "anfibioExotico" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Cabeçalho
#include "./anfibio_exotico.h"

Anfibio_Exotico::Anfibio_Exotico() : Anfibio(), Animal_Exotico() {}

Anfibio_Exotico::Anfibio_Exotico(int id,                 \
                                 string nome_cienctifico,\
                                 char sexo,              \
                                 double tamanho_cm,      \
                                 string dieta,           \
                                 int veterinario,        \
                                 int tratador,           \
                                 string nome_batismo,    \
                                 int total_de_mudas,     \
                                 string ultima_muda,     \
                                 string pais_de_origem,  \
                                 string autorizacao_ibama) : Anfibio(id,              \
                                                                     nome_cienctifico,\
                                                                     sexo,            \
                                                                     tamanho_cm,      \
                                                                     dieta,           \
                                                                     veterinario,     \
                                                                     tratador,        \
                                                                     nome_batismo,    \
                                                                     total_de_mudas,  \
                                                                     ultima_muda      ), Animal_Exotico(pais_de_origem,  \
                                                                                                        autorizacao_ibama){}
                                        
Anfibio_Exotico::~Anfibio_Exotico() { /*Usaremos o destrutor padrão*/ }

string Anfibio_Exotico::get_legalidades(){ return this->get_especificacoes_legais(); }