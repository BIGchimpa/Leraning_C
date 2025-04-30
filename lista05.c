#include <stdio.h>
#include <math.h>

// 5. Função que calcula o IMC e classifica
int calcula_imc(float peso, float altura) {
    float imc = peso / (altura * altura);
    if (imc < 18.5)
        return 0; // Magreza
    else if (imc < 25.0)
        return 1; // Saudável
    else if (imc < 30.0)
        return 2; // Sobrepeso
    else
        return 3; // Obesidade
}

// Função que imprime a classificação do IMC
void imprima_imc(float peso, float altura) {
    int classificacao = calcula_imc(peso, altura);
    switch (classificacao) {
        case 0: printf("Magreza\n"); break;
        case 1: printf("Saudável\n"); break;
        case 2: printf("Sobrepeso\n"); break;
        case 3: printf("Obesidade\n"); break;
        default: printf("Erro na classificação\n");
    }
}

// 6. Função que verifica se um número é palíndromo
int eh_palindromo(int numero) {
    int original = numero, reverso = 0;
    while (numero > 0) {
        reverso = reverso * 10 + (numero % 10);
        numero /= 10;
    }
    return (original == reverso) ? 1 : 0;
}

// 7. Função que calcula perímetro e área de um círculo usando ponteiros
void calcular_circulo(float raio, float *perimetro, float *area) {
    const float PI = 3.1415926535;
    *perimetro = 2 * PI * raio;
    *area = PI * raio * raio;
}

// 8. Função que calcula distância euclidiana entre dois pontos
float distancia(float x1, float y1, float x2, float y2) {
    return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
}
