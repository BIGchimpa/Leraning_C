#include <iostream>

using namespace std;

int main(){
   float N1, N2, N3, NF;
 do {
   cout << "Digite a primeira nota: \n";
   cin >> N1;
   cout << "Digite a segunda nota: \n";
   cin >> N2;
   cout << "Digite a terceira nota: \n";
   cin >> N3;
   if (N1 < 0 || N1 > 10 || N2 < 0 || N2 > 10 || N3 < 0 || N3 > 10) {
      cout << "Nota invalida\n";
      system("pause");
   } else {
      NF = (N1 + N2 + N3) / 3;
      cout << "Nota final: " << NF << endl;
   }
     } while (N1 < 0 || N1 > 10 || N2 < 0 || N2 > 10 || N3 < 0 || N3 > 10);

   if (NF >= 5) {
      cout << "Aprovado\n";
   }
   else{
      cout << "Reprovado\n";
   }
   cout << "Pressione Enter para sair...";
   cin.ignore();
   cin.get();

   return 0;
}