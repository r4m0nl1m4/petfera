
//Main for "dados-manip" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Guarda
#ifndef DADOS_MANIP_H
#define DADOS_MANIP_H

//Bibliotecas
#include <vector>
using std::vector;
#include <string>
using std::string;
using std::stoi;
using std::stof;
#include <fstream>
using std::ofstream;
using std::ifstream;
#include <sstream>
using std::stringstream;
#include <algorithm>
using std::none_of;

//Bibliotecas novas
#include "../funcionario/veterinario/veterinario.h"
#include "../funcionario/tratador/tratador.h"
#include "../animal/classes/anfibio/anfibio_exotico.h"
#include "../animal/classes/anfibio/anfibio_nativo.h"
#include "../animal/classes/ave/ave_exotico.h"
#include "../animal/classes/ave/ave_nativo.h"
#include "../animal/classes/mamifero/mamifero_exotico.h"
#include "../animal/classes/mamifero/mamifero_nativo.h"
#include "../animal/classes/reptil/reptil_exotico.h"
#include "../animal/classes/reptil/reptil_nativo.h"

vector<Funcionario*> ler_funcionarios(vector<vector<string>> texto);
vector<Animal*> ler_animais(vector<vector<string>> texto);
vector<vector<string>> ler_do_arquivo(string nome_do_arquivo);
void escrever_no_arquivo(vector<Animal*> animais, vector<Funcionario*> funcionarios, string nome_do_arquivo);

#endif