#include <iostream>
#include <locale>

using namespace std;

int main(){

    setlocale(LC_ALL, "pt_BR.UTF-8");
    int idade, tempoContribuicao, diferenca;
    cout << "QUAL A SUA IDADE E TEMPO DE CONYTRIBUIÇÃO?\n";
    cout << "------------------------------------------\n";
    cout << "Digite su idade: ";
    cin >> idade;
    cout << "Digite o tempo de contribuição: ";
    cin >> tempoContribuicao;
    diferenca = idade - tempoContribuicao;

    if (idade < 0 || tempoContribuicao < 0 || diferenca < 14){             
        cout << "Idade e tempo de contribuição não podem ser negativos\n";
        cout << "Idade não pode ser menor que o tempo de contribuição\n";
    }
    
    else if ( idade >= 65 || tempoContribuicao >= 30 || (idade >= 60 && tempoContribuicao >= 25)){
        cout << "Você pode se aposentar\n";
    } else {
        cout << "Você não pode se aposentar\n";
    }
   

    system("pause");
    return 0;
}