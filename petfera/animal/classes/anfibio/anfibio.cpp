
//Main for "anfibio" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Cabeçalho
#include "./anfibio.h"

//Contrutores
Anfibio::Anfibio() : Animal() {
    this->_total_de_mudas = 0;
    this->_ultima_muda = "00/00/00";
}

Anfibio::Anfibio(int id,
                string nome_cienctifico,
                char sexo,
                double tamanho_cm,
                string dieta,
                int veterinario,
                int tratador,
                string nome_batismo,
                int total_de_mudas,
                string ultima_muda)
        : Animal(id,
                nome_cienctifico,
                sexo,
                tamanho_cm,
                dieta,
                veterinario,
                tratador,
                nome_batismo)
{
    this->_total_de_mudas = total_de_mudas;
    this->_ultima_muda = ultima_muda;
}

//Destrutor
Anfibio::~Anfibio() { /*Usaremos o destrutor padrão*/ }

//Getters
string Anfibio::get_reino() { return "Anfibio"; }
string Anfibio::get_especificidades(){ return to_string(this->_total_de_mudas) + ";" + this->_ultima_muda; }

