#include <iostream>
#include <locale>


using namespace std;

int main(){
    setlocale(LC_ALL, "pt_BR.UTF-8");
    int n;
    cout << "QUAL VALOR ABSOLUTO DO SEU NÚMERO?\n";
    cout << "----------------------------------------------------------------------------------------------------------------------------------------------\n";
    cout << "Digite um número: ";
    cin >> n;
    if (n >= 0){
        cout << "O valor absoluto do seu número é: " << n << endl;
    }
    else{
        cout << "O valor absoluto do seu número é: " << n * -1 << endl;
    }
    
    system("pause");
    return 0;
}