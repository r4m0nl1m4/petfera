
//Main for "reptil_nativo" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Cabeçalho
#include "./reptil_nativo.h"

Reptil_Nativo::Reptil_Nativo() : Reptil(), Animal_Nativo() {}

Reptil_Nativo::Reptil_Nativo(int id,
                            string nome_cienctifico,
                            char sexo,
                            double tamanho_cm,
                            string dieta,
                            int veterinario,
                            int tratador,
                            string nome_batismo,
                            bool venenoso,
                            string tipo_veneno,
                            string uf_de_origem,
                            string autorizacao,
                            string autorizacao_ibama)
                : Reptil(id,
                        nome_cienctifico,
                        sexo,
                        tamanho_cm,
                        dieta,
                        veterinario,
                        tratador,
                        nome_batismo,
                        venenoso,
                        tipo_veneno)
                , Animal_Nativo(uf_de_origem,
                                autorizacao,
                                autorizacao_ibama) {}

Reptil_Nativo::~Reptil_Nativo() { /*Usaremos o destrutor padrão*/ }

string Reptil_Nativo::get_naturalidade() {return "Nativo"; }
string Reptil_Nativo::get_legalidades(){ return this->get_especificacoes_legais(); }