
//Main for "animal" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Guarda
#ifndef ANIMAL_H
#define ANIMAL_H

//Bibliotecas
#include <string>
using std::string;
using std::to_string;
#include <ostream>
using std::ostream;
#include <istream>
using std::istream;

//Novas Bibliotecas
#include "./ui.h"

class Animal{
    protected:
    int _id;
    string _nome_cienctifico;
    char _sexo;
    double _tamanho_cm;
    string _dieta;
    int _veterinario;
    int _tratador;
    string _nome_batismo;


    public:
    Animal();
    Animal(int id,
            string nome_cienctifico,
            char sexo,
            double tamanho_cm,
            string dieta,
            int veterinario,
            int tratador,
            string nome_batismo);
    ~Animal();

    // getters
    int get_id();
    int get_veterinario();
    int get_tratador();
    virtual string get_naturalidade() = 0;
        // getters para axuliar na escrita do arquivo como também no polimorfismo da classe animal
    virtual string get_reino() = 0;
    virtual string get_especificidades() = 0;
    virtual string get_legalidades() = 0;
    
    // operadores
        // operador sobrecarregado para axuliar escrita em arquivo
    friend ostream& operator<< (ostream& o, Animal* obj); 
};


#endif