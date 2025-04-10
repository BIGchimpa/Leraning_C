#include <iostream>
#include <string>
#include <locale>
#include <cmath>

using namespace std;

int main(){
    setlocale(LC_ALL, "Portuguese");

    int num1, num1o, i;
    i = 2;

    cout << "SEU NÚMERO É PRIMO?" << endl;
    cout << "Digite um número inteiro positivo maior ou igual a 1: ";
    cin >> num1;
    num1o = num1;
    
    
    if (num1 <= 0 || num1 != floor(num1)) {
        cout << "Número inválido. Digite um número inteiro positivo maior ou igual a 1." << endl;
        return 1;
    }  while(i < num1o) {
        if (num1 % i == 0) {
            cout <<  "O número " << num1o << " não é primo." << endl;
            cout << "Pressione qualquer tecla para continuar..." << endl;
            cin.ignore();
            cin.get();
            return 0;
        } else {
            i++;
        }
    }
    cout << "O número " << num1o << " é primo." << endl;
    cout << "Pressione qualquer tecla para continuar..." << endl;
    
        
        cin.ignore();
        cin.get();
    return 0;
}