
//Main for "animalExotico" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Guarda
#ifndef animalExotico_H
#define animalExotico_H

//Bibliotecas novas
#include "../animalSilvestre.h"

class animalExotico : public animalSilvestre 
{
    public:
        //contador objetos
        static int total;
    protected:
        //propriedades
        std::string pais_origem, autorizacao;
    public:        
        //Construtores
        animalExotico( std::string _autorizacao_ibama, \
                       std::string _pais_origem,       \
                       std::string autorizacao         ) : animalSilvestre( std::string _autorizacao_ibama )
        {
            pais_origem = _pais_origem;
            autorizacao = _autorizacao;
            total++;
        }
        animalExotico() { total++; }
        //Destrutor
        ~animalExotico() {}
        //Inserção e obtenção
        static int getTotal() { return total; }
};

#endif    /* animalExotico_H */