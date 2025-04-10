#include <iostream>
#include <string>
#include <locale>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
    setlocale(LC_ALL, "Portuguese");
    int n, a, b, result;
    a = 0;
    b = 1;
    char retry;
     do {
      cout << "CALCULADORA DE FIBONACCI" << endl;
      cout << "Digite um número inteiro positivo maior ou igual a 1: ";
      cin >> n;
      if (n <= 0 || n != floor(n)) {
            cout << "Número inválido. Digite um número inteiro positivo maior ou igual a 1." << endl;
            return 1;
        } 
      while (result <= n) {
        result = a + b;
        b = a;
        a = result;
        if (result <= n) {
            cout << result << endl;
        }
       
      }
        cout << "Deseja calcular outro número de Fibonacci? (s/n): ";
        cin >> retry;
     } while (retry == 's' || retry == 'S');
     

    cout << "Obrigado por usar a calculadora FIBONACCI!" << endl;
    cout << "Pressione qualquer tecla para continuar..." << endl;
    cin.ignore();
    cin.get();
    return 0;
}