
//Main for "animalNativo" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Guarda
#ifndef animalNativo_H
#define animalNativo_H

//Bibliotecas novas
#include "../animalSilvestre.h"

class animalNativo : public animalSilvestre 
{
    public:
        //contador objetos
        static int total;
    protected:
        //propriedades
        std::string uf_origem, autorizacao;
    public:        
        //Construtores
        animalNativo( std::string _autorizacao_ibama, \
                      std::string _uf_origem,         \
                      std::string autorizacao         ) : animalSilvestre( std::string _autorizacao_ibama )
        {
            uf_origem = _uf_origem;
            autorizacao = _autorizacao;
            total++;
        }
        animalExotico() { total++; }
        //Destrutor
        ~animalExotico() {}
        //Inserção e obtenção
        static int getTotal() { return total; }
};

#endif    /* animalNativo_H */