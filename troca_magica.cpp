#include <iostream>
#include <string>

using namespace std;

int main(){
    int a;
    int b;

    cout << "Digite seu numero favorito: \n";
    cin >> a;
    cout << "Digite o numero que mais odeia: \n";
    cin >> b;

    a = a + b; // "a" recebe o valor de "a" mais "b"
    b = a - b; // "b" recebe o valor de "a" original
    a = a - b; // "a" recebe o valor de "b" original

    cout << "Seu numero favorito eh: " << a << endl;
    cout << "O numero que mais odeia eh: " << b << endl;

    system("pause");
    return 0;
}