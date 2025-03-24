#include <iostream>
#include <string>
#include <locale>

using namespace std;

int main(){
    setlocale(LC_ALL, "pt_BR.UTF-8");

    float a;
    char retry;

    do {
    cout << "QUAL O VALOR ABSOLUTO DO SEU NÚMERO?\n";
    cout << "------------------------------------\n";
    cout << "Digite seu número: \n";
    cin >> a;

    if (a < 0) {
    a = -1*a;
    }
    
    cout << "O valor absoluto do seu número é: " << a << endl;
    cout << "Deseja verificar outro número? ('s' para sim e 'n' para não)\n";
    cin >> retry; 
    } while (retry == 's' || retry == 'S');

    system ("pause");
    return 0;
}

