#include <stdio.h>
#include "aluno.h"
int main() {
    Aluno a1 = criarAluno("Maria", 559087, 8.5);
    Aluno a2 = criarAluno("Joao", 558761, 7.0);
    imprimirAluno(a1);
    imprimirAluno(a2);

    Lista listaDeAlunos;
    criarLista(&listaDeAlunos);
    inserirAlunoNaLista(&listaDeAlunos, a1);
    inserirAlunoNaLista(&listaDeAlunos, a2);

    int rmParaBuscar = 558761;
    int indice = buscarAlunoPorRM(&listaDeAlunos, rmParaBuscar);
    if (indice != -1) {
        printf("\nAluno com RM %d encontrado no indice %d\n", rmParaBuscar, indice);
    } else {
        printf("\nAluno com RM %d nao encontrado.\n", rmParaBuscar);
    }

    int rmParaBuscar2 = 999999;
    int indice2 = buscarAlunoPorRM(&listaDeAlunos, rmParaBuscar2);
    if (indice2 != -1) {
        printf("\nAluno com RM %d encontrado no indice %d\n", rmParaBuscar2, indice2);
    } else {
        printf("\nAluno com RM %d nao encontrado.\n", rmParaBuscar2);
    }

    liberarLista(&listaDeAlunos);

    return 0;
}

