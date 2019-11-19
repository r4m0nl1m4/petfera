
//Header for "estoque" C++ application
//Created by r4m0nl1m4 29/10/2019

//Guarda
#ifndef estoque_H
#define estoque_H

//Biblioteca
#include <list>

//Classe genérica
template <class T>
class estoque
{
    private:
        //Elementos armazenados no estoque
        std::list<T> container;
    public:
        //Construtor
        estoque (){};
        //Contém veículo?
        template <typename U>
        bool checkIn(U vehicle)
        {
            //Acesso ao estoque de veículos
            for(typename std::list<T>::iterator i = container.begin() ; i != container.end() ; i++)
            {
                //Lógica operacional para a aferição de igualdade
                if((*i) == vehicle)
                {
                    std::cout << "   ERROR! Veículo já adicionado" << std::endl;
                    (*i).total--;
                    //Sai da iteração
                    return true;
                }
            }
            return false;
        }
        //Esvaziar
        void clear()
        {
            container.clear();
        }
        //Deletar veículo
        template <typename U>        
        void del(U vehicle)
        {
            //Acesso ao estoque de veículos
            for(typename std::list<T>::iterator i = container.begin() ; i != container.end() ; i++)
            {
                //Lógica operacional para a aferição de igualdade
                if((*i) == vehicle)
                {
                    container.erase(i);
                }
            }
        }
        //Vazia?
        bool empty() const
        {
            return container.empty();
        }
        //Obter veículo
        template <typename U>        
        void find_vehicle(U chass)
        {
            //Acesso ao estoque de veículos
            for(typename std::list<T>::iterator i = container.begin() ; i != container.end() ; i++)
            {
                //Lógica operacional para a aferição de igualdade
                if((*i).getChass() == chass)
                {
                    std::cout << *i;
                }
            }
        }
        //Encarecer
        void increase_tax_rate(float n)
        {
            //Acesso ao estoque de veículos
            for(typename std::list<T>::iterator i = container.begin() ; i != container.end() ; i++)
            {
                (*i).setPreco( (*i).getPreco()*( 1+n/100 ) );
            }
        }
        //Retorna o último veículo adicionado
        T& newest()
        {
            return container.front();
        }
        //Apresentar dados dos veículos
        template <typename S>
        void print(S & stream)
        {
            //Acesso a lista
            for(typename std::list<T>::iterator i = container.begin() ; i != container.end() ; i++)
                (*i).print(stream);
        }
        //Imprimi a produção trimestral
        template <typename S>
        void print_producao_trimestral(S & stream)
        {
            //Variáveis para a amálise
            double idade = 0, trimestre = 3*30*24*60*60;
            time_t now, dataF;       
            //Acesso ao estoque de veículos
            for(typename std::list<T>::iterator i = container.begin() ; i != container.end() ; i++)
            {   
                //Data atual
                now = time(NULL);
                //Data de fabricação
                dataF = (*i).getDataF();
                //Idade da produção em segundos
                idade = difftime(now, dataF);
                //Condicional de idade
                if(idade <= trimestre)
                    (*i).print(stream);
            }
        }
        //Produção trimestral
        int producao_trimestral()
        {
            //Variáveis para a amálise
            double idade = 0, trimestre = 3*30*24*60*60;
            time_t now, dataF;
            int proT = 0;       
            //Acesso ao estoque de veículos
            for(typename std::list<T>::iterator i = container.begin() ; i != container.end() ; i++)
            {   
                //Data atual
                now = time(NULL);
                //Data de fabricação
                dataF = (*i).getDataF();
                //Idade da produção em segundos
                idade = difftime(now, dataF);
                //Condicional de idade
                if(idade <= trimestre)
                {
                    proT++;
                }    
            }
            return proT;
        }
        //Empilhar
        void push(const T& vehicle)
        {
            container.push_back(vehicle);
        }
        //Tamanho?
        int size()
        {
            return container.size();
        }
};

#endif /* estoque_H */