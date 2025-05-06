#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    clock_t inicio, fim;
    double segs;
    if (argc <= 1) {
        printf("Passe como parâmetro o numero de elementos do vetor\n");
        exit(1);
    }
    int n = atoi(argv[1]);
    int *inteiros = malloc(n * sizeof(int));
    printf("Criando vetor de %d (%g) inteiros\n", n, (double)n);
    inicio = clock(); // Marca o tempo de início
    // Coloque aqui o algoritmo que você quer medir
    for (int i = 0; i < n; i++)
        inteiros[i] = rand(); // Cria vetor de inteiros aleatórios
    fim = clock(); // Marca o tempo final
    // Calcula o tempo decorrido em segundos
    segs = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo de execucao: %f seconds\n", segs);
    return 0;
}
