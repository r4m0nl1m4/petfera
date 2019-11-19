
//Main for "animal" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Guarda
#ifndef animal_H
#define animal_H

//Bibliotecas
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdlib.h>

//Nova Bibliotecas
#include "../funcionario/Veterinario.h"
#include "../funcionario/Tratador.h"

class animal : public Veterinario, Tratador
{
    public:
        //contador objetos
        static int total;
    protected:
        //propriedades
        int id;
        std::string classe, nome_cientifico, dieta, nome_batismo;
        char sexo;
        double tamanho;
        Veterinario veterinario;
        Tratador tratador;
    public:        
        //Construtores
        animal( int _id,                     \
                std::string _classe,         \
                std::string _nome_cientifico,\
                char _sexo,                  \
                double _tamanho,             \
                std::string _dieta,          \
                Veterinario _veterinario,    \
                Tratador _tratador           )
        {
            id = _id;
            classe = _classe;
            nome_cientifico = _nome_cientifico;
            sexo = _sexo;
            tamanho = _tamanho;
            dieta = _dieta;
            veterinario = _veterinario;
            tratador = _tratador;
            total++;
        }
        animal() { total++; }
        //Destrutor
        ~animal() {}
        //Inserção e obtenção
        static int getTotal() { return total; }
};

#endif    /* animal_H */