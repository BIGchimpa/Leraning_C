#include <iostream>
#include <string>

using namespace std;

int main(){
    int num1;
    int num2;

    cout << "Digite o primeiro numero: \n";
    cin >> num1;
    cout << "Digite o segundo numero: \n";
    cin >> num2;

    int soma = num1 + num2;

    cout << "O resultado da soma eh: " << soma << endl;

    system("pause");
    return 0;
}