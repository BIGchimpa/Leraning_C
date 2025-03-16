#include <iostream>
#include <string>

using namespace std;

int main(){
    int z_inteiro = 5;
    float q_decimal = 5.99; // usado para economizar memória
    double q_decimal_grande = 5.98; // usado quando precisão é muito necessário
    char l_letra = 'E';
    bool vf_booleano = true;
    string l_conjuntochar = "Eduardo";

    cout << "int: " << z_inteiro << endl;
    cout << "float: " << q_decimal << endl;
    cout << "double: " << q_decimal_grande << endl;
    cout << "char: " << l_letra << endl;
    cout << "bool: " << vf_booleano << endl;
    cout << "string: " << l_conjuntochar << endl;

    return 0;
}
