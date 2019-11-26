
//Main for "rexpression" C++ application
//Created by r4m0nl1m4 e ggorg03 26/11/2019

//Cabeçalho
#include "./rexpression.h"

bool ehDia(string str){
    regex exp("0[1-9]|[1-2][0-9]|3[0-1]");
    return regex_match(str,exp);
}

bool ehMes(string str){
    regex exp("0[1-9]|1[0-2]");
    return regex_match(str,exp);
}
bool ehAno(string str){
    regex exp("[1-2][0-9]{3}");
    return regex_match(str,exp);
}

bool ehNome(string str){
    regex exp("[a-z]+|[A-Z][a-z]*");
    return regex_match(str,exp);
}

bool ehNum(string str){
    regex exp("[0-9]+");
    return regex_match(str,exp);
}

bool ehRh(string str){
    regex exp("[/+]|[/-]");
    return regex_match(str,exp);

}


bool ehCpf(string str){
    regex exp("[0-9]{3}.[0-9]{3}.[0-9]{3}-[0-9]{2}");
    return regex_match(str,exp);
}

bool ehCrmv(string str){
    regex exp("[A-Z]{2}[0-9]{4}");
    return regex_match(str,exp);
}