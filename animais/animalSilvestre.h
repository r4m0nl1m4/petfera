
//Header for "veiculos" C++ application
//Created by r4m0nl1m4 29/10/2019

//Guarda
#ifndef veiculos_H
#define veiculos_H

//Bibliotecas
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdlib.h>

class veiculo
{
    public:
        //contador objetos
        static int total;
    protected:
        //propriedades
        std::string marca;
        float preco, chass;
        time_t dataF;
    public:        
        //Construtores
        veiculo(std::string _marca, float _preco, float _chass, time_t _dataF);
        veiculo();
        //Destrutor
        ~veiculo();
        //Inserção e obtenção
        static int getTotal();
        void setMarca(std::string setMarca);
        std::string getMarca();
        void setPreco(float setPreco);
        float getPreco();
        void setChass(float setChass);
        float getChass();
        void setDataF(time_t setDataF);
        time_t getDataF();
};

#endif    /* veiculos_H */