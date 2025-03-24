#include <iostream>
#include <string>
#include <locale>

using namespace std;

int main(){
    setlocale(LC_ALL, "pt_BR.UTF-8");

    float a, b, c;
    float ang_a, ang_b, ang_c;
    char retry;
    char escolha;
    cout << "SEU TRIÂNGULO É RETÂNGULO?\n";
    cout << "--------------------------\n";

  do {
    
    while (true) {
        cout << "Deseja verificar o triângulo através dos ângulos internos ou através dos lados? ('a' para ângulos e 'l' para lados)\n";
        cin >> escolha;
        if (escolha == 'a' || escolha == 'A') {
            cout << "Digite os ângulos internos do triângulo: \n";
            cin >> ang_a >> ang_b >> ang_c; 
            if ((cin.fail()) || ang_a + ang_b + ang_c != 180 || ang_a <= 0 || ang_b <= 0 || ang_c <= 0) {
                cout << "Os ângulos informados não formam um triângulo válido!\n";
            } else {
                break;
            }
        } else if (escolha == 'l' || escolha == 'L') {
            cout << "Digite a medidas dos três lados do triângulo: \n";
            cin >> a >> b >> c;
            if ((cin.fail()) || ( a <= 0 ||  b <= 0 ||  c <= 0) || (a + b <= c) || (a + c <= b) || (b + c <= a)) { 
                cin.clear(); 
                cin.ignore(1000, '\n'); 
                cout << "Números inválidos! Digite apenas números! Digite números positivos! A soma dois dois menores lados do triângulo deve ser maior que a medida do maior lado!\n"; 
            } else {
                break; 
            }
        } else {
            cout << "Opção inválida! Digite 'a' para ângulos e 'l' para lados!\n";
        }
}
       


    if (escolha == 'l' || escolha == 'L') {
        if (a*a == b*b + c*c || b*b == a*a + c*c || c*c == a*a + b*b) {
            cout << "O triângulo é retângulo.\n";
        } else {
            cout << "O triângulo não é retângulo.\n";
        }
    }

    if (escolha == 'a' || escolha == 'A') {
        if (ang_a == 90 || ang_b == 90 || ang_c == 90) {
            cout << "O triângulo é retângulo.\n";
        } else {
            cout << "O triângulo não é retângulo.\n";
        }
    }
   
    cout << "---------------------------------------------------------------\n";  
    cout << "Deseja verificar outro triângulo? ('s' para sim e 'n' para não)\n";
    cin >> retry;
  } while ( retry == 's' || retry == 'S');
 
    system ("pause");
    return 0;
}