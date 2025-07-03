#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    srand(time(NULL));
    int numeroAleatorio, chances, numeroAleatorio2;
    char retry;
    
    do{
  
    chances = 9;
    numeroAleatorio = 1 + (rand() % 1000);
    numeroAleatorio2 = 0;
        
    do{
        
        puts("**ACERTE O NÚMERO**");
        puts("Digite um número de 1 a 1000");
        scanf("%d", &numeroAleatorio2);
        
        if (numeroAleatorio2 == numeroAleatorio){
            printf("PARABENS, VOCE GANHOU O JOGO COM %d chances restantes!", chances);
            return 0;
        }
        else {
            chances--;
            printf("Que pena! Voce errou... tente novamente. Voce ainda tem %d chances \n", chances);
            
            if (numeroAleatorio2 > numeroAleatorio){
                puts("o numero digitado eh maior que o numero real... \n \n");
            }
            if (numeroAleatorio2 < numeroAleatorio){
                puts("o numero digitado eh menor que o numero real...\n \n");
            }
        }
        
    } while(chances >= 1);
    
    printf ("O número era: %d \n", numeroAleatorio);
    printf("Errouuuu! perdeu todas as chances! :( \n \n \n");
    puts("Deseja jogar novamente? digite \"s\" para sim e \"n\" para não");
    scanf (" %c", &retry);
    } while (retry == 's' || retry == 'S');
    
    return 0;
}
