#ifndef PETFERA_H
#define PETFERA_H

#include "dados_manip.h"
#include "ui.h"
#include "animal.h"
#include "funcionario.h"


class Petfera{
    private:
        vector<Animal*> animais;
        vector<Funcionario*> funcionarios;
    
    public:
        Petfera();
        ~Petfera();

        void show_menu();

        void set_animal();
        void set_funcionario();

        void buscar_animal();
        void buscar_funcionario();

        void adicionar_animal();
        void remover_animal();
        
        void adicionar_funcionario();
        void remover_funcionario();
};


#endif