#include <iostream> 
using namespace std;


void inverterArrayComPonteiros(int* arr, int size) {

    if (arr == nullptr || size < 2) {
        return;
    }

 
    int* ptrEsquerda = arr; 
    

    int* ptrDireita = arr + (size - 1); 


    while (ptrEsquerda < ptrDireita) {

        int temp = *ptrEsquerda; 

        *ptrEsquerda = *ptrDireita; 
        
  
        *ptrDireita = temp; 

        ptrEsquerda++; 

        ptrDireita--; 
    }
}
