#include <iostream>
#include <string>
#include <locale>

using namespace std;

int main(){
    setlocale(LC_ALL, "pt_BR.UTF-8");

    float a, b, c;
    char retry;
    cout << "QUAL O TIPO DO SEU TRIÃNGULO?\n";
    cout << "-----------------------------\n";

  do {
    
    while (true) {
        double temp_a, temp_b, temp_c; 
        cout << "Digite a medidas dos três lados do triângulo: \n";
        cin >> temp_a >> temp_b >> temp_c;
       
        if ((cin.fail()) || ( temp_a <= 0 ||  temp_b <= 0 ||  temp_c <= 0) || (temp_a + temp_b <= temp_c) || (temp_a + temp_c <= temp_b) || (temp_b + temp_c <= temp_a)) { 
            cin.clear(); 
            cin.ignore(1000, '\n'); 
            cout << "Números inválidos! Digite apenas números! Digite números positivos! A soma dois dois menores lados do triângulo deve ser maior que a medida do maior lado!\n"; 
        } else {
            a = temp_a; b = temp_b; c = temp_c;
            break; 
        }
          }

    if (a == b && b == c) {
        cout << "O triângulo é equilátero.\n";
    } else if (a == b && b != c || a == c && c != b || b == c && c != a) {
        cout << "O triângulo é isósceles.\n";
    } else if ( a != b && b != c && a != c) {
        cout << "O triângulo é escaleno.\n";
    }
   
    cout << "---------------------------------------------------------------\n";  
    cout << "Deseja verificar outro triângulo? ('s' para sim e 'n' para não)\n";
    cin >> retry;
  } while ( retry == 's' || retry == 'S');
 
    system ("pause");
    return 0;
}