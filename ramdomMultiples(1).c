#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main(){  
    setlocale(LC_ALL, "pt_BR.UTF-8");
    srand(time(NULL));
    char retry = 's';
    
 do{    
    int num1 = rand() % 1000 + 1, num2 = rand() % 1000/2 + 1;
    
    puts("Are this two numbers multiple of eache other?");
    printf("The two secret numbers are: %d & %d\n", num1, num2);
    
    if(num1 % num2 != 0 && num2 % num1 != 0){
        printf("%d is not multiple of %d, neither are %d multiple of %d\n", num1, num2, num2, num1);
    }
    if(num1 % num2 != 0 && num2 % num1 == 0){
        printf("%d is not multiple of %d, but %d is multiple of %d\n", num1, num2, num2, num1);
    }
    if(num1 % num2 == 0 && num2 % num1 != 0){
        printf("%d is multiple of %d, but %d is not multiple of %d\n", num1, num2, num2, num1);
    }
    if(num1 % num2 == 0 && num2 % num1 == 0){
        printf("%d is multiple of %d and %d is multiple of %d\n", num1, num2, num2, num1);
    }
    puts("Do you want to compute with others numbers? Press 's' for YES and 'n' for NO...");
    scanf(" %c", &retry);
    
  }while(retry == 's' || retry == 'S');    

    return 0;
}