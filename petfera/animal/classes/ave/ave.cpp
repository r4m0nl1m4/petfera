
//Main for "ave" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Cabeçalho
#include "./ave.h"

// contrutores
Ave::Ave() : Animal() {
    this->_tamanho_do_bico_cm = 0;
    this->_envergadura_cm = 0;
}

Ave::Ave(int id,
        string nome_cienctifico,
        char sexo,
        double tamanho_cm,
        string dieta,
        int veterinario,
        int tratador,
        string nome_batismo,
        double tamanho_do_bico_cm,
        double envergadura_cm)
    : Animal(id,
            nome_cienctifico,
            sexo,
            tamanho_cm,
            dieta,
            veterinario,
            tratador,
            nome_batismo)
{
    this->_tamanho_do_bico_cm = tamanho_do_bico_cm;
    this->_envergadura_cm = envergadura_cm; 
}

//Destrutor
Ave::~Ave() { /*Usaremos o destrutor padrão*/ }

//Getters
string Ave::get_reino() { return "Ave"; }

string Ave::get_especificidades(){
    return formate_decimal(this->_tamanho_do_bico_cm) + ";" + formate_decimal(this->_envergadura_cm);
}