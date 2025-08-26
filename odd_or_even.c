#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main(){  
    setlocale(LC_ALL, "pt_BR.UTF-8");
    srand(time(NULL));
    
    int num1 = rand() % 100000000000 + 1;
    
    puts("It´s oven or it´s even?");
    printf("The secret number is: %d\n", num1);
    if(num1 % 2 != 0){
        puts("The secret numbe is odd!");
        return 0;
    }
    puts("The secret number is even!");

    return 0;
}