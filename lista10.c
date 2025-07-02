#include <stdio.h> 

// Variável global count inicializada como 0. [cite: 34]
int count = 0; 


int main() { 
    [cite_start]// Pós-incremente e imprima o valor de count cada vez que main for chamada. 
    printf("Chamada %d de main.\n", count++);

    return 0;
}

/*
O que acontece?
Ao executar este programa, a função `main` se chamará recursivamente. 
]A variável `count` é global e, portanto, seu valor persiste entre as chamadas da função. 
Cada vez que `main` é chamada, `count` é pós-incrementado e seu valor é impresso. 
Sem uma condição de parada, isso levaria a um "stack overflow" (estouro de pilha), pois cada chamada recursiva consome espaço na pilha de execução.
*/

// Exercicio numero 2
/*
a) C armazena listas de valores em arrays.
b) Os elementos de um array têm em comum o fato de que eles têm o mesmo tipo.
]c) Ao se referir a um elemento do array, o número da posição contido dentro dos parênteses é um(a) índice ou subscrito.
d) Os nomes dos cinco elementos do array p são p[0], p[1], p[2], p[3], e p[4]. 
e) O conteúdo de um elemento em particular de um array é chamado valor [cite: 44] [cite_start]desse elemento.
f) Dar nome a um array, indicar seu tipo e especificar o número de elementos contidos nele é chamado de declaração do array. 
g) Em um array de subscrito duplo (matriz), o primeiro subscrito (por convenção) identifica a linha [cite: 49] [cite_start]de um elemento, e o segundo subscrito (por convenção) identifica a coluna 
h) Um array *m*-por-*n* contém m [cite: 50] [cite_start]linhas, n [cite: 53] [cite_start]colunas e m * n [n]elementos. 
i) O nome do elemento do array d na linha 3, coluna 5 é d[2][4]. [cite_start](Arrays em C são baseados em zero, então linha 3 é índice 2 e coluna 5 é índice 4).
*/

/*
a) int *number;
   printf("%d\n", *number); [cite_start]// [cite: 59]
   Erro: O ponteiro `number` é declarado, mas não é inicializado. [cite_start]Ele aponta para uma localização de memória arbitrária. [cite: 58]
   A desreferenciação de um ponteiro não inicializado resulta em comportamento indefinido (segmentation fault).
   Correção: Inicializar o ponteiro para NULL ou para um endereço de memória válido antes de desreferenciá-lo.
   Ex: int *number = NULL; ou int var = 10; int *number = &var;

[cite_start]b) float *realPtr; [cite: 60]
   [cite_start]long *integerPtr; [cite: 60]
   integerPtr = realPtr; [cite_start]// [cite: 61]
   [cite_start]Erro: Atribuição de ponteiros de tipos incompatíveis sem um cast explícito. [cite: 61]
   [cite_start]`realPtr` é um ponteiro para `float` e `integerPtr` é um ponteiro para `long`. [cite: 60]
   Embora ambos sejam endereços de memória, o compilador C pode emitir um aviso ou erro devido à incompatibilidade de tipos de dados.
   Correção: Usar um cast explícito se a conversão for intencional: `integerPtr = (long *)realPtr;`

[cite_start]c) int *x, y; [cite: 62]
   x = y; [cite_start]// [cite: 62]
   Erro: Atribuição de um valor inteiro a um ponteiro. [cite_start]`x` é um ponteiro para `int`, e `y` é um `int`. [cite: 62]
   Você não pode atribuir diretamente o valor de uma variável inteira a um ponteiro, a menos que seja um endereço de memória.
   Correção: Para fazer `x` apontar para `y`, use o operador de endereço: `x = &y;`.

[cite_start]d) char s[] = "um array de caracteres"; [cite: 63]
   int count;
   [cite_start]for (; *s != '\0'; s++) // [cite: 64]
   printf("%c", *s); [cite_start]// [cite: 65]
   [cite_start]Erro: A variável `s` é um array estático (não um ponteiro modificável no contexto da função). [cite: 63]
   `s` na verdade se comporta como um ponteiro constante para o início do array. Você não pode incrementar `s` diretamente (`s++`) porque ele não é um l-value modificável.
   Correção: Use um ponteiro auxiliar ou um índice para iterar sobre o array:
   Ex: `char *ptr = s; for (; *ptr != '\0'; ptr++) printf("%c", *ptr);`
   Ou: `for (int i = 0; s[i] != '\0'; i++) printf("%c", s[i]);`

[cite_start]e) short *numPtr, result; [cite: 66]
   [cite_start]void *genericPtr = numPtr; [cite: 66]
   result = *genericPtr + 7; [cite_start]// [cite: 66]
   [cite_start]Erro: Desreferenciação de um ponteiro `void*` sem cast. [cite: 66]
   [cite_start]`void*` é um ponteiro genérico que não tem um tipo de dado associado; portanto, você não pode desreferenciá-lo diretamente (`*genericPtr`) porque o compilador não sabe quantos bytes ler. [cite: 66]
   Correção: Faça um cast para o tipo apropriado antes de desreferenciar: `result = *(short *)genericPtr + 7;`

[cite_start]f) float x = 19.34; [cite: 67]
   float xPtr = &x; [cite_start]// [cite: 67]
   printf("%f\n", xPtr); [cite_start]// [cite: 67]
   Erro: Atribuição do endereço de `x` (um `float*`) a uma variável `float`. [cite_start]`xPtr` deve ser um ponteiro para `float`, não um `float`. [cite: 67]
   [cite_start]Além disso, `printf("%f\n", xPtr)` está incorreto; para imprimir o valor para o qual um ponteiro aponta, você precisa desreferenciá-lo ou, se quiser imprimir o endereço, usar `%p`. [cite: 67]
   Correção:
   `float *xPtr = &x;`
   `printf("%f\n", *xPtr);` // Para imprimir o valor para o qual xPtr aponta
   `printf("%p\n", (void *)xPtr);` // Para imprimir o endereço
   `printf("%f\n", x);` // Se a intenção era imprimir o valor de x

[cite_start]g) char *s; [cite: 68]
   printf("%s\n", s); [cite_start]// [cite: 69]
   [cite_start]Erro: O ponteiro `s` é declarado, mas não inicializado. [cite: 68]
   [cite_start]`%s` espera que o ponteiro aponte para o início de uma string terminada em nulo (`\0`). [cite: 69]
   A tentativa de imprimir uma string a partir de um ponteiro não inicializado levará a um comportamento indefinido (geralmente um segmentation fault) ao tentar acessar uma área de memória inválida.
   Correção: Inicializar `s` para apontar para uma string válida ou alocar memória para ela:
   Ex: `char *s = "Hello";` ou `char buffer[100]; s = buffer;`
*/



// exercicio 4
#include <stdio.h>
[cite_start]#include <stdlib.h> // Para malloc, free, realloc [cite: 71, 74]

void exercicio4_arrayDinamico() {
    printf("\n--- Exercicio 4: Array Alocado Dinamicamente ---\n");

    int *array = NULL;
    int tamanho_original;

    [cite_start]// Obter o tamanho do array do teclado. [cite: 72]
    printf("Digite o tamanho do array: ");
    while (scanf("%d", &tamanho_original) != 1 || tamanho_original <= 0) {
        printf("Entrada invalida. Digite um numero inteiro positivo: ");
        while (getchar() != '\n'); // Limpa o buffer de entrada
    }

    [cite_start]// Alocar um array de inteiros dinamicamente. [cite: 71]
    array = (int *)malloc(tamanho_original * sizeof(int)); [cite_start]// [cite: 71]
    if (array == NULL) {
        printf("Erro na alocacao de memoria para o array.\n");
        return;
    }
    printf("Array alocado com sucesso (tamanho: %d).\n", tamanho_original);

    [cite_start]// Os elementos do array devem ser valores atribuidos a partir da entrada pelo teclado. [cite: 73]
    printf("Preencha os %d elementos do array:\n", tamanho_original); [cite_start]// [cite: 73]
    for (int i = 0; i < tamanho_original; i++) {
        printf("Elemento [%d]: ", i);
        while (scanf("%d", &array[i]) != 1) {
            printf("Entrada invalida. Digite um numero inteiro: ");
            while (getchar() != '\n'); // Limpa o buffer de entrada
        }
    }

    [cite_start]// Imprima os valores do array. [cite: 73]
    printf("\nValores do array original:\n"); [cite_start]// [cite: 73]
    for (int i = 0; i < tamanho_original; i++) {
        printf("%d ", array[i]); [cite_start]// [cite: 73]
    }
    printf("\n");

    [cite_start]// Realoque a memoria do array a metade do numero atual de elementos. [cite: 74]
    int novo_tamanho = tamanho_original / 2;
    if (novo_tamanho == 0 && tamanho_original > 0) {
        novo_tamanho = 1; // Garante que array não fique com tamanho 0 se original era 1
    } else if (tamanho_original == 0) {
        // Nada a realocar
        novo_tamanho = 0;
    }

    if (novo_tamanho > 0) {
        int *temp_array = (int *)realloc(array, novo_tamanho * sizeof(int)); [cite_start]// [cite: 74]
        if (temp_array == NULL) {
            printf("Erro na realocacao de memoria. O array original permanece intacto.\n");
            free(array); // Libera o array original se a realocação falhou
            return;
        }
        array = temp_array; // Atualiza o ponteiro para o novo bloco de memória
        printf("\nArray realocado para metade do tamanho (novo tamanho: %d).\n", novo_tamanho); [cite_start]// [cite: 74]
    } else {
        printf("\nO tamanho original era muito pequeno para realocar para metade (novo tamanho seria 0).\n");
        free(array); // Libera o array original
        array = NULL;
        return;
    }


    // Imprima os valores restantes do array para confirmar se eles correspondem
    [cite_start]// aos valores da primeira metade do array original. [cite: 75]
    printf("Valores restantes do array (primeira metade do original):\n"); [cite_start]// [cite: 75]
    if (array != NULL) {
        for (int i = 0; i < novo_tamanho; i++) {
            printf("%d ", array[i]); [cite_start]// [cite: 75]
        }
        printf("\n");
    } else {
        printf("Array esta vazio apos realocacao.\n");
    }


    // Libera a memória alocada
    if (array != NULL) {
        free(array); [cite_start]// [cite: 74]
        printf("Memoria do array liberada.\n");
    }
}

