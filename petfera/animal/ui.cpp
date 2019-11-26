
#include "./ui.h"

string formate_decimal(float decimal)
{
    stringstream dec_stream;
    // configurando float na formatação desejada
    dec_stream << fixed << setprecision(2) << decimal;
    // convertendo para string
    string dec_str = dec_stream.str();
    
    return dec_str;
}