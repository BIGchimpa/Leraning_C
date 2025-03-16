#include <iostream>
#include <string>

using namespace std;

int main(){
    int a, b;

    cout << "Digite o primeiro numero: \n";
    cin >> a;
    cout << "Digite o segundo numero: \n";
    cin >> b;

    a += b;

    cout << "O resultado da soma eh: " << a << endl;
    
    a -= b;
    a = a - b;

    cout << "O resultado da subtracao eh:" << a << endl;

    a += b;
    a = a*b;

    cout << "O resultado da multiplicacao eh: " << a << endl;
    
    a /= b;
    a = a/b;

    cout << "O resultado da divisao eh: " << a << endl;
    
    system("pause");
    return 0;
}