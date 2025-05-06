#include <stdio.h> //printf
#include <stdlib.h> //malloc

struct Noh {
    int num;
    struct Noh *prox;
};

// Inicie uma lista ligada vazia
static struct Noh *cabeca=0; // Tem que ser estática para "sobreviver" às funções

// Faça uma função que receba um inteiro, aloque memória para um nó 
// e retorne um ponteiro para este nó
struct Noh *cria_noh( int n) {
    struct Noh *p=malloc(sizeof(struct Noh));
    if (!p) {
        printf("Malloc falhou\n");
        exit(-1);
    } else {
        p->num = n;
        p->prox = 0; // Para controlar vazamento de memória
        return p;
    }
    return 0; // Nunca vai cair aqui
}

// Função que insere um elemento no início de uma lista ligada
void insere_noh(struct Noh *p){ // p aponta o elemento a ser inserido
    p->prox = cabeca; // Aponta o novo nó para o antigo cabeça
    cabeca = p; // Altera a variável estática
/* Outras soluções para este problema:
- Passar cabeca por referência para insere_noh(&cabeca). Aí fica ponteiro pra ponteiro, OU
- Passar por parâmetro, retornar o novo valor, e o chamador tem que atribuir de volta:
struct Noh * insere_noh( struct Noh *p, struct Noh *cabeca){
    ...
    return cabeca;
}
E, no chamador:
cabeca = insere_noh(p, cabeca);*/
} 

// Faça uma função que conta os nós de uma lista
int conta_nohs() {
    int n=0;
    struct Noh *p=cabeca;
    while (p) {
        ++n;
        p = p->prox;
    }
    return n;
}

// Faça uma função que insere um nó no fim de uma lista ligada
// que não tem ponteiro para a cauda
void insere_fim(struct Noh *novo) {
    struct Noh *q=cabeca, *anterior;
    while (q) { // Percorre a lista toda até o final
        anterior = q;
        q = q->prox;
    }
    // Aqui q é nulo e anterior aponta o último
    anterior->prox = novo;
    novo->prox = 0; // Já deveria vir zerado, mas não custa.
}

// Faça uma função que imprima uma lista na sequência, 
// só os números, separados por espaços e terminados por um único \n

int main(void) {
    struct Noh *no1 = cria_noh(42);
    insere_noh(no1);
    insere_noh(cria_noh(27));
    insere_noh(cria_noh(33));
    printf("A lista ligada tem %d nos\n", conta_nohs(cabeca));
    insere_fim(cria_noh(8));
    printf("A lista ligada tem %d nos\n", conta_nohs(cabeca));
}

/* Exercícios
1-Suponha que exista uma variável cauda que aponta o último de uma lista ligada
Crie uma função inserefim2() que faz a inserção no fim neste caso.
2-Quais alterações serão necessárias para manter cauda corretamente? Crie as novas funções acrescentando um 2 no nome das antigas.
3-Quais informações são necessárias para inserir um elemento no meio?
4-Reescreva as funções acima, agora para listas duplamente ligadas
*/
/*
struct Noh {
    int num;
    char *str;
    int num2
    char cpf[12]];
    struct Noh *prox;
};

struct Obj {
    int num;
    double taxa;
    char cpf[11+1];
} objeto;
*/
