#include <iostream>
#include <string>
#include <locale>

using namespace std;

int main(){
    setlocale(LC_ALL, "pt_BR.UTF-8");

    float a, b, c;
    char retry;

do {

    cout << "ORDENADOR DE NÚMEROS!\n";
    cout << "---------------------\n";
    

    while (true) {
        double temp_a, temp_b, temp_c; 
        cout << "Digite os três números que deseja ordenar: \n";
        cin >> temp_a >> temp_b >> temp_c;
       
        if (cin.fail() || floor(temp_a) != temp_a || floor(temp_b != temp_b) || floor(temp_c != temp_c)) { 
            cin.clear(); 
            cin.ignore(1000, '\n'); 
            cout << "Números inválidos! Digite apenas números! Digite números inteiros!\n"; 
        } else {
            a = temp_a; b = temp_b; c = temp_c;
            break; 
        }
          }
    
    if (a < b && b < c) { 
        cout << "A ordem crescente dos números é: " << a << ", " << b << ", " << c << endl;
        cout << "A ordem decrescente dos números é: " << c << ", " << b << ", " << a << endl;    
    } else if (a < c && c < b) {
        cout << "A ordem crescente dos números é: " << a << ", " << c << ", " << b << endl;
        cout << "A ordem decrescente dos números é: " << b << ", " << c << ", " << a << endl;
    } else if (b < a && a < c) {
        cout << "A ordem crescente dos números é: " << b << ", " << a << ", " << c << endl;
        cout << "A ordem decrescente dos números é: " << c << ", " << a << ", " << b << endl;
    } else if (b < c  && c < a) {
        cout << "A ordem crescente dos números é: " << b << ", " << c << ", " << a << endl;
        cout << "A ordem decrescente dos números é: " << a << ", " << c << ", " << b << endl;
    } else if (c < a && a < b) {
        cout << "A ordem crescente dos números é: " << c << ", " << a << ", " << b << endl;
        cout << "A ordem decrescente dos números é: " << b << ", " << a << ", " << c << endl;
    } else if (c < b && b < a) {
        cout << "A ordem crescente dos números é: " << c << ", " << b << ", " << a << endl;
        cout << "A ordem decrescente dos números é: " << a << ", " << b << ", " << c << endl;
    } else if (a == b && b == c) {
        cout << "Os números são iguais!\n";      
    } else if (a == b && a > c) {
        cout << "A ordem crescente dos números é: " << c << ", " << a << ", " << b << endl;
        cout << "A ordem decrescente dos números é: " << b << ", " << a << ", " << c << endl;
    } else if (a == b && a < c) {
        cout << "A ordem crescente dos números é: " << a << ", " << b << ", " << c << endl;
        cout << "A ordem decrescente dos números é: " << c << ", " << b << ", " << a << endl;
    } else if (a == c && a > b) {
        cout << "A ordem crescente dos números é: " << b << ", " << a << ", " << c << endl;
        cout << "A ordem decrescente dos números é: " << c << ", " << a << ", " << b << endl;
    } else if (a == c && a < b) {
        cout << "A ordem crescente dos números é: " << a << ", " << c << ", " << b << endl;
        cout << "A ordem decrescente dos números é: " << b << ", " << c << ", " << a << endl;
    } else if (b == c && b > a) {
        cout << "A ordem crescente dos números é: " << a << ", " << b << ", " << c << endl;
        cout << "A ordem decrescente dos números é: " << c << ", " << b << ", " << a << endl;
    } else if (b == c && b < a) {
        cout << "A ordem crescente dos números é: " << b << ", " << c << ", " << a << endl;
        cout << "A ordem decrescente dos números é: " << a << ", " << c << ", " << b << endl;
    }

    cout << "Deseja verificar outra ordenação? ('s' para sim e 'n' para não)\n";
    cin >> retry;
   } while ( retry == 's' || retry == 'S');
 
    system ("pause");
    return 0;
}