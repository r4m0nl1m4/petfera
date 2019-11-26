
//Main for "petfera" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//CAbeçalho
#include "./petfera.h"

string arquivo_petfera = "petfera/dados/petfera.txt";

int int_garantido_entre(int a, int b){
    int entrada;
    cin >> entrada;
    while (entrada < a || entrada > b){
        cout << "As opcoes de entrada sao de " << a << " ate " << b << endl;
        cin >> entrada;
    }
    return entrada;
}

int id_disponivel_animal(vector<Animal*> animais){
    int n_id;
    cout << "Digite a id do animal: ";

    while(true){
        cin >> n_id;

        if(none_of(animais.begin(),animais.end(),[n_id](Animal* a){return a->get_id() == n_id; })){
            return n_id;
        }
        cout << "Já temos um animal com essa id, tente outra" << endl;
    }
}

int id_disponivel_funcionario(vector<Funcionario*> funcionarios){
    int n_id;
    cout << "Digite a id do funcionario: ";

    while(true){
        cin >> n_id;
        if(n_id == 0){
            cout << "O id de um funcionario não ser 0" << endl;
        }
        else if(none_of(funcionarios.begin(),funcionarios.end(),[n_id](Funcionario* f){return f->get_id() == n_id; })){
            return n_id;
        }
        else{
            cout << "Já temos um funcionario com essa id, tente outra" << endl;
        }
    }
}

void filtrar_animais(vector<Animal*> animais, bool &sair, bool voltar){
    clear();
    cout << "BUSCAR ANIMAL" << endl << endl;
    while (!sair && !voltar){
        // mostra os animais
        cout << endl;
        cout << "Animais" << endl;
        std::for_each(animais.begin(),animais.end(),[](Animal* a){cout << a; });
        cout << endl;

        // mostra as opcões de busca
        vector<string> reinos = {"Anfibio","Ave","Mamifero","Reptil"};
        vector<string> tipos_de_silvestres = {"Exotico","Nativo"};
        cout << "Filtrar por reino" << endl;
        int cont = 0;
        for(auto r = reinos.begin(); r != reinos.end();++r){
            cout << "[" << cont << "]" << " filtror por " << *r << endl;
            cont++; 
        }
        cout << endl;

        cout << "Filtrar por tipo de silvestre" << endl;
        
        for(auto s = tipos_de_silvestres.begin(); s != tipos_de_silvestres.end();++s){
            cout << "[" << cont << "]" << " filtror por " << *s << endl;
            cont++; 
        }
        cout << endl;

        cout << "Para sair da busca [6] | para remover o ultimo filtro [7]" << endl << endl;

        int escolha = int_garantido_entre(0,7);
        
        if(escolha <= 3){
            vector<Animal*> animais_filtrados;
    
            string reino_escolhido = reinos[escolha];
            copy_if(animais.begin(),animais.end(),std::back_inserter(animais_filtrados),
                    [reino_escolhido](Animal* a){return a->get_reino().compare(reino_escolhido) == 0; });

            filtrar_animais(animais_filtrados,sair,false);
        }
        else if(escolha <= 5){
            vector<Animal*> animais_filtrados;
    
            string tipo_silvestre_escolhido = tipos_de_silvestres[escolha - 4];
            copy_if(animais.begin(),animais.end(),std::back_inserter(animais_filtrados),
                    [tipo_silvestre_escolhido](Animal* a){return a->get_naturalidade().compare(tipo_silvestre_escolhido) == 0; });

            filtrar_animais(animais_filtrados,sair,false);

        }
        else if(escolha <= 7){
            if(escolha == 6){
                sair = true;
            }
            else if(escolha == 7){
                voltar = true;
            }
        }
                
    }
}


Petfera::Petfera(){
    vector<vector<string>> lido_do_arquivo = ler_do_arquivo(arquivo_petfera);
    this->animais = ler_animais(lido_do_arquivo);
    this->funcionarios = ler_funcionarios(lido_do_arquivo);
}  
    
Petfera::~Petfera(){
    escrever_no_arquivo(this->animais, this->funcionarios,arquivo_petfera);
}

vector<Animal*> Petfera::get_animais(){ return this->animais; }

vector<Funcionario*> Petfera::get_funcionarios() { return this->funcionarios; }

void Petfera::show_menu(){
    bool sair = false;
    while(!sair){
        clear();
        cout << "TELA INICIAL PETFERA " << endl << endl;
        this->print_funcionarios();
        cout << endl;
        this->print_animais();
        cout << endl;

        cout << "Operações de manipulação dos dados" << endl;
        cout << "[0] adicionar novo animal | [1] adicionar novo funcionario" << endl;
        cout << "[2] remover algum animal  | [3] remover algum funcionario" << endl << endl;

        cout << "Consultas" << endl;
        cout << "[4] Buscar por animais | [5] Buscar por funcionarios" << endl << endl;

        cout << "[6] Finalizar Petfera" << endl;

        int escolha = int_garantido_entre(0,6);

        switch (escolha)
        {
        case 0:
            this->adicionar_animal();
            break;
        case 1:
            this->adicionar_funcionario();
            break;
        case 2:
            this->remover_animal();
            break;
        case 3:
            this->remover_funcionario();
            break;
        case 4:
            this->buscar_animal();
            break;
        case 5:
            this->buscar_funcionario();
            break;
        case 6:
            sair = true;
            break;
        
        default:
            break;
        } 

    }
}

void Petfera::buscar_animal(){
    vector<Animal*> animais = this->get_animais();
    
    bool fim_da_busca = false;
    filtrar_animais(animais,fim_da_busca,false);
}

void Petfera::buscar_funcionario(){
    clear();
    cout << "BUSCAR FUNCIONARIO" << endl << endl;
    bool sair = false;
    while(!sair){
        this->print_funcionarios();
        cout << endl;

        cout << "Digite [0] para filtrar Tratadores | [1] para filtrar o veterinarios" << endl;
        cout << "Digite [2] para sair ";
        int escolha = int_garantido_entre(0,2);

        if (escolha == 0){
            clear();
            cout << "BUSCANDO POR TRATADORES" << endl << endl;
            bool voltar = false;
            vector<Funcionario*> tratadores = this->get_tratadores();

            while(!voltar){
                // mostrando tratadores
                std::for_each(tratadores.begin(),tratadores.end(),[](Funcionario *f){cout << f; });
                cout << endl;

                int id_alvo;
                cout << "digite [0] para voltar | digite a [id do tratatador] para analisar o tratador" << endl;
                cin >> id_alvo;

                if(id_alvo == 0){
                    voltar = true;
                }
                else{
                    auto tratador = std::find_if(tratadores.begin(),tratadores.end(),
                                [id_alvo](Funcionario* f){return f->get_id() == id_alvo; });
                    
                    if(tratador == tratadores.end()){
                        cout << "Não temos tratador com essa id" << endl;
                        wait();
                    }
                    else{
                        cout << *tratador;

                        vector<Animal*> animais_do_tratador;

                        copy_if(this->animais.begin(),this->animais.end(),std::back_inserter(animais_do_tratador),
                                    [id_alvo](Animal* a){return a->get_tratador() == id_alvo; });
                        
                        bool sair = false;
                        filtrar_animais(animais_do_tratador,sair,false);

                    }
                }
            }
        }
        else if (escolha == 1){
            clear();
            cout << "BUSCAR POR VETERINARIOS" << endl << endl;
            bool voltar = false;
            vector<Funcionario*> veterinarios = this->get_veterinarios();

            while(!voltar){
                std::for_each(veterinarios.begin(),veterinarios.end(),[](Funcionario *f){cout << f; });
                cout << endl;

                int id_alvo;
                cout << "digite [0] para voltar | digite a [id do veterinario] para analisar o veterinario" << endl;
                cin >> id_alvo;

                if(id_alvo == 0){
                    voltar = true;
                }
                else{
                    auto veterinario = std::find_if(veterinarios.begin(),veterinarios.end(),
                                [id_alvo](Funcionario* f){return f->get_id() == id_alvo; });
                    
                    if(veterinario == veterinarios.end()){
                        cout << "Não temos veterinario com essa id" << endl;
                        wait();
                    }
                    else{
                        cout << *veterinario;

                        vector<Animal*> animais_do_veterinario;

                        copy_if(this->animais.begin(),this->animais.end(),std::back_inserter(animais_do_veterinario),
                                    [id_alvo](Animal* a){return a->get_veterinario() == id_alvo; });
                        
                        bool sair = false;
                        filtrar_animais(animais_do_veterinario,sair,false);

                    }
                }
            }
        }
        else if(escolha == 2){
            sair = true;
        }

    }
}

void Petfera::print_animais(){
    cout << endl;
    cout << "ANIMAIS" << endl;
    std::for_each(this->animais.begin(), this->animais.end(),
                    [](Animal* a){ cout << a; });
}

void Petfera::print_funcionarios(){
    cout << endl;
    cout << "FUNCIONARIOS" << endl;
    std::for_each(this->funcionarios.begin(), this->funcionarios.end(),
                    [](Funcionario* f){ cout << f; });
}

void Petfera::adicionar_animal(){
    // coletando dados comuns aos animais
    clear();
    cout << "ADICIOANDO ANIMAL" << endl << endl;

    this->print_animais();
    cout << endl;

    int id = id_disponivel_animal(this->animais);

    string nome_cienctifico;
    cout << "Digite o nome cientifico: ";
    cin >> nome_cienctifico;

    char sexo;
    cout << "Sexo do animal: ";
    cin >> sexo;

    double tamanho_cm;
    cout << "Tamanho dele em centimetros: ";
    cin >> tamanho_cm;

    string dieta;
    cout << "Dieta do animal: ";
    cin.ignore();
    getline(cin,dieta);

    int veterinario = -1;
    vector<Funcionario*> veterinarios = this->get_veterinarios();
    bool encontrou_veterinario = false;
    while(!encontrou_veterinario && veterinario != 0){

        cout << "Veterinarios" << endl;
        
        std::for_each(veterinarios.begin(),veterinarios.end(),
                    [](Funcionario* f){
                        cout << f->get_id() << " " << f->get_nome() << " " << f->get_especificidade() << endl; });

        cout << "Digite a id do veterinario: ";
        cin >> veterinario;

        encontrou_veterinario =  std::any_of(veterinarios.begin(), veterinarios.end(),
                                [veterinario](Funcionario* f){return f->get_id() == veterinario; });
        

        if (!encontrou_veterinario)
            cout << "Nao temos veterinario com essa id" << endl;
    }

    string nome_batismo;
    cout << "Digite nome de batismo do animal: ";
    cin >> nome_batismo;

    int tipo_de_silvestre;
    cout << "[0] animal nativo | [1] animal exotico" << endl;
    tipo_de_silvestre = int_garantido_entre(0,1);
    
    // coletando dados comuns aos silvestres
    string autorizacao_ibama;
    cout << "Digite a autorizacao do ibama: ";
    cin.ignore();
    getline(cin,autorizacao_ibama);

    // coletadandos animais nativos
    if(tipo_de_silvestre == 0){
        
        string uf_de_origem, autorizacao;
        cout << "Digite a uf de origem: ";
        cin >> uf_de_origem;

        cout << "Digite a autorizacao: ";
        cin >> autorizacao;

        // coletando dados restantes e criando animal Nativo
        cout << "Qual o reino do animal que deseja adicionar?" << endl;
        cout << "[0]anfibio | [1]ave | [2]mamifero | [3]reptil " << endl;
        int reino_escolhido = int_garantido_entre(0,3);
        // criando anfibio nativo
        if(reino_escolhido == 0){

            int tratador = -1;
            bool encontrou_tratador = false;
            vector<Funcionario*> tratadores = this->get_tratadores();
            while(!encontrou_tratador && tratador != 0){
                cout << "Tratadores" << endl;
                std::for_each(tratadores.begin(),tratadores.end(),[](Funcionario* f)
                            {
                                if(stoi(f->get_especificidade()) != 2){
                                    cout << f->get_id() << " " << f->get_nome() << " " << f->get_especificidade() << endl; }
                            });

                cout << "Digite a Id do tratador: ";
                cin >> tratador;
                
                encontrou_tratador = any_of(tratadores.begin(),tratadores.end(),
                                        [tratador](Funcionario* f){return stoi(f->get_especificidade()) != 2 && f->get_id() == tratador;});
            }


            int total_de_mudas = 0;
            string data_ultima_muda = "--/--/----";
            
            do
            {
                cout << "Quantas mudas esse anfibio já teve?: ";
                cin >> total_de_mudas;    
            } while (total_de_mudas < 0);
            

            string dia,mes,ano;

            if(total_de_mudas > 0){
                cout << "Insira a data da ultima muda" << endl;
                do
                {
                    cout << "digite o dia da ultima muda: ";
                    cin >> dia;
                } while (!ehDia(dia));
                
                
                do
                {
                    cout << "digite o mes da ultima muda: ";
                    cin >> mes;
                } while (!ehMes(mes));
                
                do
                {
                    cout << "digite o ano da ultima muda: ";
                    cin >> ano;
                } while (!ehAno(ano));
            }

            data_ultima_muda = dia + "/" + mes + "/" + ano;
            
            this->animais.push_back(new Anfibio_Nativo(id,
                                                    nome_cienctifico,
                                                    sexo,
                                                    tamanho_cm,
                                                    dieta,
                                                    veterinario,
                                                    tratador,
                                                    nome_batismo,
                                                    total_de_mudas,
                                                    data_ultima_muda,
                                                    uf_de_origem,
                                                    autorizacao,
                                                    autorizacao_ibama));

        }
        if(reino_escolhido == 1){
            int tratador = -1;
            bool encontrou_tratador = false;
            vector<Funcionario*> tratadores = this->get_tratadores();
            while(!encontrou_tratador && tratador != 0){
                cout << "Tratadores" << endl;
                std::for_each(tratadores.begin(),tratadores.end(),[](Funcionario* f)
                            {
                                if(stoi(f->get_especificidade()) != 2){
                                    cout << f->get_id() << " " << f->get_nome() << " " << f->get_especificidade() << endl; }
                            });

                cout << "Digite a Id do tratador: ";
                cin >> tratador;
                
                encontrou_tratador = any_of(tratadores.begin(),tratadores.end(),
                                        [tratador](Funcionario* f){return stoi(f->get_especificidade()) != 2 && f->get_id() == tratador;});
            }


            float tamanho_bico_cm;
            cout << "Comprimento do bico em cm: ";
            cin >> tamanho_bico_cm;
            
            float envergadura_cm;
            cout << "Envergadura em cm: ";
            cin >> envergadura_cm;

            animais.push_back(new Ave_Nativo(id,
                                            nome_cienctifico,
                                            sexo,
                                            tamanho_cm,
                                            dieta,
                                            veterinario,
                                            tratador,
                                            nome_batismo,
                                            tamanho_bico_cm,
                                            envergadura_cm,
                                            uf_de_origem,
                                            autorizacao,
                                            autorizacao_ibama));


        }
        if(reino_escolhido == 2){

            int tratador = -1;
            bool encontrou_tratador = false;
            vector<Funcionario*> tratadores = this->get_tratadores();
            while(!encontrou_tratador && tratador != 0){
                cout << "Tratadores" << endl;
                std::for_each(tratadores.begin(),tratadores.end(),[](Funcionario* f)
                            {
                                if(stoi(f->get_especificidade()) == 1){
                                    cout << f->get_id() << " " << f->get_nome() << " " << f->get_especificidade() << endl; }
                            });

                cout << "Digite a Id do tratador: ";
                cin >> tratador;
                
                encontrou_tratador = any_of(tratadores.begin(),tratadores.end(),
                                        [tratador](Funcionario* f){return stoi(f->get_especificidade()) == 1 && f->get_id() == tratador;});
            }

            string cor_do_pelo;
            cout << "Cor do pelo: ";
            cin >> cor_do_pelo;

            animais.push_back(new Mamifero_Nativo(id,
                                                nome_cienctifico,
                                                sexo,
                                                tamanho_cm,
                                                dieta,
                                                veterinario,
                                                tratador,
                                                nome_batismo,
                                                cor_do_pelo,
                                                uf_de_origem,
                                                autorizacao,
                                                autorizacao_ibama));
        }
        if(reino_escolhido == 3){

            int tratador = -1;
            bool encontrou_tratador = false;
            vector<Funcionario*> tratadores = this->get_tratadores();
            while(!encontrou_tratador && tratador != 0){
                cout << "Tratadores" << endl;
                std::for_each(tratadores.begin(),tratadores.end(),[](Funcionario* f)
                            {
                                if(stoi(f->get_especificidade()) == 2){
                                    cout << f->get_id() << " " << f->get_nome() << " " << f->get_especificidade() << endl; }
                            });

                cout << "Digite a Id do tratador: ";
                cin >> tratador;
                
                encontrou_tratador = any_of(tratadores.begin(),tratadores.end(),
                                        [tratador](Funcionario* f){return stoi(f->get_especificidade()) == 2 && f->get_id() == tratador;});
            }

            bool venenoso = false;
            string tipo_veneno;
            cout << "O reptil eh venenoso? [S]sim | [n]nao" << endl;
            cin >> tipo_veneno;
            if(tipo_veneno.compare("S")){
                venenoso = true;
                cout << "Qual o tipo do veneno: ";
                cin >> tipo_veneno;
            }
            else{
                venenoso = false;
                tipo_veneno = "-";
            }
            animais.push_back(new Reptil_Nativo(id,
                                                nome_cienctifico,
                                                sexo,
                                                tamanho_cm,
                                                dieta,
                                                veterinario,
                                                tratador,
                                                nome_batismo,
                                                venenoso,
                                                tipo_veneno,
                                                uf_de_origem,
                                                autorizacao,
                                                autorizacao_ibama));               

        }
    }
    // animais exoticos
    if(tipo_de_silvestre == 1){
        string pais_de_origem;
        cout << "Digite pais de origem: ";
        cin >> pais_de_origem;

        cout << "Qual o reino do animal que deseja adicionar?" << endl;
        cout << "[0]anfibio | [1]ave | [2]mamifero | [3]reptil " << endl;
        int reino_escolhido = int_garantido_entre(0,3);
        // criando anfibio nativo
        if(reino_escolhido == 0){

            int tratador = -1;
            bool encontrou_tratador = false;
            vector<Funcionario*> tratadores = this->get_tratadores();
            while(!encontrou_tratador && tratador != 0){
                cout << "Tratadores" << endl;
                std::for_each(tratadores.begin(),tratadores.end(),[](Funcionario* f)
                            {
                                if(stoi(f->get_especificidade()) != 2){
                                    cout << f->get_id() << " " << f->get_nome() << " " << f->get_especificidade() << endl; }
                            });

                cout << "Digite a Id do tratador: ";
                cin >> tratador;
                
                encontrou_tratador = any_of(tratadores.begin(),tratadores.end(),
                                        [tratador](Funcionario* f){return stoi(f->get_especificidade()) != 2 && f->get_id() == tratador;});
            }


            int total_de_mudas = 0;
            string data_ultima_muda = "--/--/----";
            
            do
            {
                cout << "Quantas mudas esse anfibio já teve?: ";
                cin >> total_de_mudas;    
            } while (total_de_mudas < 0);
            

            string dia,mes,ano;

            if(total_de_mudas > 0){

                
                cout << "Insira a data da ultima muda" << endl;
                do
                {
                    cout << "digite o dia da ultima muda: ";
                    cin >> dia;
                } while (!ehDia(dia));
                
                
                do
                {
                    cout << "digite o mes da ultima muda: ";
                    cin >> mes;
                } while (!ehMes(mes));
                
                do
                {
                    cout << "digite o ano da ultima muda: ";
                    cin >> ano;
                } while (!ehAno(ano));
            }

            data_ultima_muda = dia + "/" + mes + "/" + ano;
            
            this->animais.push_back(new Anfibio_Exotico(id,
                                                    nome_cienctifico,
                                                    sexo,
                                                    tamanho_cm,
                                                    dieta,
                                                    veterinario,
                                                    tratador,
                                                    nome_batismo,
                                                    total_de_mudas,
                                                    data_ultima_muda,
                                                    pais_de_origem,
                                                    autorizacao_ibama));

        }
        if(reino_escolhido == 1){

            int tratador = -1;
            bool encontrou_tratador = false;
            vector<Funcionario*> tratadores = this->get_tratadores();
            while(!encontrou_tratador && tratador != 0){
                cout << "Tratadores" << endl;
                std::for_each(tratadores.begin(),tratadores.end(),[](Funcionario* f)
                            {
                                if(stoi(f->get_especificidade()) != 2){
                                    cout << f->get_id() << " " << f->get_nome() << " " << f->get_especificidade() << endl; }
                            });

                cout << "Digite a Id do tratador: ";
                cin >> tratador;
                
                encontrou_tratador = any_of(tratadores.begin(),tratadores.end(),
                                        [tratador](Funcionario* f){return stoi(f->get_especificidade()) != 2 && f->get_id() == tratador;});
            }

            float tamanho_bico_cm;
            cout << "Comprimento do bico em cm: ";
            cin >> tamanho_bico_cm;
            
            float envergadura_cm;
            cout << "Envergadura em cm: ";
            cin >> envergadura_cm;

            animais.push_back(new Ave_Exotico(id,
                                            nome_cienctifico,
                                            sexo,
                                            tamanho_cm,
                                            dieta,
                                            veterinario,
                                            tratador,
                                            nome_batismo,
                                            tamanho_bico_cm,
                                            envergadura_cm,
                                            pais_de_origem,
                                            autorizacao_ibama));


        }
        if(reino_escolhido == 2){

            int tratador = -1;
            bool encontrou_tratador = false;
            vector<Funcionario*> tratadores = this->get_tratadores();
            while(!encontrou_tratador && tratador != 0){
                cout << "Tratadores" << endl;
                std::for_each(tratadores.begin(),tratadores.end(),[](Funcionario* f)
                            {
                                if(stoi(f->get_especificidade()) == 1){
                                    cout << f->get_id() << " " << f->get_nome() << " " << f->get_especificidade() << endl; }
                            });

                cout << "Digite a Id do tratador: ";
                cin >> tratador;
                
                encontrou_tratador = any_of(tratadores.begin(),tratadores.end(),
                                        [tratador](Funcionario* f){return stoi(f->get_especificidade()) == 1 && f->get_id() == tratador;});
            }

            string cor_do_pelo;
            cout << "Cor do pelo: ";
            cin >> cor_do_pelo;

            animais.push_back(new Mamifero_Exotico(id,
                                                nome_cienctifico,
                                                sexo,
                                                tamanho_cm,
                                                dieta,
                                                veterinario,
                                                tratador,
                                                nome_batismo,
                                                cor_do_pelo,
                                                pais_de_origem,
                                                autorizacao_ibama));
        }
        if(reino_escolhido == 3){

            int tratador = -1;
            bool encontrou_tratador = false;
            vector<Funcionario*> tratadores = this->get_tratadores();
            while(!encontrou_tratador && tratador != 0){
                cout << "Tratadores" << endl;
                std::for_each(tratadores.begin(),tratadores.end(),[](Funcionario* f)
                            {
                                if(stoi(f->get_especificidade()) == 2){
                                    cout << f->get_id() << " " << f->get_nome() << " " << f->get_especificidade() << endl; }
                            });

                cout << "Digite a Id do tratador: ";
                cin >> tratador;
                
                encontrou_tratador = any_of(tratadores.begin(),tratadores.end(),
                                        [tratador](Funcionario* f){return stoi(f->get_especificidade()) == 2 && f->get_id() == tratador;});
            }

            bool venenoso = false;
            string tipo_veneno;
            cout << "O reptil eh venenoso? [S]sim | [n]nao" << endl;
            cin >> tipo_veneno;
            if(tipo_veneno.compare("S") == 0){
                venenoso = true;
                cout << "Qual o tipo do veneno: ";
                cin >> tipo_veneno;
            }
            else{
                venenoso = false;
                tipo_veneno = "-";
            }
            animais.push_back(new Reptil_Exotico(id,
                                                nome_cienctifico,
                                                sexo,
                                                tamanho_cm,
                                                dieta,
                                                veterinario,
                                                tratador,
                                                nome_batismo,
                                                venenoso,
                                                tipo_veneno,
                                                pais_de_origem,
                                                autorizacao_ibama));               

        }
        
    }
}

void Petfera::adicionar_funcionario(){
    clear();
    cout << "ADICIONANDO FUNCIONARIO" << endl << endl;

    this->print_funcionarios();

    int id = id_disponivel_funcionario(funcionarios);

    string nome;
    cout << "Digite nome do funcionario: ";
    cin >> nome;

    string cpf;
    cout << "Digite cpf do funcionario no formato esperado ddd.ddd.ddd-dd: ";
    do
    {
        cin >> cpf;

        if(!ehCpf(cpf))
            cout << "Isso não é um cpf valido" << endl;
        
    } while (!ehCpf(cpf));
    

    short idade;
    cout << "Digite a idade do funcionario: ";
    cin >> idade;


    string tipos_sanguineos = "ABO";
    cout << "Selecione o tipo sanguineo: [0] A | [1] B | [2] C " << endl;
    int sangue = int_garantido_entre(0,2);
    char tipo_sanguineo = tipos_sanguineos[sangue];

    string fatores_rh = "+-";
    cout << "Selecione o fato RH: [0] fator + | [1] fator -" << endl;
    int rh = int_garantido_entre(0,1);
    char fator_rh = fatores_rh[rh];
    

    string especialidade;
    cout << "Digite a especialidade do funcionario: ";
    cin >> especialidade;

    cout << "Digite o tipo funcionario [0]Veterinario | [1]Tratador" << endl;
    int tipo_funcionario = int_garantido_entre(0,1);
    
    if(tipo_funcionario == 0){
        string crmv;
        cout << "Digite o crmv do veterinario" << endl;
        cout << "formato de crmv: CRMV-LLdddd, onde L é uma letra maiuscula e d é um digito " << endl;
        cout << "Insira no seguinte formato: LLdddd" << endl;
        do{
            cin >> crmv;
            if(!ehCrmv(crmv)){
                cout << "formato invalido" << endl;
            }
        } while (!ehCrmv(crmv));

        crmv = "CRMV-" + crmv;
        

        funcionarios.push_back(new Veterinario(id,
                                            nome,
                                            cpf,
                                            idade,
                                            tipo_sanguineo,
                                            fator_rh,
                                            especialidade,
                                            crmv));
    }
    if(tipo_funcionario == 1){
        int nivel_de_seguranca;
        cout << "Digite o nivel de segurança do tratador (deve ser entre 0 e 2): ";
        nivel_de_seguranca = int_garantido_entre(0,2);

        funcionarios.push_back(new Tratador(id,
                                            nome,
                                            cpf,
                                            idade,
                                            tipo_sanguineo,
                                            fator_rh,
                                            especialidade,
                                            nivel_de_seguranca));
    }



}

void Petfera::remover_animal(){
    clear();
    cout << "REMOVENDO ANIMAL" << endl;

    this->print_animais();
    cout << endl;
    
    cout << "Digite o id do animal que quer remover: ";
    int id_do_alvo;
    cin >> id_do_alvo;

    this->animais.erase(
        std::find_if(this->animais.begin(),this->animais.end(),[id_do_alvo](Animal* a){return a->get_id() == id_do_alvo;})
        );

}

void Petfera::remover_funcionario(){
    clear();
    cout << "REMOVENDO FUNCIONARIO" << endl;
    this->print_funcionarios();
    cout << endl;

    cout << "Digite o id do funcionaria que quer remover: ";
    int id_do_alvo;
    cin >> id_do_alvo;

    this->funcionarios.erase(
        std::find_if(this->funcionarios.begin(),this->funcionarios.end(),[id_do_alvo](Funcionario* f){return f->get_id() == id_do_alvo;})
        );


}



vector<Funcionario*> Petfera::get_veterinarios(){
    vector<Funcionario*> veterinarios;        
        copy_if(this->funcionarios.begin(), this->funcionarios.end(), std::back_inserter(veterinarios),
                            [](Funcionario* f){return f->get_profissao().compare("veterinario") == 0;});

        return veterinarios;
}

vector<Funcionario*> Petfera::get_tratadores(){
    vector<Funcionario*> tratadores;        
        copy_if(this->funcionarios.begin(), this->funcionarios.end(), std::back_inserter(tratadores),
                            [](Funcionario* f){return f->get_profissao().compare("tratador") == 0;});

        return tratadores;
}