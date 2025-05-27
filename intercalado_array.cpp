#include <iostream>
#include <locale>

using namespace std;


int main(){
    setlocale(LC_ALL, "pt_BR.UTF-8");
    
    int A[5] = {0,2,4,6,8};
    int B[5] = {1,3,5,7,9};
    int i = 0;
    
    for(i = 0;i < 5; i++){
        cout << A[i] << "\t" << B[i] << "\t";
    }
    
    cin.ignore();
    cin.get();
    return 0;
}
