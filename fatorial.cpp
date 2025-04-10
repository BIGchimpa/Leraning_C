#include <iostream>
#include <string>
#include <locale>
#include <cmath>

using namespace std;

int main(){
    setlocale(LC_ALL, "Portuguese");

    int num1, num1o, i;
    
    cout << "CALCULADORA DE FATORIAL" << endl;
    cout << "Digite um número inteiro positivo maior ou igual a 1: ";
    cin >> num1;
    num1o = num1;
    i = num1 - 1;

      if (num1 < 0) {
      cout << "Fatorial de numero negativo nao existe." << endl;
      return 1;
      } else if (num1 == 0) {
        cout << "Fatorial de 0 é 1." << endl;
        return 0;
      } else if (num1 != floor(num1)) {
        cout << "Fatorial de numero decimal nao existe." << endl;
        return 1;
      } 
      while (i >= 1) {
        num1 = num1 * i;
        i--;
      }
        cout << "O fatorial de " << num1o << " é " << num1 << endl;
        cout << "Pressione qualquer tecla para continuar..." << endl;
        
        cin.ignore();
        cin.get();
    return 0;
}