
//Main for "petfera" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Guarda
#ifndef PETFERA_H
#define PETFERA_H

//Bibliotecas novas
#include "./dados/dados_manip.h"
#include "./user_interface/ui.h"
#include "./rexpression.h"
#include "./animal/animal.h"
#include "./funcionario/funcionario.h"

//Bibliotecas
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <algorithm>
using std::copy_if;

class Petfera{
    private:
        vector<Animal*> animais;
        vector<Funcionario*> funcionarios;
    
    public:
        Petfera();
        ~Petfera();

        void show_menu();

        vector<Animal*> get_animais();
        vector<Funcionario*> get_funcionarios();

        void print_animais();
        void print_funcionarios();

        void buscar_animal();
        void buscar_funcionario();

        void adicionar_animal();
        void remover_animal();
        
        void adicionar_funcionario();
        void remover_funcionario();

        vector<Funcionario*> get_veterinarios();
        vector<Funcionario*> get_tratadores();
};


#endif