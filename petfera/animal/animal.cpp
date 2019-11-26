
//Main for "animal" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Cabeçalho
#include "./animal.h"

Animal::Animal(){
    this->_id = 0;
    this->_nome_cienctifico = "-";
    this->_sexo = '-';
    this->_tamanho_cm = 0;
    this->_dieta = "-";
    this->_veterinario = 0; // Deve ser um objeto da classe veterinario
    this->_tratador = 0; // Deve ser um objeto da classe Tratador
    this->_nome_batismo = "-";
}

Animal::Animal(int id,
        string nome_cienctifico,
        char sexo,
        double tamanho_cm,
        string dieta,
        int veterinario,
        int tratador,
        string nome_batismo)
{
    this->_id = id;
    this->_nome_cienctifico = nome_cienctifico;
    this->_sexo = sexo;
    this->_tamanho_cm = tamanho_cm;
    this->_dieta = dieta;
    this->_veterinario = veterinario;
    this->_tratador = tratador;
    this->_nome_batismo = nome_batismo;    
}

Animal::~Animal() { /*Usaremos o destrutor padrão*/ }

int Animal::get_id(){ return this->_id; }
int Animal::get_veterinario(){ return this->_veterinario; }
int Animal::get_tratador() {return this->_tratador; }

ostream& operator<< (ostream& o, Animal* obj){
    o << obj->_id << ";";
    o << obj->get_reino() << ";";
    o << obj->get_especificidades() << ";";
    o << obj->_nome_cienctifico << ";";
    o << obj->_sexo << ";";
    o << formate_decimal(obj->_tamanho_cm) << ";";
    o << obj->_dieta << ";";
    o << obj->_veterinario << ";";
    o << obj->_tratador << ";";
    o << obj->_nome_batismo << ";";
    o << obj->get_legalidades() << ";";
    o << "\n";

    return o;
}