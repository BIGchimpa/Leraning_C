#include <iostream>
#include <string>
#include <locale>

using namespace std;

int main(){
    setlocale(LC_ALL, "pt_BR.UTF-8");

    int idade, tempoCont;
    char retry;

do {
    cout << "VOCÊ PODE SE APOSENTAR?\n";
    cout << "-----------------------\n";
   
   while (true) {
    cout << "Digite sua idade: \n";
    cin >> idade;
    cout << "Digite o tempo de contribuição: \n";
    cin >> tempoCont;

    if (cin.fail() || idade < 0 || idade > 120 || tempoCont < 0 || (idade - tempoCont < 14)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Número inválido. Digite um número válido para realizar a conferência!\n";
        
    } else {
        break;
    }
                }

    if (idade >= 65 || tempoCont >=30 || (idade >= 60 && tempoCont >=25)) {
        cout << "Você pode se aposentar! :)\n";
    } else {
        cout << "Você não pode se aposentar! :(\n";
    }
    cout << "Deseja verificar outra idade e tempo de contribuição? ('s' para sim e 'n' para não)\n";
    cin >> retry;
} while ( retry == 's' || retry == 'S');
 
    system ("pause");
    return 0;
}