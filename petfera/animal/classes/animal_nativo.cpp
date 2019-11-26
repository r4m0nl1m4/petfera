
//Main for "animalNativo" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Cabeçalho
#include "./animal_nativo.h"

Animal_Nativo::Animal_Nativo() : Animal_Silvestre() {
    this->_uf_de_origem = "-";
    this->_autorizacao = "Nenhuma";
    this->_nacionalidade = "Nativo";
}

Animal_Nativo::Animal_Nativo(string uf_de_origem, string autorizacao, string autorizacao_ibama) : Animal_Silvestre(autorizacao_ibama){
    this->_uf_de_origem = uf_de_origem;
    this->_autorizacao = autorizacao;
    this->_nacionalidade = "Nativo";

}

Animal_Nativo::~Animal_Nativo(){ /*Usaremos o destrutor padrão*/ }

string Animal_Nativo::get_especificacoes_legais(){
    return this->_nacionalidade + ";" + this->_uf_de_origem + ";" + this->_autorizacao_ibama + ";" + this->_autorizacao;
}