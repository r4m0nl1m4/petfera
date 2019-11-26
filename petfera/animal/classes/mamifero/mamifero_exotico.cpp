
//Main for "mamifero" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Cabeçalho
#include "./mamifero_exotico.h"

Mamifero_Exotico::Mamifero_Exotico() : Mamifero(), Animal_Exotico() {}

Mamifero_Exotico::Mamifero_Exotico(int id,                 \
                                   string nome_cienctifico,\
                                   char sexo,              \
                                   double tamanho_cm,      \
                                   string dieta,           \
                                   int veterinario,        \
                                   int tratador,           \
                                   string nome_batismo,    \
                                   string cor_do_pelo,     \
                                   string pais_de_origem,  \
                                   string autorizacao_ibama) : Mamifero(id,              \
                                                                        nome_cienctifico,\
                                                                        sexo,            \ 
                                                                        tamanho_cm,      \  
                                                                        dieta,           \
                                                                        veterinario,     \                                       
                                                                        tratador,        \
                                                                        nome_batismo,    \                                        
                                                                        cor_do_pelo      ), Animal_Exotico(pais_de_origem,
                                                                                                           autorizacao_ibama){}

Mamifero_Exotico::~Mamifero_Exotico() { /*Usaremos o destrutor padrão*/ }

string Mamifero_Exotico::get_legalidades()
{ 
    return this->get_especificacoes_legais();
}