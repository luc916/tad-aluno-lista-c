#include <stdio.h>
#include <string.h>
#include "aluno.h"
#include <stdlib.h>
Aluno criarAluno(const char *nome, int rm, float nota) {
    Aluno a;
    strncpy(a.nome, nome, sizeof(a.nome));
    a.rm = rm;
    a.nota = nota;
    return a;
}
void imprimirAluno(Aluno a) {
    printf("Nome: %s | RM: %d | Nota: %.2f\n", a.nome, a.rm, a.nota);
}

void criarLista(Lista* l) {
    l->inicio = NULL;
}

void inserirAlunoNaLista(Lista* l, Aluno a) {
    Elo* novoElo = (Elo*)malloc(sizeof(Elo));
    if (novoElo == NULL) {
        printf("Erro de alocação de memória!\n");
       return;
    }
    novoElo->aluno = a;
    novoElo->proximo = l->inicio;
    l->inicio = novoElo;
}

void liberarLista(Lista* l) {
    Elo* atual = l->inicio;
    while (atual != NULL) {
        Elo* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    l->inicio = NULL;
}

int buscarAlunoPorRM(Lista* l, int rm) {
    Elo* atual = l->inicio;
    int indice = 0;
    while (atual != NULL) {
        if (atual->aluno.rm == rm) {
            return indice; 
        }
        atual = atual->proximo;
        indice++;
    }
    return -1; 
}

