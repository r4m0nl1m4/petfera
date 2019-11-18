
//Body for "veiculos" C++ application
//Created by r4m0nl1m4 29/10/2019

//Cabeçalho
#include "./veiculos.h"

//Construtores

veiculo::veiculo(std::string _marca, float _preco, float _chass, time_t _dataF)
{
    marca = _marca;
    preco = _preco;
    chass = _chass;
    dataF = _dataF;
    total++;
}

veiculo::veiculo()
{
    preco = 0;
    chass = 0;
    dataF = time(NULL);
    total++;
}

//Destrutor

veiculo::~veiculo() {}

//Inserção e obtemção

int veiculo::getTotal()
{
    return total;
}

void veiculo::setMarca(std::string setMarca)
{
    marca = setMarca;
}

std::string veiculo::getMarca()
{
    return marca;
}

void veiculo::setPreco(float setPreco)
{
    preco = setPreco;
}

float veiculo::getPreco()
{
    return preco;
}

void veiculo::setChass(float setChass)
{
    chass = setChass;
}

float veiculo::getChass()
{
    return chass;
}

void veiculo::setDataF(time_t setDataF)
{
    dataF = setDataF;
}

time_t veiculo::getDataF()
{
    return dataF;
}