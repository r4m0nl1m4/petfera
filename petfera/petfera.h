
//Main for "petfera" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Guarda
#ifndef petfera_H
#define petfera_H

//Bibliotecas
#include <iostream>

//Bibliotecas novas
#include "./estoque/estoque.h"
#include "./animal/classes/anfibio/anfibioExotico.h"
#include "./animal/classes/anfibio/anfibioNativo.h"
#include "./animal/classes/ave/aveExotico.h"
#include "./animal/classes/ave/aveNativo.h"
#include "./animal/classes/mamifero/mamiferoExotico.h"
#include "./animal/classes/mamifero/mamiferoNativo.h"
#include "./animal/classes/reptil/reptilExotico.h"
#include "./animal/classes/reptil/reptilNativo.h"

class petfera
{
    public:
        //Contador objetos
        static int total;
        //Estrutura de dados de um proprietario
        struct p
        {
            std::string nome;
            std::string codigo;
        };
        //Estrutra de dados do juridico
        struct j
        {
            std::string nome;
            std::string cnpj;
        };
        //Estrutura de dados do estoque
        struct e
        {
            estoque<caminhao> caminhoes;
            estoque<moto> motos;
            int naut;
        };
    private:
        //Dados de um proprietario
        p prop;
        //Lista de proprietarios
        std::list<p> proprietarios;
        //Dados da concessionária
        j juridico;
        //Dados do estoque
        e stock;
    public:
        //Construtores
        petfera(std::list<p> _proprietarios, j _juridico, e _est);
        petfera();
        //Destrutor
        ~petfera();
        //Inserção e obtenção
        static int getTotal();
        void setProprietarios(std::list<p> setProprietarios);
        //list<p> getProprietarios();
        void setJuridico(j setJuridico);
        j    getJuridico();
        void setEstoque(e setEstoque);
        e    getEstoque();
        int  getEstoque_producao_trimestral();
        //Apresentação
        template <typename S>
        void print(S & stream);
        void show_producao_trimestral();
        //Arquivo
        void readDataOnFile();
        void writeDataInFile();
        //Operações com o estoque
        void find_vehicle(float chass);
        void increase_tax_rate(float n);
        //Sobrecarga de Operadores Relacionais
        bool operator ==(petfera a);
        bool operator !=(petfera a);
        //Sobrecarga do Operador de Atribuição
        petfera & operator =(const petfera & a);
        //Sobrecarga de Operadores IO
        friend std::istream & operator >>(std::istream & is, petfera & c);
        friend std::ostream & operator <<(std::ostream & os, petfera & c);
};

#endif    /* petfera_H */