#include <iostream>
#include <string>
#include <locale>

using namespace std;

int main(){
    setlocale(LC_ALL, "pt_BR.UTF-8");

    int a;
    char retry;

    do {
     cout << "SEU NÚMERO É PAR OU ÍMPAR?\n";
     cout << "--------------------------\n";

       while (true) {
        double temp; // Variável temporária para verificar se "a" é um número inteiro
        cout << "Digite seu número: \n";
        cin >> temp; // Lê o valor digitado pelo usuário e armazena na variável temporária
       
        if (cin.fail() || floor(temp) != temp) { // Verifica se "temp" é um número inteiro, pois se função piso "temp" for diferente do valor de "temp", então "temp" não é um número inteiro.
            cin.clear(); // Limpa o estado de erro
            cin.ignore(1000, '\n'); // Ignora a entrada inválida
            cout << "Número inválido. Digite um número inteiro!\n"; // Se o usuário colocar um valor não numérico ou um valor numérico não-inteiro, o programa envia uma mensagem de erro.
        } else {
            a = temp; // Se o usuário colocar um valor inteiro e válido, a variável temporária é atribuída a "a"
            break; // Se o usuário colocar um valor inteiro e válido, o programa continua.
        }
          }

                  
     if (a % 2) {
        cout << "Seu número é ímpar.\n";
     } else {
        cout << "Seu número é par.\n";
     }
     cout << "Deseja verificar outro número? ('s' para sim e 'n' para não)\n";
     cin >> retry;
    } while (retry == 's' || retry == 'S' );
    
    system ("pause");
    return 0;
}