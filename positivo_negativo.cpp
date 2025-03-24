#include <iostream>
#include <string>
#include <locale>

using namespace std;

int main(){
    setlocale(LC_ALL, "pt_BR.UTF-8");

    float a;
    char opcao;

    do {
     cout << "SEU NÚMERO É POSITIVO, NEGATIVO OU ZERO?\n";
     cout << "----------------------------------------\n";
     cout << "Digite seu número: \n";
     cin >> a;
     if (a > 0) {
        cout << "Seu número é positivo.\n";
     } else if ( a == 0) {
        cout << "Seu número não é possitivo nem negativo :(\n";
     } else {
        cout << "Seu número é negativo.\n";
    }
        cout << "Deseja verificar outro número? ('s' para sim e 'n' para não)\n";
        cin >> opcao;
    } while (opcao == 's' || opcao == 'S' );

    system("pause");
    return 0;
}

