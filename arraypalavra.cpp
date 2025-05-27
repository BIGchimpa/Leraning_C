#include <iostream>
#include <locale>

using namespace std;


int main(){
    setlocale(LC_ALL, "pt_BR.UTF-8");
    
    char palavra[50];
    
    cout << "DIGITE UMA PALAVRA: ";
    cin >> palavra;
    cout << "A primeira letra da sua palavra é: '" << palavra[0] << "'.";
    
    cin.ignore();
    cin.get();
    return 0;
}
