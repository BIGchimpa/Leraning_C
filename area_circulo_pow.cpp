#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main(){
    int raio;
    double pi, area;
    pi = 3.14159;

    cout << "CALCULADORA DE AREA DE CIRCULO!\n";
    cout << "Digite o tamanho do raio do circulo: \n";
    cin >> raio;
    
    area = pow(raio, 2) * pi;

    cout << "A area do circulo eh: " << area << endl;

    system("pause");
    return 0;
}