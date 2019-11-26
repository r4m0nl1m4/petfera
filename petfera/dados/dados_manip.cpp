
//Main for "dados-manip" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Cabeçalho
#include "./dados_manip.h"

vector<Funcionario*> ler_funcionarios(vector<vector<string>> texto){
    vector<Funcionario*> funcionarios;

    for(auto i = texto.begin(); i != texto.end(); ++i){
        if((*i).size() > 2){
            if((*i)[1].compare("veterinario") == 0){
                int id = stoi((*i)[0]);
                string nome = (*i)[2];
                string cpf = (*i)[3];
                short idade = stoi((*i)[4]);
                char tipo_sanguineo = (*i)[5][0];
                char fator_rh = (*i)[6][0];
                string especialidade = (*i)[7];
                string crmv = (*i)[8];

                if(none_of(funcionarios.begin(),funcionarios.end(),[id](Funcionario* f){ return f->get_id() == id; })){
                    funcionarios.push_back(new Veterinario(id,
                                                        nome,
                                                        cpf,
                                                        idade,
                                                        tipo_sanguineo,
                                                        fator_rh,
                                                        especialidade,
                                                        crmv));
                }
            }
            
            if((*i)[1].compare("tratador") == 0){
                int id = stoi((*i)[0]);
                string nome = (*i)[2];
                string cpf = (*i)[3];
                short idade = stoi((*i)[4]);
                char tipo_sanguineo = (*i)[5][0];
                char fator_rh = (*i)[6][0];
                string especialidade = (*i)[7];
                int nivel_de_seguranca = stoi((*i)[8]);

                if(none_of(funcionarios.begin(),funcionarios.end(),[id](Funcionario* f){ return f->get_id() == id; })){
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
        }
    }
    return funcionarios;
}

vector<Animal*> ler_animais(vector<vector<string>> texto){
    vector<Animal*> animais;
    
    for(auto i = texto.begin(); i != texto.end(); ++i){
        if((*i).size() > 2){
            int maybe_id = stoi((*i)[0]);
            if(none_of(animais.begin(),animais.end(),[maybe_id](Animal* a){ return a->get_id() == maybe_id; })){
                if((*i)[1].compare("Anfibio") == 0){
                    if((*i)[11].compare("Exotico") == 0){
                        int id = stoi((*i)[0]);
                        string nome_cienctifico = (*i)[4];
                        char sexo = (*i)[5][0];
                        double tamanho_cm = stof((*i)[6]);
                        string dieta = (*i)[7];
                        int veterinario = stoi((*i)[8]);
                        int tratador = stoi((*i)[9]);
                        string nome_batismo = (*i)[10];
                        int total_de_mudas = stoi((*i)[2]);
                        string ultima_muda = (*i)[3];
                        string pais_de_origem = (*i)[12];
                        string autorizacao_ibama = (*i)[13];

                        animais.push_back(new Anfibio_Exotico(id,
                                                            nome_cienctifico,
                                                            sexo,
                                                            tamanho_cm,
                                                            dieta,
                                                            veterinario,
                                                            tratador,
                                                            nome_batismo,
                                                            total_de_mudas,
                                                            ultima_muda,
                                                            pais_de_origem,
                                                            autorizacao_ibama));
                    }
                    if((*i)[11].compare("Nativo") == 0){
                        int id = stoi((*i)[0]);
                        string nome_cienctifico = (*i)[4];
                        char sexo = (*i)[5][0];
                        double tamanho_cm = stof((*i)[6]);
                        string dieta = (*i)[7];
                        int veterinario = stoi((*i)[8]);
                        int tratador = stoi((*i)[9]);
                        string nome_batismo = (*i)[10];
                        int total_de_mudas = stoi((*i)[2]);
                        string ultima_muda = (*i)[3];
                        string uf_de_origem = (*i)[12];
                        string autorizacao = (*i)[13];
                        string autorizacao_ibama = (*i)[14];

                        animais.push_back(new Anfibio_Nativo(id,
                                                            nome_cienctifico,
                                                            sexo,
                                                            tamanho_cm,
                                                            dieta,
                                                            veterinario,
                                                            tratador,
                                                            nome_batismo,
                                                            total_de_mudas,
                                                            ultima_muda,
                                                            uf_de_origem,
                                                            autorizacao,
                                                            autorizacao_ibama));
                    }
                }
                if((*i)[1].compare("Ave") == 0){
                    if((*i)[11].compare("Exotico") == 0){
                        int id = stoi((*i)[0]);
                        string nome_cienctifico = (*i)[4];
                        char sexo = (*i)[5][0];
                        double tamanho_cm = stof((*i)[6]);
                        string dieta = (*i)[7];
                        int veterinario = stoi((*i)[8]);
                        int tratador = stoi((*i)[9]);
                        string nome_batismo = (*i)[10];
                        double tamanho_do_bico_cm = stof((*i)[2]);
                        double envergadura_cm = stof((*i)[3]);
                        string pais_de_origem = (*i)[12];
                        string autorizacao_ibama = (*i)[13];
                        
                        
                        animais.push_back(new Ave_Exotico(id,
                                                    nome_cienctifico,
                                                    sexo,
                                                    tamanho_cm,
                                                    dieta,
                                                    veterinario,
                                                    tratador,
                                                    nome_batismo,
                                                    tamanho_do_bico_cm,
                                                    envergadura_cm,
                                                    pais_de_origem,
                                                    autorizacao_ibama));
                    }
                    if((*i)[11].compare("Nativo") == 0){
                        int id = stoi((*i)[0]);
                        string nome_cienctifico = (*i)[4];
                        char sexo = (*i)[5][0];
                        double tamanho_cm = stof((*i)[6]);
                        string dieta = (*i)[7];
                        int veterinario = stoi((*i)[8]);
                        int tratador = stoi((*i)[9]);
                        string nome_batismo = (*i)[10];
                        double tamanho_do_bico_cm = stof((*i)[2]);
                        double envergadura_cm = stof((*i)[3]);
                        string uf_de_origem = (*i)[12];
                        string autorizacao = (*i)[13];
                        string autorizacao_ibama = (*i)[14];
                        
                        
                        animais.push_back(new Ave_Nativo(id,
                                                        nome_cienctifico,
                                                        sexo,
                                                        tamanho_cm,
                                                        dieta,
                                                        veterinario,
                                                        tratador,
                                                        nome_batismo,
                                                        tamanho_do_bico_cm,
                                                        envergadura_cm,
                                                        uf_de_origem,
                                                        autorizacao,
                                                        autorizacao_ibama));
                    }

                }
                if((*i)[1].compare("Mamifero") == 0){
                    if((*i)[10].compare("Exotico") == 0){
                        int id = stoi((*i)[0]);
                        string nome_cienctifico = (*i)[3];
                        char sexo = (*i)[4][0];
                        double tamanho_cm = stof((*i)[5]);
                        string dieta = (*i)[6];
                        int veterinario = stoi((*i)[7]);
                        int tratador = stoi((*i)[8]);
                        string nome_batismo = (*i)[9];
                        string cor_do_pelo = (*i)[2];
                        string pais_de_origem = (*i)[11];
                        string autorizacao_ibama = (*i)[12];

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
                    if((*i)[10].compare("Nativo") == 0){
                        int id = stoi((*i)[0]);
                        string nome_cienctifico = (*i)[3];
                        char sexo = (*i)[4][0];
                        double tamanho_cm = stof((*i)[5]);
                        string dieta = (*i)[6];
                        int veterinario = stoi((*i)[7]);
                        int tratador = stoi((*i)[8]);
                        string nome_batismo = (*i)[9];
                        string cor_do_pelo = (*i)[2];
                        string uf_de_origem = (*i)[11];
                        string autorizacao = (*i)[12];
                        string autorizacao_ibama = (*i)[13];

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
                }
                if((*i)[1].compare("Reptil") == 0){
                    if((*i)[11].compare("Exotico") == 0){
                        int id = stoi((*i)[0]);
                        string nome_cienctifico = (*i)[4];
                        char sexo = (*i)[5][0];
                        double tamanho_cm = stof((*i)[6]);
                        string dieta = (*i)[7];
                        int veterinario = stoi((*i)[8]);
                        int tratador = stoi((*i)[9]);
                        string nome_batismo = (*i)[10];
                        bool venenoso = stoi((*i)[2]);
                        string tipo_veneno = (*i)[3];
                        string pais_de_origem = (*i)[12];
                        string autorizacao_ibama = (*i)[13];
                        
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
                    if((*i)[11].compare("Nativo") == 0){
                        int id = stoi((*i)[0]);
                        string nome_cienctifico = (*i)[4];
                        char sexo = (*i)[5][0];
                        double tamanho_cm = stof((*i)[6]);
                        string dieta = (*i)[7];
                        int veterinario = stoi((*i)[8]);
                        int tratador = stoi((*i)[9]);
                        string nome_batismo = (*i)[10];
                        bool venenoso = stoi((*i)[2]);
                        string tipo_veneno = (*i)[3];
                        string uf_de_origem = (*i)[12];
                        string autorizacao = (*i)[13];
                        string autorizacao_ibama = (*i)[14];
                        
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
            }
        }
    }
        return animais;
}

vector<vector<string>> ler_do_arquivo(string nome_arquivo){
    
    vector<vector<string>> dados_lidos;

    ifstream arquivo(nome_arquivo); // abri o nosso arquivo
    while (!arquivo.eof()){ // loop que se encerra ao final da leitura do arquivo
        string line;
        getline(arquivo,line); // ler uma linha do arquivo

        // criamos uma stringstream para que possamois manipular a string como uma stream
        stringstream streamline;
        streamline << line;

        vector<string> elementos; // esse vetor é para alocarmos cada "palavra" que encontramos na stream
        while (!streamline.eof()){ // loop que se encerra ao final da leitura da stream
            string elem;
            getline(streamline,elem,';'); // pega as "palavras" separadas por ";"
            elementos.push_back(elem); // alocando todas as palavras que encontramos na stream
        }
        
        dados_lidos.push_back(elementos); // adiciona os dados da linha no nosso vetor de dados
    }
    while(arquivo.is_open()){ // garantindo que o arquivo sera fechado
        arquivo.close();
    }

    return dados_lidos;
}

void escrever_no_arquivo(vector<Animal*> animais, vector<Funcionario*> funcionarios, string nome_do_arquivo){
    ofstream arquivo(nome_do_arquivo); // abrindo arquivo para escrita

    // escrevendo os animais no arquivo
    for(auto i = animais.begin(); i != animais.end(); ++i){
        arquivo << *i;
    }
    // escrevendo os funcionarioas no arquivo
    for(auto i = funcionarios.begin(); i != funcionarios.end(); ++i){
        arquivo << *i;
    }

}