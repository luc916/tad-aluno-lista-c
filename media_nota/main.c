#include <stdio.h>
#include "aluno.h"
int main() {
    Aluno a1 = criarAluno("Maria", 559087, 10.0);
    Aluno a2 = criarAluno("Joao", 558761, 8.0);
    imprimirAluno(a1);
    imprimirAluno(a2);

    Lista listaDeAlunos;
    criarLista(&listaDeAlunos);
    inserirAlunoNaLista(&listaDeAlunos, a1);
    inserirAlunoNaLista(&listaDeAlunos, a2);

    float media = calcularMedia(&listaDeAlunos);
    printf("\nA media dos alunos: %.2f\n", media);
    liberarLista(&listaDeAlunos);

    return 0;
}

