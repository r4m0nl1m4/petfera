
//Body for "automoveis" C++ application
//Created by r4m0nl1m4 29/10/2019

//Cabeçalho
#include "./automoveis.h"

//Construtores

automovel::automovel(std::string _marca, float _preco, float _chass, time_t _dataF, std::string _motor) : veiculo(_marca, _preco, _chass, _dataF)
{
    motor = _motor;
    total++;
}

automovel::automovel()
{
    total++;
}

//Destrutor

automovel::~automovel() {}

//Inserção e obtenção

int automovel::getTotal()
{
    return total;
}

void automovel::setMotor(std::string setMotor)
{
    motor = setMotor;
}

std::string automovel::getMotor()
{
    return motor;
}