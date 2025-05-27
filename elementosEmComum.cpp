#include <iostream>
#include <locale>

using namespace std;

void elementosComuns(int A[],int B[],int T){
    int resultado[T];
    int w, i, j;
    w = 0;
    j = 0;
    for (i = 0; i < T; i++){
        while (w < T){
        if(A[i] == B[w]){
            resultado[j] = B[w];
            j++;
           
        }
             w++;
        }
        w = 0;
        
    }
    if (j == 0){
        cout << "n tem elementos em comum kkkkkk";
    } else{
    for(i = 0; i < j; i++){
     cout << resultado[i] << "\t";   
    } }
}

