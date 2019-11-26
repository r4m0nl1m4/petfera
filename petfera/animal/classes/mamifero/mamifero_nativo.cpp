
//Main for "mamifero" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Cabeçalho
#include "./mamifero_nativo.h"

Mamifero_Nativo::Mamifero_Nativo() : Mamifero(), Animal_Nativo() {}

Mamifero_Nativo::Mamifero_Nativo(int id,                 
                                 string nome_cienctifico,
                                 char sexo,              
                                 double tamanho_cm,      
                                 string dieta,           
                                 int veterinario,        
                                 int tratador,           
                                 string nome_batismo,    
                                 string cor_do_pelo,     
                                 string uf_de_origem,    
                                 string autorizacao,     
                                 string autorizacao_ibama) : Mamifero(id,              
                                                                      nome_cienctifico,
                                                                      sexo,            
                                                                      tamanho_cm,      
                                                                      dieta,           
                                                                      veterinario,     
                                                                      tratador,        
                                                                      nome_batismo,    
                                                                      cor_do_pelo      ), Animal_Nativo(uf_de_origem,
                                                                                                  autorizacao,        
                                                                                                  autorizacao_ibama  ){}

Mamifero_Nativo::~Mamifero_Nativo() { /*Usaremos o destrutor padrão*/ }

string Mamifero_Nativo::get_legalidades(){ return this->get_especificacoes_legais(); }