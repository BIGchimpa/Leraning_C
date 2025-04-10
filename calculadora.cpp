#include <iostream>
#include <string>
#include <locale>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
    setlocale(LC_ALL, "Portuguese");
    int operac;
    float num1, num2, result;
    char retry;

     do {
       cout << "CALCULADORA" << endl;
       cout << "Escolha a opção desejada:" << endl;
         cout << "1 - Soma" << endl;
         cout << "2 - Subtração" << endl;
         cout << "3 - Multiplicação" << endl;
         cout << "4 - Divisão" << endl;
         cin >> operac;
         if (operac < 1 || operac > 4 || operac != floor(operac)) {
             cout << "Opção inválida. Tente novamente." << endl;
             return 1;
         } else if (operac == 1){
                cout << "Digite o primeiro número: ";
                cin >> num1;
                cout << "Digite o segundo número: ";
                cin >> num2;
                result = num1 + num2;
                cout << fixed << setprecision(6); // Define a precisão do cout para 6 casas decimais
                cout << "Resultado: " << result << endl;
         } else if (operac == 2){
                cout << "Digite o primeiro número: ";
                cin >> num1;
                cout << "Digite o segundo número: ";
                cin >> num2;
                result = num1 - num2;
                cout << fixed << setprecision(6);
                cout << "Resultado: " << result << endl;
         } else if (operac == 3){
                cout << "Digite o primeiro número: ";
                cin >> num1;
                cout << "Digite o segundo número: ";
                cin >> num2;
                result = num1 * num2;
                cout << fixed << setprecision(6);
                cout << "Resultado: " << result << endl;
         } else if (operac == 4){
                cout << "Digite o primeiro número: ";
                cin >> num1;
                cout << "Digite o segundo número: ";
                cin >> num2;
                if (num2 == 0) {
                    cout << "Divisão por zero não é permitida." << endl;
                    return 1;
                }
                result = num1 / num2;
                cout << fixed << setprecision(6);
                cout << "Resultado: " << result << endl;
         }
       
      cout << "Deseja realizar outra operação? Digite 's' para sim ou 'n' para não: ";
      cin >> retry;
     } while (retry == 's' || retry == 'S');


    cout << "Obrigado por usar a calculadora!" << endl;
    cout << "Pressione qualquer tecla para continuar..." << endl;
    cin.ignore();
    cin.get();
    return 0;
}