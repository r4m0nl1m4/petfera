
//Main for "main to petfera" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Biblioteca(s)
#include <iostream>
#include <vector>

//Biblioteca(s) nova(s)
//#include "./petfera/animal/classes/anfibio/anfibio_nativo.h"
//#include "./petfera/animal/classes/anfibio/anfibio_exotico.h"
//#include "./petfera/animal/classes/ave/ave_exotico.h"
//#include "./petfera/animal/classes/ave/ave_nativo.h"
//#include "./petfera/animal/classes/mamifero/mamifero_exotico.h"
//#include "./petfera/animal/classes/mamifero/mamifero_nativo.h"
//#include "./petfera/animal/classes/reptil/reptil_exotico.h"
//#include "./petfera/animal/classes/reptil/reptil_nativo.h"
//#include "./petfera/funcionario/veterinarios.h"
//#include "./petfera/funcionario/tratador.h"
#include "./petfera/dados/dados_manip.h"

using namespace std;

int main()
{

    // Teste basico classe animal
    vector<Animal*> animais;
    animais.push_back(new Mamifero_Exotico());
    animais.push_back(new Mamifero_Nativo());
    animais.push_back(new Anfibio_Exotico());
    animais.push_back(new Anfibio_Nativo());
    animais.push_back(new Reptil_Exotico());
    animais.push_back(new Reptil_Nativo());
    animais.push_back(new Ave_Exotico());
    animais.push_back(new Ave_Nativo());

/* 
    for (auto i = animais.begin(); i != animais.end(); i++){
        cout << *i;
    }
 */

    vector<Funcionario*> funcionarios;
    funcionarios.push_back(new Veterinario());
    funcionarios.push_back(new Veterinario());
    funcionarios.push_back(new Veterinario());
    funcionarios.push_back(new Tratador());
    funcionarios.push_back(new Tratador());
    funcionarios.push_back(new Tratador());

    funcionarios[0]->set_especificidade("hi");
    funcionarios[2] = funcionarios[0];
    funcionarios[0] = funcionarios[1];

    funcionarios[3]->set_especificidade("5");
    funcionarios[5] = funcionarios[3];
    funcionarios[3] = funcionarios[4];


/* 
    for (auto i = funcionarios.begin(); i != funcionarios.end(); i++){
        cout << *i;
    }
 */
    escrever_no_arquivo(animais,funcionarios,"bla.txt");

    vector<vector<string>> palavras = ler_do_arquivo("bla.txt");
    vector<Animal*> sapos = ler_animais(palavras);
    vector<Funcionario*> ellens = ler_funcionarios(palavras);

    /* for (auto i = palavras.begin(); i != palavras.end(); ++i){
        for(auto j = (*i).begin(); j != (*i).end(); ++j){
            cout << *j;
            cout << " ";
        }
        cout << "\n";
    } */


    for (auto i = sapos.begin(); i != sapos.end(); i++){
        cout << *i;
    }

}