
//Header for "automoveis" C++ application
//Created by r4m0nl1m4 29/10/2019

//Guarda
#ifndef automoveis_H
#define automoveis_H

//Bibliotecas novas
#include "../veiculos.h"

class automovel : public veiculo 
{
    public:
        //contador objetos
        static int total;
    protected:
        //propriedades
        std::string motor;
    public:        
        //Construtores
        automovel(std::string _marca, float _preco, float _chass, time_t _dataF, std::string _motor);
        automovel();
        //Destrutor
        ~automovel();
        //Inserção e obtenção
        static int getTotal();
        void setMotor(std::string setMotor);
        std::string getMotor();
};

#endif    /* automoveis_H */