#include <stdio.h>
#include <stdlib.h)
#include <string.h>
#include <math.h>
#include <time.h>

// Protótipos das funções dos exercícios
void exercicio1(int argc, char *argv[]);
int ehPrimo(int num);
void exercicio2();
double arredondar(double valor, int casas);
void exercicio3();
void exercicio4();
void exercicio5();

int main(int argc, char *argv[]) {
    int opcao;

    do {
        printf("\n--- Menu de Exercícios ---\n");
        printf("1. Números Primos em um Intervalo (requer args de linha de comando)\n");
        printf("2. Arredondar Valor\n");
        printf("3. Gerar Cartelas de BINGO\n");
        printf("4. Soma de Matrizes de Arquivo\n");
        printf("5. Lanchonete (Menu Interativo)\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\n--- Exercício 1: Números Primos em um Intervalo ---\n");
                // A função principal 'main' recebe os argumentos da linha de comando
                exercicio1(argc, argv);
                break;
            case 2:
                printf("\n--- Exercício 2: Arredondar Valor ---\n");
                exercicio2();
                break;
            case 3:
                printf("\n--- Exercício 3: Gerar Cartelas de BINGO ---\n");
                exercicio3();
                break;
            case 4:
                printf("\n--- Exercício 4: Soma de Matrizes de Arquivo ---\n");
                exercicio4();
                break;
            case 5:
                printf("\n--- Exercício 5: Lanchonete (Menu Interativo) ---\n");
                exercicio5();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}

/*
 * -------------------------------------------------------------------
 * Exercício 1: Escreva um programa que receba de argumento, dois
 * números (inicio e fim) e imprima todos os números primos nesse
 * [cite_start]intervalo. [cite: 2]
 * -------------------------------------------------------------------
 */
void exercicio1(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Uso: ./programa <inicio> <fim> (executado via linha de comando na compilação)\n");
        printf("Ou selecione a opção 1 no menu e ignore esta mensagem se já passou os argumentos.\n");
        return;
    }

    int inicio = atoi(argv[1]);
    int fim = atoi(argv[2]);

    printf("Números primos entre %d e %d:\n", inicio, fim);
    for (int i = inicio; i <= fim; ++i) {
        if (ehPrimo(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int ehPrimo(int num) {
    if (num <= 1) return 0; // 0 e 1 não são primos
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

/*
 * -------------------------------------------------------------------
 * Exercício 2: Faça uma função para arredondar valor para dada casas.
 * Se casas não for fornecido, arredonde para 0 casas decimais
 * [cite_start](casas = 0). [cite: 3, 4]
 * -------------------------------------------------------------------
 */
void exercicio2() {
    double valor;
    int casas;
    char buffer[10];

    printf("Digite o valor a ser arredondado: ");
    scanf("%lf", &valor);

    printf("Digite o número de casas decimais (ou pressione Enter para 0): ");
    // Limpa o buffer de entrada antes de ler a string
    while(getchar() != '\n');
    fgets(buffer, sizeof(buffer), stdin);

    if (buffer[0] == '\n' || buffer[0] == '\0') {
        casas = 0; // Valor padrão se nada for digitado
    } else {
        casas = atoi(buffer);
    }

    double resultado = arredondar(valor, casas);
    printf("Valor arredondado: %.*f\n", casas, resultado);
}

double arredondar(double valor, int casas) {
    double fator = pow(10.0, casas);
    return round(valor * fator) / fator;
}

/*
 * -------------------------------------------------------------------
 * Exercício 3: Crie um programa que gere cartelas de BINGO no
 * formato .csv, onde cada linha é uma cartela com 5 números únicos
 * [cite_start]por coluna (B-I-N-G-O). [cite: 5]
 * [cite_start]Coluna B: números 1-15 [cite: 6]
 * [cite_start]Coluna I: números 16-30 [cite: 7]
 * [cite_start]Coluna N: números 31-45 (com um espaço livre no meio, "FREE") [cite: 8]
 * [cite_start]Coluna G: números 46-60 [cite: 9]
 * [cite_start]Coluna O: números 61-75 [cite: 10]
 * -------------------------------------------------------------------
 */
void exercicio3() {
    int n_cartelas;
    printf("Digite o número de cartelas de BINGO a serem geradas: ");
    scanf("%d", &n_cartelas);

    FILE *arquivo = fopen("bingo.csv", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo bingo.csv\n");
        return;
    }

    srand(time(NULL));
    fprintf(arquivo, "B,I,N,G,O\n"); // Cabeçalho do CSV

    for (int c = 0; c < n_cartelas; ++c) {
        int cartela[5][5];
        int numeros[15];

        // Colunas B, I, N, G, O
        int inicios[] = {1, 16, 31, 46, 61};

        for (int j = 0; j < 5; ++j) { // Para cada coluna
            // Preenche o array com os números possíveis para a coluna
            for (int i = 0; i < 15; ++i) {
                numeros[i] = inicios[j] + i;
            }

            // Embaralha os números
            for (int i = 0; i < 15; ++i) {
                int temp = numeros[i];
                int randomIndex = rand() % 15;
                numeros[i] = numeros[randomIndex];
                numeros[randomIndex] = temp;
            }

            // Seleciona os 5 primeiros números embaralhados para a coluna
            for (int i = 0; i < 5; ++i) {
                cartela[i][j] = numeros[i];
            }
        }

        // Imprime a cartela no arquivo CSV
        for (int i = 0; i < 5; ++i) {
            if (i > 0) {
                 fprintf(arquivo, ",,,,,\n"); // Linha em branco entre as linhas da mesma cartela para espaçamento visual
            }
            for (int j = 0; j < 5; ++j) {
                if (i == 2 && j == 2) {
                    fprintf(arquivo, "FREE");
                } else {
                    fprintf(arquivo, "%d", cartela[i][j]);
                }
                if (j < 4) {
                    fprintf(arquivo, ",");
                }
            }
            fprintf(arquivo, "\n");
        }
        fprintf(arquivo, "\n"); // Linha em branco entre cartelas
    }

    fclose(arquivo);
    printf("%d cartela(s) de BINGO gerada(s) em 'bingo.csv'.\n", n_cartelas);
}

/*
 * -------------------------------------------------------------------
 * Exercício 4: Faça um programa que calcule a soma de duas matrizes
 * quadradas de inteiros que são passadas em um arquivo matriz.txt, a
 * [cite_start]primeira linha do arquivo indica as dimensões da matriz. [cite: 11]
 * -------------------------------------------------------------------
 */
void exercicio4() {
    FILE *arquivo = fopen("matriz.txt", "r");
    if (arquivo == NULL) {
        printf("Erro: Arquivo 'matriz.txt' não encontrado.\n");
        printf("Crie o arquivo 'matriz.txt' com o seguinte formato:\n");
        printf("Dimensao\n");
        printf("elementos da matriz 1...\n");
        printf("elementos da matriz 2...\n");
        return;
    }

    int dim;
    fscanf(arquivo, "%d", &dim);

    int matriz1[dim][dim], matriz2[dim][dim], soma[dim][dim];

    // Leitura da primeira matriz
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            fscanf(arquivo, "%d", &matriz1[i][j]);
        }
    }

    // Leitura da segunda matriz
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            fscanf(arquivo, "%d", &matriz2[i][j]);
        }
    }

    fclose(arquivo);

    // Cálculo da soma
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            soma[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }

    // Impressão da matriz resultante
    printf("Matriz Soma:\n");
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            printf("%d\t", soma[i][j]);
        }
        printf("\n");
    }
}


/*
 * -------------------------------------------------------------------
 * Exercício 5: Faça um menu interativo que leia o menu no menu.txt e
 * [cite_start]imprima o boleto de um pedido de lanchonete num boleto.txt. [cite: 12]
 * Dica: Coloque a quantidade de itens do menu na primeira linha de
 * [cite_start]menu.txt). rewind(f) permite recomeçar a leitura de um arquivo. [cite: 14, 15]
 * -------------------------------------------------------------------
 */
void exercicio5() {
    FILE *menu_file = fopen("menu.txt", "r");
    if (menu_file == NULL) {
        printf("Erro: Arquivo 'menu.txt' não encontrado.\n");
        printf("Crie o arquivo 'menu.txt' com o seguinte formato:\n");
        printf("NumeroDeItens\n");
        printf("Nome do Item 1 Preco1\n");
        printf("Nome_do_Item_2 Preco2\n");
        // ...
        return;
    }

    int num_itens;
    fscanf(menu_file, "%d\n", &num_itens);

    char nomes[num_itens][50];
    float precos[num_itens];
    int pedidos[num_itens];
    for(int i = 0; i < num_itens; ++i) pedidos[i] = 0;


    int opcao, quantidade;
    float total = 0.0;

    do {
        // rewind para reler o menu a cada iteração
        rewind(menu_file);
        fscanf(menu_file, "%d\n", &num_itens); // Pula a primeira linha

        printf("\n--- Menu Lanchonete ---\n");
        for (int i = 0; i < num_itens; ++i) {
            fscanf(menu_file, "%s %f\n", nomes[i], &precos[i]);
            printf("%d. %s - R$%.2f\n", i + 1, nomes[i], precos[i]);
        }
        printf("0. Finalizar Pedido\n");
        printf("Escolha um item: ");
        scanf("%d", &opcao);

        if (opcao > 0 && opcao <= num_itens) {
            printf("Digite a quantidade: ");
            scanf("%d", &quantidade);
            pedidos[opcao - 1] += quantidade;
            total += precos[opcao - 1] * quantidade;
            printf("Adicionado ao pedido!\n");
        } else if (opcao != 0) {
            printf("Opção inválida!\n");
        }

    } while (opcao != 0);

    fclose(menu_file);

    // Gerar boleto.txt
    FILE *boleto_file = fopen("boleto.txt", "w");
    if (boleto_file == NULL) {
        printf("Erro ao criar o arquivo boleto.txt\n");
        return;
    }

    fprintf(boleto_file, "--- BOLETO LANCHONETE ---\n\n");
    fprintf(boleto_file, "Item\t\tQtd\tPreço Unit.\tSubtotal\n");
    fprintf(boleto_file, "--------------------------------------------------\n");

    for (int i = 0; i < num_itens; ++i) {
        if (pedidos[i] > 0) {
            fprintf(boleto_file, "%-15s\t%d\tR$ %.2f\t\tR$ %.2f\n",
                    nomes[i], pedidos[i], precos[i], precos[i] * pedidos[i]);
        }
    }

    fprintf(boleto_file, "\n--------------------------------------------------\n");
    fprintf(boleto_file, "TOTAL DO PEDIDO: R$ %.2f\n", total);
    fclose(boleto_file);

    printf("Pedido finalizado. O 'boleto.txt' foi gerado.\n");
}
