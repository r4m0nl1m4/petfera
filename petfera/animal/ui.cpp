
//Main for "ui" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Cabeçalho
#include "./ui.h"

#define LIMPAR "clear"

string formate_decimal(float decimal){
    stringstream dec_stream;
    // configurando float na formatação desejada
    dec_stream << fixed << setprecision(2) << decimal;
    // convertendo para string
    string dec_str = dec_stream.str();
    
    return dec_str;
}
void clear() { // limpa a tela
    system(LIMPAR);
}
void wait(){ // espera por o usuario teclar ENTER
    cin.ignore();
    do{
        cout << "tecle ENTER para continar\n";
    }while (cin.get() != '\n');
}