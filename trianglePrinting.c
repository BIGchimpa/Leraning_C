#include <stdio.h>
#include <locale.h>

void triangulo1(int height);
void triangulo2(int height);
void triangulo3(int height);
void triangulo4(int height);
void triangulo5(int height);

int main(){
    setlocale(LC_ALL, "pt_BR.UTF-8");

    int altura;
    char retry = 'y';
    do{
        puts("Digite a altura do triângulo:");
        scanf_s("%d", &altura);
        puts("");

        triangulo1(altura);
        puts("\n");
        triangulo2(altura);
        puts("\n");
        triangulo3(altura);
        puts("\n");
        triangulo4(altura);
        puts("\n");
        triangulo5(altura);
        puts("\n");
        puts("Deseja uma nova rodada? Digite Y para sim e N para não...");
        scanf_s(" %c", &retry, 1);
    } while(retry == 'y' || retry == 'Y');
    
    return 0;
}

void triangulo1(int height){
    int i = 1, l;
    l = i;
    while(height > 0){
        while(i > 0){
            printf("*");
            i--;
        }
        puts("");
        i = l;
        i++;
        l = i;
        height--;
    }
    return;
}
void triangulo2(int height){
    int i = height;
    while(height > 0){
        while(height > 0){
            printf("*");
            height--;
        }
        puts("");
        height = i;
        height--;
        i = height;
    }
    return;
}
void triangulo3(int height){
    int blankSpace = 0;
    int i = height;
    int l = blankSpace;

    while(height > 0){
        while(blankSpace > 0){
            printf(" ");
            blankSpace--;
        }
        blankSpace = l;
        blankSpace++;
        l = blankSpace;
        while(height > 0){
            printf("*");
            height--;
        }
        height = i;
        height--;
        i = height;
        puts("");
    }

    return;
}
void triangulo4(int height){
    int blankSpace = (height - 1);
    int asterisk = 1;
    int y = asterisk;
    int i = height;
    int l = blankSpace;

    while(height > 0){
        while(blankSpace > 0){
            printf(" ");
            blankSpace--;
        }
        blankSpace = l;
        blankSpace--;
        l = blankSpace;
        while(asterisk > 0){
            printf("*");
            asterisk--;
        }
        asterisk = y;
        asterisk++;
        y = asterisk;
        height--;
        puts("");
    }

    return;
}

void triangulo5(int height){
    int blankLeft = ((1+((height - 1)*2))/2);
    int asterisk = 1;
    int y = asterisk;
    int i = height;
    int l = blankLeft;

    while(height > 0){
        while(blankLeft > 0){
            printf(" ");
            blankLeft--;
        }
        blankLeft = l;
        blankLeft--;
        l = blankLeft;
        while(asterisk > 0){
            printf("*");
            asterisk--;
        }
        asterisk = y;
        asterisk += 2;
        y = asterisk;
        height--;
        puts("");
    }
    return;
}