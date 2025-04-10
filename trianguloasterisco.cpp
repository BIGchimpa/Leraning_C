#include <iostream>
#include <string>
#include <locale>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
    setlocale(LC_ALL, "Portuguese");
    char retry;
    int altura;

    do {
        cout << "CALCULADORA DE TRIÂNGULO DE ASTERISCO" << endl;
        cout << "Digite a altura do triângulo (número inteiro positivo): ";
        cin >> altura;

        if (altura <= 0 || altura != floor(altura)) {
            cout << "Número inválido. Digite um número inteiro positivo." << endl;
            continue;
        }

        // Imprime o triângulo de asteriscos
        for (int i = 1; i <= altura; i++) {
            // Imprime os espaços
            for (int j = 1; j <= altura - i; j++) {
                cout << " ";
            }
            // Imprime os asteriscos
            for (int k = 1; k <= (2 * i - 1); k++) {
                cout << "*";
            }
            cout << endl; // Quebra de linha após cada nível do triângulo
        }

        cout << "Deseja calcular outro triângulo de asterisco? (s/n): ";
        cin >> retry;

    } while (retry == 's' || retry == 'S');

    cout << "Obrigado por usar a calculadora de TRIÂNGULO DE ASTERISCO!" << endl;
    cout << "Pressione qualquer tecla para continuar..." << endl;
    cin.ignore();
    cin.get();
    return 0;
}