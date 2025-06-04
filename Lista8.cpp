// 1. Peça ao usuário um número n, aloque um vetor de inteiros com n posições,
//    preencha com valores sequenciais e imprima.
void exercicio1() {
    int n;
    std::cout << "Digite o número de posições (n): ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "O número de posições deve ser positivo." << std::endl;
        return;
    }

    int* vetor = new int[n]; // Alocação dinâmica

    for (int i = 0; i < n; ++i) {
        vetor[i] = i + 1; // Preenchendo com valores sequenciais (1, 2, ..., n)
    }

    imprimirVetor(vetor, n, "Vetor Ex1");

    delete[] vetor; // Liberação da memória alocada
    vetor = nullptr; // Boa prática para evitar dangling pointers
}

// 2. Faça um programa que armazene todos os valores de um vetor passado pelo
//    usuário. Peça ao usuário um número n, inicialmente, que representa quantos
//    números serão armazenados.
void exercicio2() {
    int n;
    std::cout << "Digite quantos números serão armazenados (n): ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "O número de elementos deve ser positivo." << std::endl;
        return;
    }

    int* vetor = new int[n]; // Alocação dinâmica

    std::cout << "Digite os " << n << " números:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << "Elemento " << i + 1 << ": ";
        std::cin >> vetor[i];
    }

    imprimirVetor(vetor, n, "Vetor Ex2");

    delete[] vetor; // Liberação da memória alocada
    vetor = nullptr;
}

// 3. Repita o exercício anterior, mas dessa vez o valor '-1' define que não haverá mais
//    valores a serem armazenados no vetor (para tal, use o realloc).
//    Nota: C++ não tem 'realloc' para memória alocada com 'new[]'.
//    Vamos simular o comportamento de 'realloc' manualmente.
void exercicio3() {
    int capacidade = 2; // Capacidade inicial
    int* vetor = new int[capacidade];
    int tamanho = 0;
    int valor;

    std::cout << "Digite os números um por um (digite -1 para parar):" << std::endl;

    while (true) {
        std::cout << "Valor: ";
        std::cin >> valor;

        if (valor == -1) {
            break;
        }

        // Se o vetor está cheio, redimensiona (simulando realloc)
        if (tamanho == capacidade) {
            int novaCapacidade = capacidade * 2; // Dobra a capacidade
            if (novaCapacidade == 0) novaCapacidade = 1; // Caso capacidade inicial seja 0
            
            int* novoVetor = new int[novaCapacidade];
            for (int i = 0; i < tamanho; ++i) {
                novoVetor[i] = vetor[i];
            }
            delete[] vetor; // Libera o vetor antigo
            vetor = novoVetor; // Aponta para o novo vetor
            capacidade = novaCapacidade;
            // std::cout << "(Vetor redimensionado para capacidade " << capacidade << ")" << std::endl;
        }

        vetor[tamanho] = valor;
        tamanho++;
    }

    imprimirVetor(vetor, tamanho, "Vetor Ex3");

    delete[] vetor; // Liberação da memória alocada
    vetor = nullptr;
}

// 4. Dado um vetor dinâmico V de n inteiros, crie uma função que retorne um novo vetor
//    S alocado dinamicamente que contenha apenas os elementos pares de V.
int* exercicio4_funcao(const int* V, int n_v, int& tamanho_S) {
    if (V == nullptr || n_v <= 0) {
        tamanho_S = 0;
        return nullptr;
    }

    // Contar quantos elementos pares existem em V
    int contadorPares = 0;
    for (int i = 0; i < n_v; ++i) {
        if (V[i] % 2 == 0) {
            contadorPares++;
        }
    }

    if (contadorPares == 0) {
        tamanho_S = 0;
        return nullptr; // Nenhum elemento par
    }

    // Alocar o vetor S com o tamanho exato dos elementos pares
    int* S = new int[contadorPares];
    tamanho_S = contadorPares;

    // Preencher S com os elementos pares de V
    int indice_S = 0;
    for (int i = 0; i < n_v; ++i) {
        if (V[i] % 2 == 0) {
            S[indice_S] = V[i];
            indice_S++;
        }
    }
    return S;
}

void exercicio4() {
    int n_v;
    std::cout << "Digite o tamanho do vetor V: ";
    std::cin >> n_v;

    if (n_v <= 0) {
        std::cout << "Tamanho inválido para o vetor V." << std::endl;
        return;
    }

    int* V = new int[n_v];
    std::cout << "Digite os " << n_v << " elementos do vetor V:" << std::endl;
    for (int i = 0; i < n_v; ++i) {
        std::cout << "V[" << i << "]: ";
        std::cin >> V[i];
    }

    imprimirVetor(V, n_v, "Vetor V (Original)");

    int tamanho_S = 0;
    int* S = exercicio4_funcao(V, n_v, tamanho_S);

    if (S != nullptr) {
        imprimirVetor(S, tamanho_S, "Vetor S (Pares)");
        delete[] S; // Liberar S
        S = nullptr;
    } else {
        std::cout << "Nenhum elemento par encontrado ou vetor V inválido, vetor S não foi criado." << std::endl;
    }

    delete[] V; // Liberar V
    V = nullptr;
}


// 5. Simule uma matriz 3x3 preenchida com 0, usando um único vetor alocado
//    dinamicamente. Imprima o vetor no formato de matriz.
void exercicio5() {
    const int LINHAS = 3;
    const int COLUNAS = 3;
    const int TAMANHO_TOTAL = LINHAS * COLUNAS;

    // Aloca um único vetor para simular a matriz
    int* matriz_vetor = new int[TAMANHO_TOTAL];

    // Preenche com 0
    for (int i = 0; i < TAMANHO_TOTAL; ++i) {
        matriz_vetor[i] = 0;
    }

    std::cout << "Matriz 3x3 simulada (preenchida com 0s):" << std::endl;
    for (int i = 0; i < LINHAS; ++i) {
        for (int j = 0; j < COLUNAS; ++j) {
            // Acesso ao elemento (i, j) como matriz_vetor[i * COLUNAS + j]
            std::cout << std::setw(3) << matriz_vetor[i * COLUNAS + j] << " ";
        }
        std::cout << std::endl;
    }
    
    // Imprime o vetor original para demonstrar o armazenamento
    // imprimirVetor(matriz_vetor, TAMANHO_TOTAL, "Vetor da Matriz Ex5");


    delete[] matriz_vetor; // Liberação da memória alocada
    matriz_vetor = nullptr;
}


