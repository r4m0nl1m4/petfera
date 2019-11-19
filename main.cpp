
//Main for "main to petfera" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Biblioteca(s)
#include <iostream>

//Biblioteca(s) nova(s)
#include "./dealerships/concessionarias.h"

//Inicialização do(s) atributo(s) estático(s) da(s) classe(s)
int moto::total = 0,            \
    caminhao::total = 0,        \
    animalSilvestre::total = 0, \
    animal::total = 0,          \
    petfera::total = 0;

//Program
int main()
{
	//Declaração das concessionárias
	concessionaria c1, c2;

	//Instanciação de uma concessionária
	std::cout << std::endl << "...Instanciação de uma concessionária..." << std::endl << std::endl;
	std::cin >> c1;

	//Apresentação dos dados das concessionárias
	std::cout << std::endl << "...Apresentação dos dados da(s) concessionária(s)..." << std::endl;
	std::cout << c1;

	//Produção trimestral da(s) concessionária(s)
	std::cout << std::endl << "...Produção trimestral da(s) concessionária(s)..." << std::endl << std::endl;
	c1.show_producao_trimestral();

	//Ajuste nos preços dos veículos de uma concessionária
	std::cout << std::endl << "...Aplicando o incremento de 50% na alíquota do preço dos veículos de uma concessionária..." << std::endl;
	c1.increase_tax_rate(50);
	c1.print(std::cout);

	//Salva os dados em um arquivo
	c1.writeDataInFile();

    //Apresentação das operações da(s) concessionária(s) 
    std::cout << std::endl << "...Apresentação do balanço das operações da(s) concessionária(s)..." << std::endl << std::endl;    
    std::cout << "    Balanço              "                                                                 << std::endl;
    std::cout << "     Concessionária(s)   " << concessionaria::getTotal()                                   << std::endl; //Total de concessionárias
    std::cout << "     Média da Produção   " << float(veiculo::getTotal())/float(concessionaria::getTotal()) << std::endl; //Média de veículos por concessionárias
    std::cout << "     Produção Trimestral " << c1.getEstoque_producao_trimestral()                          << std::endl; //Produção trimestral total da(s) concessionária(s)
    std::cout << "     Veículo(s)          " << veiculo::getTotal()                                          << std::endl; //Total de veículos
    std::cout << "     ├Automóvel(is)      " << automovel::getTotal()                                        << std::endl; //  /   /  automóveis
    std::cout << "     ├─Caminhão(ões)     " << caminhao::getTotal()                                         << std::endl; //  /   /  caminhões
    std::cout << "     ├─Moto(s)           " << moto::getTotal()                                             << std::endl; //  /   /  motos


    //Busca veículo no estoque pelo seu chassis
    std::cout << std::endl << "...Busca veículo no estoque pelo seu chassis..." << std::endl << std::endl;    
    float chass;
	std::cout << "    Digite o chass: ";
	std::cin  >> chass;
	c1.find_vehicle(chass);

    //Lê dados do arquivos
    std::cout << std::endl << "...Nova instância criada a partir do arquivo gerado anteriormente..." << std::endl;    
	c2.readDataOnFile();
	std::cout << c2 << std::endl;

	return 0;
}