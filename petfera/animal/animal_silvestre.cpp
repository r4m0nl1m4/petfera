
//Main for "animalSilvestre" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Cabeçalho
#include "./animal_silvestre.h"

Animal_Silvestre::Animal_Silvestre() : _autorizacao_ibama("Nenhuma") {}
Animal_Silvestre::Animal_Silvestre(string autorizacao_ibama){
    this->_autorizacao_ibama = autorizacao_ibama;
}
Animal_Silvestre::~Animal_Silvestre(){/*Usaremos o destrutor padrão*/}