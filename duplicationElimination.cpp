#include <stdio.h>
#include <stdlib.h>
#include <locale.h> 
#include <time.h> 
#define MAX_SIZE 100

void duplicacaoEliminacao(int* array);

int main(){
    setlocale(LC_ALL, "pt_BR.UTF-8");
    int randomNumbers[20];
    srand(time(NULL));
    for(int i = 0; i < 20; i++){
        randomNumbers[i] = (rand() % 20) + 1;
}
    duplicacaoEliminacao(randomNumbers);



}

void duplicacaoEliminacao(int* array){
    for(int x = 0; x < 20; x++){
        for(int j = x + 1; j < 20; j++){
            if(array[j] == array[x]){
                array[j] = -1;
        }
    }
}

    for(int y = 0; y < 20; y++){
        if(array[y] != -1){
            printf("%d\t", array[y]);   
        }
    }
}