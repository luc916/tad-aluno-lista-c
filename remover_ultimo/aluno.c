#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "aluno.h"

Aluno criarAluno(const char *nome, int rm, float nota) {
    Aluno a;
    strncpy(a.nome, nome, sizeof(a.nome));
    a.nome[sizeof(a.nome)-1] = '\0';
    a.rm = rm;
    a.nota = nota;
    return a;
}

void imprimirAluno(Aluno a) {
    printf("Nome: %s | RM: %d | Nota: %.2f\n", a.nome, a.rm, a.nota);
}

// ===== Lista encadeada (padrao do repo) =====
void criarLista(Lista* l) {
    l->inicio = NULL;
}

void inserirAlunoNaLista(Lista* l, Aluno a) {
    Elo* novo = (Elo*)malloc(sizeof(Elo));
    if (!novo) {
        printf("Erro de alocacao de memoria!\n");
        return;
    }
    novo->aluno = a;
    novo->proximo = l->inicio;
    l->inicio = novo;
}

void removerUltimo(Lista* l) {
    if (!l || !l->inicio) {
        // lista vazia
        return;
    }
    if (!l->inicio->proximo) {
        // só um elemento
        free(l->inicio);
        l->inicio = NULL;
        return;
    }
    // percorre até o penúltimo
    Elo* atual = l->inicio;
    while (atual->proximo && atual->proximo->proximo) {
        atual = atual->proximo;
    }
    // atual->proximo é o último
    free(atual->proximo);
    atual->proximo = NULL;
}

void imprimirLista(const Lista* l) {
    const Elo* it = l->inicio;
    int i = 0;
    while (it) {
        printf("[%d] ", i++);
        imprimirAluno(it->aluno);
        it = it->proximo;
    }
}

void liberarLista(Lista* l) {
    Elo* atual = l->inicio;
    while (atual) {
        Elo* tmp = atual;
        atual = atual->proximo;
        free(tmp);
    }
    l->inicio = NULL;
}
