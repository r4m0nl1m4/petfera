
//Main for "animalExotico" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Cabeçalho
#include "./animal_exotico.h"

Animal_Exotico::Animal_Exotico() : Animal_Silvestre() {
    this->_pais_de_origem = "-";
    this->_nacionalidade = "Exotico";
}

Animal_Exotico::Animal_Exotico(string pais_de_origem, string autorizacao_ibama) : Animal_Silvestre(autorizacao_ibama){
    this->_pais_de_origem = pais_de_origem;
        this->_nacionalidade = "Exotico";

}

Animal_Exotico::~Animal_Exotico(){ /*Usaremos o destrutor padrão*/ }

string Animal_Exotico::get_especificacoes_legais(){
    return this->_nacionalidade + ";" + this->_pais_de_origem + ";" + this->_autorizacao_ibama;
}