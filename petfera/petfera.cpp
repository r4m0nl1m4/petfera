
//Main for "petfera" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Cabeçalho
#include "./petfera.h"

//Construtores

petfera::petfera(std::list<p> _proprietarios, j _juridico, e _est)
{
    proprietarios = _proprietarios;
    juridico = _juridico;
    stock = _est;
    total++;
}

petfera::petfera()
{
    stock.naut = 0;
    total++;
}

//Destrutor

petfera::~petfera() {}

//Inserção e obtenção

int petfera::getTotal()
{
    return total;
}

void petfera::setProprietarios(std::list<p> setProprietarios)
{
    proprietarios.assign(setProprietarios.begin(), setProprietarios.end());
}

//petfera::list<p> petfera::getProprietarios()
//{
//    return proprietarios;
//}

void petfera::setJuridico(j setJuridico)
{
    juridico = setJuridico;
}

petfera::j petfera::getJuridico()
{
    return juridico;
}

void petfera::setEstoque(e setEstoque)
{
    stock = setEstoque;
}

petfera::e petfera::getEstoque()
{
    return stock;
}

int petfera::getEstoque_producao_trimestral()
{
    return (
             stock.caminhoes.producao_trimestral() + \
             stock.motos.producao_trimestral()       
           );
}

//Apresentação

template <typename S>
void petfera::print(S & stream)
{
    stream                                                                     << std::endl;
    stream     << "    Dados da concessionária"                                << std::endl;
    //Proprietário(s)
    stream     << "     Proprietários:"               << proprietarios.size()  << std::endl;
    int n = 1;
    for(std::list<p>::iterator i = proprietarios.begin() ; i != proprietarios.end() ; i++)
    {   
        stream << "      " << n << "  Nome/razão social:"     << (*i).nome     << std::endl;
        stream << "         CPF/CNPJ:"                        << (*i).codigo   << std::endl;
        n++;
    }
    //Jurídico
    stream << "     Jurídico               "                  << std::endl;
    stream << "      Razão social:"          << juridico.nome << std::endl;
    stream << "      CNPJ:"                  << juridico.cnpj << std::endl;
    //Estoque
    if(stock.naut != 0)
    {
        stream << "     Estoque                "                  << std::endl;
        stream << "      Total:"                                  << stock.naut                       << std::endl;
        stream << "      Caminhões:"                              << stock.caminhoes.size()           << std::endl;
        stream << "      Motos:"                                  << stock.motos.size()               << std::endl;
        stream << "      Produção Trimestral:"                    << getEstoque_producao_trimestral() << std::endl;
        stream << "      Detalhamento dos veículos cadastrados:"                                      << std::endl;

        stock.caminhoes.print(stream);
        stock.motos.print(stream);
    }
}

void petfera::show_producao_trimestral()
{
    int proT = stock.caminhoes.producao_trimestral() + stock.motos.producao_trimestral();
    //Balanço da produção
    std::cout << "    A concessionária " << juridico.nome << " produziu " << proT << " veículo(s) no último trimestre." << std::endl;
    //Apresentação dos dados
    if(proT != 0) 
    {
        //Produção trimestral de caminhões
        stock.caminhoes.print_producao_trimestral(std::cout);
        //Produção trimestral de motos
        stock.motos.print_producao_trimestral(std::cout);
    }
}

//Arquivo

void petfera::readDataOnFile()
{   
    std::string strFile = "dados.txt";                                //Nome do arquivo
    const char *cstr = strFile.c_str();                          //std::string to C std::string version
    std::ifstream file;                                               //Instancia para a leitura 
    file.open(cstr);                                                  //Abre o arquivo
    bool status;                                                      //Status do arquivo                       
    status = !( ( file.fail() || !file.is_open() ) || !file.good() );  
    if(!status)                                                       //Deu ruim!
    {
        std::cout << "O arquivo não pode ser aberto para leitura.\n";
        std::cout << "Programa terminando...\n";
        exit(EXIT_FAILURE);
    }
    else
    {
        //Proprietarios
        int qtd_p = 0;
        //Escopos
        int scope = 1;
        std::string i = "0", m;
        //Lê os escopos do arquivo
        while(getline(file, i))                            //final do arquivo?
        {
            //scope 1
            //if (scope == 01)
            // std::cout << "scope" << scope << std::endl;
            //scope 2 Dados dos proprietarios
            if(scope == 02)
            {
                file.ignore(256, ':');                     //ignore until ': '
                getline(file, i);                          //get    until '\n'
                qtd_p = atoi(i.c_str());                   //Quantidade de proprietarios
                //std::cout << "scope" << scope << std::endl
                //std::cout << "->" << i << std::endl;
                //Atualiza lista de proprietarios
                for(int p = 1 ; p <= qtd_p ; p++)
                {
                    file.ignore(256, ':');                 //ignore until ':'
                    getline(file, prop.nome);
                    //std::cout << "->" << prop.nome << std::endl;
                    file.ignore(256, ':');                 //ignore until ':'
                    getline(file, prop.codigo);
                    //std::cout << "->" << prop.codigo << std::endl; 
                    proprietarios.push_back(prop);         //Adiciona a lista de proprietários*/
                }
            }
            //scope 3 Dados do juridico
            else if(scope == 03)
            {
                //std::cout << "scope" << scope << std::endl;
                //Atualiza dados juridicos
                file.ignore(256, ':');                     //ignore until ':'
                getline(file, juridico.nome);
                //std::cout << "->" << juridico.nome << std::endl;
                file.ignore(256, ':');                     //ignore until ':'
                getline(file, juridico.cnpj);
                //std::cout << "->" << juridico.cnpj << std::endl;
            }
            // Outros scopes Dados do estoque
            else if(scope > 1)
            {
                if(i == "       Caminhão")                 //achou caminhão!!!
                {                  
                    stock.naut = stock.naut + 1;
                    caminhao truck;
                    truck.readDataOnFile(file);
                    stock.caminhoes.push(truck);
                }
                if(i == "       Moto")                     //achou moto!!!
                {
                    stock.naut = stock.naut + 1;
                    moto motocycle;
                    motocycle.readDataOnFile(file);
                    stock.motos.push(motocycle);
                }
            }
            scope++;
        }

        file.close();                                      //Fecha o arquivo
    }
}

void petfera::writeDataInFile()
{
    //Nome do arquivo
    std::string nameFile = "dados.txt";
    //std::string to C std::string version                                            
    const char *cstr = nameFile.c_str();
    //Instancia ofstream para a escrita                                      
    std::ofstream file;
    //Cria/Abre o arquivo                                                            
    file.open(cstr);
    //Status do arquivo                                                             
    bool status;                                                       
    status = !( file.fail() || !file.is_open() || !file.good() );
    //Deu ruim!             
    if(!status)                                                               
    {
        std::cout << "Arquivo não pode ser aberto para escrita.\n"; 
        std::cout << "Programa terminando...\n";
        exit(EXIT_FAILURE);
    }
    //De boas...
    else                                                                     
    {
        print(file);
    }
    //Fecha o arquivo
    file.close();                                                      
}

//Operações com estoque

void petfera::find_vehicle(float chass)
{
    stock.caminhoes.find_vehicle(chass);
    stock.motos.find_vehicle(chass);
}

void petfera::increase_tax_rate(float n)
{
    stock.caminhoes.increase_tax_rate(n);
    stock.motos.increase_tax_rate(n);
}

//Sobrecarga de Operadores Relacionais

bool petfera::operator ==(petfera c)
{
    return ( juridico.nome == c.juridico.nome || juridico.cnpj == c.juridico.cnpj );
}

bool petfera::operator !=(petfera c)
{
    return ( juridico.nome != c.juridico.nome || juridico.cnpj != c.juridico.cnpj );
}

//Sobrecarga do Operador de Atribuição

petfera & petfera::operator =(const petfera & c)
{
    if (this != & c)
    {
        proprietarios = c.proprietarios;
        juridico = c.juridico;
        stock = c.stock;
    }
    return *this;
}

//Sobrecarga de Operadores IO

std::istream & operator >>(std::istream & is, petfera & c)
{
    int qntd = 0;
    //Get proprietarios from user
    std::cout << "    Insira os dados da concessionária:" << std::endl;
    std::cout << "     Digite a quantidade de proprietarios: ";
    std::cin >> qntd;
    std::cin.ignore();                                                   //ignore '\n' from enter on buffer
    for(int i = 1 ; i <= qntd ; i++)
    {    
        std::cout << "      Proprietário [" << i << "]:" << std::endl;
        std::cout << "       Digite o nome/razão social: ";         
        getline(std::cin, c.prop.nome);
        std::cout << "       Digite o CNPJ/CPF: ";
        c.prop.codigo = '\0';
        getline(std::cin, c.prop.codigo);           
        c.proprietarios.push_back(c.prop);                          //Adiciona a lista de proprietários
    }
    //Get juridico from user
    std::cout << "     Jurídico: " << std::endl;
    std::cout << "      Digite a razão social: ";
    std::cin.ignore(c.juridico.nome.size(),'\n'); 
    getline(std::cin, c.juridico.nome);
    std::cout << "      Digite o CNPJ: ";    
    std::cin.ignore(c.juridico.cnpj.size(),'\n');
    getline(std::cin, c.juridico.cnpj);
    //Get estoque from user
    std::string comando;    
    std::cout << "     Cadastrar veículo [Y/N]? ";
    std::cin >> comando;    
    if (comando == "Y" || comando == "y" )
    {
        qntd = 0;
        std::cout << "      Digite a quantidade: ";
        std::cin >> qntd;

        if(qntd > 0)
        {
            std::cout << "       Menu para cadastro de veículos: "  << std::endl;
            std::cout << "       ├Automóveis:                    "  << std::endl;
            std::cout << "       ├─[1] Caminhão                  "  << std::endl;
            std::cout << "       ├─[2] Moto                      "  << std::endl;
            std::cout << "       ├─[0] Sair                      "  << std::endl;

            for(int i = 1 ; i <= qntd ; i++)
            {   //Adiciona um veículo ao estoque
                int codigo;
                std::cout << "       Digite o código do veículo [" << i << "]: ";
                std::cin >> codigo;
                switch(codigo)
                {
                    case 1:
                    {//As chaves criam um bloco e um escopo, para poder criar as variáveis.
                        caminhao novoCaminhao;
                        std::cin >> novoCaminhao;
                        if(!c.stock.caminhoes.checkIn(novoCaminhao))
                        {
                            c.stock.caminhoes.push(novoCaminhao);
                            c.stock.naut++;
                        }           
                        break;
                    }
                    case 2:
                    {
                        moto novaMoto;
                        std::cin >> novaMoto;
                        if(!c.stock.motos.checkIn(novaMoto))
                        {
                            c.stock.motos.push(novaMoto);
                            c.stock.naut++;
                        }
                        break;
                    }
                    case 0:
                        exit(EXIT_FAILURE);
                    default:
                        std::cout << "  Código inválido!" << std::endl;
                        exit(EXIT_FAILURE);
                        break;
                }
            }
        }
        else
        {
            std::cout << "  Código inválido!" << std::endl;
            exit(EXIT_FAILURE);
        }
    }
    else if (comando != "N" && comando != "n" )
    {
        std::cout << "  Código inválido!" << std::endl;
        exit(EXIT_FAILURE);
    }

    return is;
}

std::ostream & operator <<(std::ostream & os, petfera & c)
{
    c.print(std::cout);   
    return os;
}