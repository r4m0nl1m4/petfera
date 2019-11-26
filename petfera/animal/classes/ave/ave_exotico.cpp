
//Main for "ave" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Cabeçalho
#include "./ave_exotico.h"

Ave_Exotico::Ave_Exotico() : Ave(), Animal_Exotico() {}

Ave_Exotico::Ave_Exotico(int id,                   
                         string nome_cienctifico,  
                         char sexo,                
                         double tamanho_cm,        
                         string dieta,             
                         int veterinario,          
                         int tratador,             
                         string nome_batismo,      
                         double tamanho_do_bico_cm,
                         double envergadura_cm,    
                         string pais_de_origem,    
                         string autorizacao_ibama  ) : Ave(id,                
                                                           nome_cienctifico,  
                                                           sexo,              
                                                           tamanho_cm,        
                                                           dieta,             
                                                           veterinario,       
                                                           tratador,          
                                                           nome_batismo,      
                                                           tamanho_do_bico_cm, 
                                                           envergadura_cm     ), Animal_Exotico(pais_de_origem,  
                                                                                                autorizacao_ibama){}

Ave_Exotico::~Ave_Exotico() { /*Usaremos o destrutor padrão*/ }

string Ave_Exotico::get_legalidades(){ return this->get_especificacoes_legais(); }