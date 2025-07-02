#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- Estruturas e Protótipos para o Exercício 1 e 2 ---
typedef struct {
    char nome[100];
    float nota_exercicios;
    float prova1;
    float prova2;
} Aluno;

typedef struct {
    Aluno* alunos;
    int quantidade;
    int capacidade;
} ListaAlunos;

float calcular_media_final(Aluno aluno); [cite_start]// [cite: 17]
void exercicio1();
ListaAlunos* criar_lista_alunos(int capacidade_inicial);
void adicionar_aluno(ListaAlunos* lista, Aluno aluno);
void imprimir_medias_lista(ListaAlunos* lista); [cite_start]// [cite: 18]
void liberar_lista_alunos(ListaAlunos* lista);
void exercicio2();

// --- Estruturas e Protótipos para o Exercício 3 ---
typedef struct NoMatriz {
    int valor;
    int linha;
    int coluna;
    struct NoMatriz* proximo;
} NoMatriz;

typedef struct {
    NoMatriz* cabeca;
    int linhas;
    int colunas;
} MatrizNos;

MatrizNos* criar_matriz_nos(int linhas, int colunas);
void definir_valor_matriz(MatrizNos* matriz, int linha, int coluna, int valor);
int obter_valor_matriz(MatrizNos* matriz, int linha, int coluna);
void imprimir_matriz_nos(MatrizNos* matriz);
void liberar_matriz_nos(MatrizNos* matriz);
void exercicio3(); [cite_start]// [cite: 19]

// --- Estruturas e Protótipos para o Exercício 4 ---
typedef struct {
    int parte_inteira;
    int parte_decimal; // Armazenar como um inteiro (ex: 0.1234 é armazenado como 1234)
} Decimal4Casas; [cite_start]// [cite: 20]

Decimal4Casas somar_decimais(Decimal4Casas d1, Decimal4Casas d2); [cite_start]// [cite: 20]
Decimal4Casas subtrair_decimais(Decimal4Casas d1, Decimal4Casas d2); [cite_start]// [cite: 20]
void imprimir_decimal(Decimal4Casas d); [cite_start]// [cite: 20]
void exercicio4();

// --- Estruturas e Protótipos para o Exercício 5 ---
typedef struct {
    char nome[50];
    float preco;
} Produto; [cite_start]// [cite: 21]

typedef struct {
    Produto* itens;
    int quantidade_itens;
} Menu; [cite_start]// [cite: 21]

Produto inicializar_produto(const char* nome, float preco); [cite_start]// [cite: 21]
Menu* carregar_menu_do_arquivo(const char* nome_arquivo);
void liberar_menu(Menu* menu);
void exercicio5();

// --- Função Principal (Menu de Exercícios) ---
int main() {
    int opcao;
    do {
        printf("\n--- Menu de Exercícios 12 ---\n");
        printf("1. Calcular Média Final do Aluno\n");
        printf("2. Calcular Média de uma Lista de Alunos\n");
        printf("3. Matrizes com Lógica de Nós\n");
        printf("4. Operações com Números Decimais (Struct)\n");
        printf("5. Menu Interativo com Structs\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer de entrada

        switch (opcao) {
            case 1: exercicio1(); break;
            case 2: exercicio2(); break;
            case 3: exercicio3(); break;
            case 4: exercicio4(); break;
            case 5: exercicio5(); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opção inválida!\n"); break;
        }
    } while (opcao != 0);
    return 0;
}

// --- Implementação do Exercício 1 ---
/*
 * 1. Faça uma struct para alunos que permita o professor registrar notas e faça uma
 * função que permita calcular a média final (20% nota de exercícios e 80% notas de
 * [cite_start]duas provas, uma com peso 4 e outra com peso 6). [cite: 17]
 */
float calcular_media_final(Aluno aluno) {
    float media_provas = (aluno.prova1 * 4 + aluno.prova2 * 6) / 10.0f;
    float media_final = (aluno.nota_exercicios * 0.2f) + (media_provas * 0.8f);
    return media_final;
}

void exercicio1() {
    printf("\n--- Exercício 1: Média Final do Aluno ---\n");
    Aluno a1;
    printf("Digite o nome do aluno: ");
    fgets(a1.nome, 100, stdin);
    a1.nome[strcspn(a1.nome, "\n")] = 0; // Remove a nova linha

    printf("Digite a nota dos exercícios: ");
    scanf("%f", &a1.nota_exercicios);
    printf("Digite a nota da Prova 1 (peso 4): ");
    scanf("%f", &a1.prova1);
    printf("Digite a nota da Prova 2 (peso 6): ");
    scanf("%f", &a1.prova2);

    float media = calcular_media_final(a1);
    printf("\nA média final do aluno %s é: %.2f\n", a1.nome, media);
}


// --- Implementação do Exercício 2 ---
/*
 * 2. Faça uma struct para lista de alunos (dica: adapte o exemplo da aula) e uma função
 * [cite_start]que calcule e imprima a média de cada aluno. [cite: 18]
 */
ListaAlunos* criar_lista_alunos(int capacidade_inicial) {
    ListaAlunos* lista = (ListaAlunos*) malloc(sizeof(ListaAlunos));
    lista->alunos = (Aluno*) malloc(capacidade_inicial * sizeof(Aluno));
    lista->quantidade = 0;
    lista->capacidade = capacidade_inicial;
    return lista;
}

void adicionar_aluno(ListaAlunos* lista, Aluno aluno) {
    if (lista->quantidade == lista->capacidade) {
        lista->capacidade *= 2;
        lista->alunos = (Aluno*) realloc(lista->alunos, lista->capacidade * sizeof(Aluno));
    }
    lista->alunos[lista->quantidade++] = aluno;
}

void imprimir_medias_lista(ListaAlunos* lista) {
    printf("\n--- Média dos Alunos ---\n");
    for (int i = 0; i < lista->quantidade; i++) {
        float media = calcular_media_final(lista->alunos[i]);
        printf("Aluno: %s | Média Final: %.2f\n", lista->alunos[i].nome, media);
    }
}

void liberar_lista_alunos(ListaAlunos* lista) {
    free(lista->alunos);
    free(lista);
}

void exercicio2() {
    printf("\n--- Exercício 2: Média de uma Lista de Alunos ---\n");
    ListaAlunos* turma = criar_lista_alunos(2);

    Aluno a1 = {"Joao Silva", 8.0, 7.0, 7.5};
    Aluno a2 = {"Maria Souza", 9.0, 8.5, 9.0};
    Aluno a3 = {"Pedro Costa", 5.0, 4.0, 6.0};

    adicionar_aluno(turma, a1);
    adicionar_aluno(turma, a2);
    adicionar_aluno(turma, a3);

    imprimir_medias_lista(turma);
    liberar_lista_alunos(turma);
}

// --- Implementação do Exercício 3 ---
/*
 * [cite_start]3. Faça uma struct para representar matrizes de inteiros pela lógica de nós. [cite: 19]
 */
MatrizNos* criar_matriz_nos(int linhas, int colunas) {
    MatrizNos* matriz = (MatrizNos*) malloc(sizeof(MatrizNos));
    matriz->cabeca = NULL;
    matriz->linhas = linhas;
    matriz->colunas = colunas;
    return matriz;
}

void definir_valor_matriz(MatrizNos* matriz, int linha, int coluna, int valor) {
    if (linha >= matriz->linhas || coluna >= matriz->colunas) return;
    if (valor == 0) return; // Otimização: não armazenar zeros

    NoMatriz* novoNo = (NoMatriz*) malloc(sizeof(NoMatriz));
    novoNo->linha = linha;
    novoNo->coluna = coluna;
    novoNo->valor = valor;
    novoNo->proximo = matriz->cabeca;
    matriz->cabeca = novoNo;
}

int obter_valor_matriz(MatrizNos* matriz, int linha, int coluna) {
    NoMatriz* atual = matriz->cabeca;
    while (atual != NULL) {
        if (atual->linha == linha && atual->coluna == coluna) {
            return atual->valor;
        }
        atual = atual->proximo;
    }
    return 0; // Valor padrão se não encontrado
}

void imprimir_matriz_nos(MatrizNos* matriz) {
    printf("\nMatriz %dx%d (Lógica de Nós):\n", matriz->linhas, matriz->colunas);
    for (int i = 0; i < matriz->linhas; i++) {
        for (int j = 0; j < matriz->colunas; j++) {
            printf("%d\t", obter_valor_matriz(matriz, i, j));
        }
        printf("\n");
    }
}

void liberar_matriz_nos(MatrizNos* matriz) {
    NoMatriz* atual = matriz->cabeca;
    while (atual != NULL) {
        NoMatriz* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    free(matriz);
}

void exercicio3() {
    printf("\n--- Exercício 3: Matrizes com Lógica de Nós ---\n");
    MatrizNos* m = criar_matriz_nos(3, 3);
    definir_valor_matriz(m, 0, 0, 5);
    definir_valor_matriz(m, 1, 1, 9);
    definir_valor_matriz(m, 2, 2, 3);
    definir_valor_matriz(m, 0, 2, 1);

    imprimir_matriz_nos(m);
    liberar_matriz_nos(m);
}

// --- Implementação do Exercício 4 ---
/*
 * 4. Usando int, faça uma struct para representar números decimais com até 4 casas e
 * [cite_start]faça funções para somar, subtrair e imprimir o valor. [cite: 20]
 */
Decimal4Casas somar_decimais(Decimal4Casas d1, Decimal4Casas d2) {
    Decimal4Casas resultado;
    long total1 = d1.parte_inteira * 10000L + d1.parte_decimal;
    long total2 = d2.parte_inteira * 10000L + d2.parte_decimal;
    long soma_total = total1 + total2;

    resultado.parte_inteira = soma_total / 10000;
    resultado.parte_decimal = soma_total % 10000;
    return resultado;
}

Decimal4Casas subtrair_decimais(Decimal4Casas d1, Decimal4Casas d2) {
    Decimal4Casas resultado;
    long total1 = d1.parte_inteira * 10000L + d1.parte_decimal;
    long total2 = d2.parte_inteira * 10000L + d2.parte_decimal;
    long sub_total = total1 - total2;

    resultado.parte_inteira = sub_total / 10000;
    resultado.parte_decimal = sub_total % 10000;
    // Lida com resultado negativo
    if (sub_total < 0 && resultado.parte_inteira == 0) {
       resultado.parte_decimal = -resultado.parte_decimal;
    }
    return resultado;
}

void imprimir_decimal(Decimal4Casas d) {
    // Tratamento para números negativos
    if (d.parte_inteira < 0 || (d.parte_inteira == 0 && d.parte_decimal < 0)) {
         printf("-%d.%04d", abs(d.parte_inteira), abs(d.parte_decimal));
    } else {
         printf("%d.%04d", d.parte_inteira, d.parte_decimal);
    }
}


void exercicio4() {
    printf("\n--- Exercício 4: Operações com Números Decimais (Struct) ---\n");
    Decimal4Casas num1 = {10, 5000}; // 10.5000
    Decimal4Casas num2 = {5, 2550};  //  5.2550

    printf("Número 1: "); imprimir_decimal(num1); printf("\n");
    printf("Número 2: "); imprimir_decimal(num2); printf("\n");

    Decimal4Casas soma = somar_decimais(num1, num2);
    printf("Soma: "); imprimir_decimal(soma); printf("\n");

    Decimal4Casas subtracao = subtrair_decimais(num1, num2);
    printf("Subtração (1-2): "); imprimir_decimal(subtracao); printf("\n");

    Decimal4Casas num3 = {3, 1000};
    Decimal4Casas num4 = {8, 9000};
    Decimal4Casas subtracao2 = subtrair_decimais(num3, num4);
    printf("\nSubtração (3-4): "); imprimir_decimal(subtracao2); printf("\n");
}


// --- Implementação do Exercício 5 ---
/*
 * 5. Adapte o menu interativo feito na lista de exercícios anterior e crie uma struct menu
 * com uma lista de uma struct produto, crie uma função para inicializar um produto e
 * [cite_start]atualize o exercício. [cite: 21]
 */
Produto inicializar_produto(const char* nome, float preco) {
    Produto p;
    strncpy(p.nome, nome, 49);
    p.nome[49] = '\0';
    p.preco = preco;
    return p;
}

Menu* carregar_menu_do_arquivo(const char* nome_arquivo) {
    FILE* file = fopen(nome_arquivo, "r");
    if (!file) return NULL;

    Menu* menu = (Menu*) malloc(sizeof(Menu));
    fscanf(file, "%d\n", &menu->quantidade_itens);

    menu->itens = (Produto*) malloc(menu->quantidade_itens * sizeof(Produto));
    char nome_temp[50];
    float preco_temp;
    for (int i = 0; i < menu->quantidade_itens; i++) {
        fscanf(file, "%s %f\n", nome_temp, &preco_temp);
        menu->itens[i] = inicializar_produto(nome_temp, preco_temp);
    }
    fclose(file);
    return menu;
}

void liberar_menu(Menu* menu) {
    if(menu) {
        free(menu->itens);
        free(menu);
    }
}

void exercicio5() {
    printf("\n--- Exercício 5: Menu Interativo com Structs ---\n");
    // Criar um arquivo menu.txt de exemplo
    FILE* f = fopen("menu_ex5.txt", "w");
    if (f) {
        fprintf(f, "4\n");
        fprintf(f, "X-Burger 18.50\n");
        fprintf(f, "X-Salada 20.00\n");
        fprintf(f, "Batata-Frita 12.00\n");
        fprintf(f, "Refrigerante 5.50\n");
        fclose(f);
    }

    Menu* menu = carregar_menu_do_arquivo("menu_ex5.txt");
    if (!menu) {
        printf("Erro: Arquivo 'menu_ex5.txt' não encontrado ou em formato inválido.\n");
        return;
    }

    int* pedidos = (int*) calloc(menu->quantidade_itens, sizeof(int));
    int opcao, quantidade;
    float total = 0.0;

    do {
        printf("\n--- Menu Lanchonete (Struct) ---\n");
        for (int i = 0; i < menu->quantidade_itens; i++) {
            printf("%d. %s - R$%.2f\n", i + 1, menu->itens[i].nome, menu->itens[i].preco);
        }
        printf("0. Finalizar Pedido\n");
        printf("Escolha um item: ");
        scanf("%d", &opcao);

        if (opcao > 0 && opcao <= menu->quantidade_itens) {
            printf("Digite a quantidade: ");
            scanf("%d", &quantidade);
            pedidos[opcao - 1] += quantidade;
            total += menu->itens[opcao - 1].preco * quantidade;
            printf("Adicionado!\n");
        } else if (opcao != 0) {
            printf("Opção inválida!\n");
        }

    } while (opcao != 0);

    // Gerar boleto
    FILE* boleto_file = fopen("boleto_ex5.txt", "w");
    if (!boleto_file) {
        printf("Erro ao criar o arquivo boleto_ex5.txt\n");
    } else {
        fprintf(boleto_file, "--- BOLETO LANCHONETE ---\n\n");
        for (int i = 0; i < menu->quantidade_itens; i++) {
            if (pedidos[i] > 0) {
                fprintf(boleto_file, "Produto: %s, Qtd: %d, Subtotal: R$ %.2f\n",
                        menu->itens[i].nome, pedidos[i], menu->itens[i].preco * pedidos[i]);
            }
        }
        fprintf(boleto_file, "\nTOTAL: R$ %.2f\n", total);
        fclose(boleto_file);
        printf("Pedido finalizado. 'boleto_ex5.txt' foi gerado.\n");
    }

    free(pedidos);
    liberar_menu(menu);
}
