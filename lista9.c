#include <stdio.h>
#include <stdlib.h> // Para malloc e free

// --- 1. Função para Somar Duas Matrizes 3x3 ---

void exercicio1_somarMatrizes3x3(int matriz1[3][3], int matriz2[3][3], int resultado[3][3]) {
    printf("\n--- Exercicio 1: Soma de Duas Matrizes 3x3 ---\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            resultado[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
    printf("Matriz Soma:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", resultado[i][j]);
        }
        printf("\n");
    }
}

// --- 2. Função para Calcular a Transposta de uma Matriz 3x3 ---

void exercicio2_transpostaMatriz3x3(int matriz[3][3], int transposta[3][3]) {
    printf("\n--- Exercicio 2: Transposta de uma Matriz 3x3 ---\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            transposta[j][i] = matriz[i][j];
        }
    }
    printf("Matriz Original:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("Matriz Transposta:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", transposta[i][j]);
        }
        printf("\n");
    }
}

// --- 3. Função para Verificar se um Número Está Presente em uma Matriz ---

int exercicio3_verificarNumeroEmMatriz(int matriz[3][3], int numero, int *linha, int *coluna) {
    printf("\n--- Exercicio 3: Verificar Numero em Matriz 3x3 ---\n");
    printf("Matriz:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("Procurando o numero: %d\n", numero);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matriz[i][j] == numero) {
                *linha = i;
                *coluna = j;
                printf("Numero %d encontrado na posicao [%d][%d].\n", numero, *linha, *coluna);
                return 1; // Encontrado
            }
        }
    }
    printf("Numero %d NAO encontrado na matriz.\n", numero);
    return 0; // Não encontrado
}

// --- 4. Função para Calcular a Soma dos Elementos da Diagonal Principal de uma Matriz 3x3 ---

int exercicio4_somaDiagonalPrincipal3x3(int matriz[3][3]) {
    printf("\n--- Exercicio 4: Soma da Diagonal Principal de Matriz 3x3 ---\n");
    printf("Matriz:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    int soma = 0;
    for (int i = 0; i < 3; i++) {
        soma += matriz[i][i];
    }
    printf("Soma da Diagonal Principal: %d\n", soma);
    return soma;
}

// --- 5. Função para Implementar o Produto Vetorial de Duas Matrizes 3x3 (Produto de Matrizes) ---

void exercicio5_produtoMatrizes3x3(int matriz1[3][3], int matriz2[3][3], int resultado[3][3]) {
    printf("\n--- Exercicio 5: Produto de Matrizes 3x3 ---\n");
    printf("Matriz 1:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matriz1[i][j]);
        }
        printf("\n");
    }
    printf("Matriz 2:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matriz2[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
    printf("Matriz Produto (Matriz1 x Matriz2):\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", resultado[i][j]);
        }
        printf("\n");
    }
}

// --- 6. Função para Alocar uma Matriz com Linhas e Colunas Desejadas ---

int** exercicio6_alocarMatrizDinamica(int linhas, int colunas) {
    printf("\n--- Exercicio 6: Alocar Matriz Dinamicamente ---\n");
    if (linhas <= 0 || colunas <= 0) {
        printf("Erro: O numero de linhas e colunas deve ser maior que zero.\n");
        return NULL;
    }

    int** matriz = (int**) malloc(linhas * sizeof(int*));
    if (matriz == NULL) {
        printf("Erro: Falha na alocacao de memoria para as linhas.\n");
        return NULL;
    }

    for (int i = 0; i < linhas; i++) {
        matriz[i] = (int*) malloc(colunas * sizeof(int));
        if (matriz[i] == NULL) {
            printf("Erro: Falha na alocacao de memoria para a coluna %d.\n", i);
            for (int j = 0; j < i; j++) {
                free(matriz[j]);
            }
            free(matriz);
            return NULL;
        }
    }
    printf("Matriz %dx%d alocada dinamicamente.\n", linhas, colunas);
    return matriz;
}

// --- 7. Função para Liberar o Espaço Alocado pela Matriz ---

void exercicio7_liberarMatrizDinamica(int** matriz, int linhas) {
    printf("\n--- Exercicio 7: Liberar Matriz Dinamicamente ---\n");
    if (matriz == NULL) {
        printf("A matriz ja e nula ou nao foi alocada.\n");
        return;
    }
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]); // Libera cada linha
    }
    free(matriz); // Libera o array de ponteiros para as linhas
    printf("Matriz liberada.\n");
}

// --- 8. Função para o Usuário Preencher uma Matriz Dinâmica ---

void exercicio8_preencherMatrizDinamica(int** matriz, int linhas, int colunas) {
    printf("\n--- Exercicio 8: Preencher Matriz Dinamica ---\n");
    if (matriz == NULL || linhas <= 0 || colunas <= 0) {
        printf("Erro: Matriz invalida para preenchimento.\n");
        return;
    }

    printf("Preenchendo a matriz %dx%d:\n", linhas, colunas);
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("Digite o valor para [%d][%d]: ", i, j);
            while (scanf("%d", &matriz[i][j]) != 1) {
                printf("Entrada invalida. Por favor, digite um numero inteiro para [%d][%d]: ", i, j);
                while (getchar() != '\n'); // Limpa o buffer
            }
        }
    }
    printf("Matriz preenchida com sucesso!\n");
}

// --- 9. Função para Imprimir uma Matriz Dinâmica ---

void exercicio9_imprimirMatrizDinamica(int** matriz, int linhas, int colunas) {
    printf("\n--- Exercicio 9: Imprimir Matriz Dinamica ---\n");
    if (matriz == NULL || linhas <= 0 || colunas <= 0) {
        printf("A matriz esta vazia ou nao foi alocada.\n");
        return;
    }

    printf("Matriz:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%5d ", matriz[i][j]);
        }
        printf("\n");
    }
}

// --- Funções Auxiliares para o Exercício 10 ---

int _produtoMatrizesDinamicas(int** matriz1, int linhas1, int colunas1,
                             int** matriz2, int linhas2, int colunas2,
                             int*** resultado) {
    if (matriz1 == NULL || matriz2 == NULL || linhas1 <= 0 || colunas1 <= 0 ||
        linhas2 <= 0 || colunas2 <= 0) {
        return 0; // Erro
    }

    if (colunas1 != linhas2) {
        printf("Erro: O produto de matrizes nao e possivel. As dimensoes nao sao compativeis.\n");
        return 0;
    }

    *resultado = exercicio6_alocarMatrizDinamica(linhas1, colunas2);
    if (*resultado == NULL) {
        return 0; // Erro na alocação
    }

    for (int i = 0; i < linhas1; i++) {
        for (int j = 0; j < colunas2; j++) {
            (*resultado)[i][j] = 0;
            for (int k = 0; k < colunas1; k++) {
                (*resultado)[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
    return 1; // Sucesso
}


// --- 10. Programa que Realiza o Produto Vetorial (de Matrizes) de Duas Matrizes Alocadas Dinamicamente ---

void exercicio10_produtoMatrizesDinamicasPrograma() {
    printf("\n--- Exercicio 10: Produto de Matrizes Dinamicas ---\n");

    int** matriz_d_a = NULL;
    int** matriz_d_b = NULL;
    int** matriz_d_produto = NULL;
    int linhas_a, colunas_a, linhas_b, colunas_b;

    // --- Matriz 1 ---
    printf("\n--- Configuracao da Primeira Matriz ---\n");
    printf("Digite o numero de linhas para a Matriz 1: ");
    while (scanf("%d", &linhas_a) != 1 || linhas_a <= 0) {
        printf("Entrada invalida. Digite um numero inteiro positivo para as linhas: ");
        while (getchar() != '\n'); // Limpa o buffer de entrada
    }
    printf("Digite o numero de colunas para a Matriz 1: ");
    while (scanf("%d", &colunas_a) != 1 || colunas_a <= 0) {
        printf("Entrada invalida. Digite um numero inteiro positivo para as colunas: ");
        while (getchar() != '\n'); // Limpa o buffer de entrada
    }

    matriz_d_a = exercicio6_alocarMatrizDinamica(linhas_a, colunas_a);
    if (matriz_d_a == NULL) {
        return; // Sai se a alocação falhar
    }
    exercicio8_preencherMatrizDinamica(matriz_d_a, linhas_a, colunas_a);
    exercicio9_imprimirMatrizDinamica(matriz_d_a, linhas_a, colunas_a);

    // --- Matriz 2 ---
    printf("\n--- Configuracao da Segunda Matriz ---\n");
    printf("Digite o numero de linhas para a Matriz 2: ");
    while (scanf("%d", &linhas_b) != 1 || linhas_b <= 0) {
        printf("Entrada invalida. Digite um numero inteiro positivo para as linhas: ");
        while (getchar() != '\n');
    }
    printf("Digite o numero de colunas para a Matriz 2: ");
    while (scanf("%d", &colunas_b) != 1 || colunas_b <= 0) {
        printf("Entrada invalida. Digite um numero inteiro positivo para as colunas: ");
        while (getchar() != '\n');
    }

    matriz_d_b = exercicio6_alocarMatrizDinamica(linhas_b, colunas_b);
    if (matriz_d_b == NULL) {
        exercicio7_liberarMatrizDinamica(matriz_d_a, linhas_a); // Libera a primeira matriz antes de sair
        return;
    }
    exercicio8_preencherMatrizDinamica(matriz_d_b, linhas_b, colunas_b);
    exercicio9_imprimirMatrizDinamica(matriz_d_b, linhas_b, colunas_b);

    // --- Realizar o produto das matrizes ---
    printf("\n--- Realizando o Produto das Matrizes A x B ---\n");
    if (_produtoMatrizesDinamicas(matriz_d_a, linhas_a, colunas_a,
                                  matriz_d_b, linhas_b, colunas_b,
                                  &matriz_d_produto)) {
        printf("Produto das Matrizes A x B:\n");
        exercicio9_imprimirMatrizDinamica(matriz_d_produto, linhas_a, colunas_b);
    } else {
        printf("Nao foi possivel calcular o produto das matrizes.\n");
    }

    // --- Liberar as matrizes ---
    printf("\n--- Liberando as Matrizes Alocadas Dinamicamente ---\n");
    exercicio7_liberarMatrizDinamica(matriz_d_a, linhas_a);
    exercicio7_liberarMatrizDinamica(matriz_d_b, linhas_b);
    if (matriz_d_produto != NULL) { // Só libera se foi alocada
        exercicio7_liberarMatrizDinamica(matriz_d_produto, linhas_a);
    }
}

