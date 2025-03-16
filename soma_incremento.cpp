#include <iostream>
#include <string>

using namespace std;

int main(){
    double num1;
    double num2;

    cout << "Digite o primeiro numero: \n";
    cin >> num1;
    cout << "Digite o segundo numero: \n";
    cin >> num2;

    num1 += num2;

    cout << "O resultado da soma eh: " << num1 << endl;

    system("pause");
    return 0;
}