
//Main for "veterinario" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Guarda
#ifndef veterinario_H
#define veterinario_H

//Bibliotecas novas
#include "../funcionario.h"

class veterinario : public funcionario 
{
    public:
        //contador objetos
        static int total;
    protected:
        //propriedades
        std::string cmv;
    public:        
        //Construtores
        veterinario( int _id,                   \
                     std::string _nome,         \
                     std::string _cpf,          \
                     short _idade,              \ 
                     short _tipo_sanguineo,     \
                     char _fator_rh,            \
                     std::string _especialidade,\
                     std::string _cmv           ) : funcionario( _id,            \
                                                                 _nome,          \
                                                                 _cpf,           \
                                                                 _idade,         \ 
                                                                 _tipo_sanguineo,\
                                                                 _fator_rh,      \
                                                                 _especialidade  )
        {
            cmv = _cmv;
            total++;
        }
        veterinario() { total++; }
        //Destrutor
        ~veterinario() {}
        //Inserção e obtenção
        static int getTotal() { return total; }
};

#endif    /* veterinario_H */