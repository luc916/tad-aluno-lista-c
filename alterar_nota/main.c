#include <stdio.h>
#include "aluno.h"

int main() {
    Aluno a1 = criarAluno("Maria", 559087, 8.5f);
    printf("Antes:\n");
    imprimirAluno(a1);

    alterarNota(&a1, 9.7f);
    printf("\nDepois de alterarNota:\n");
    imprimirAluno(a1);

    // (Abaixo só para manter o mesmo esqueleto de lista que o repo usa)
    Lista lista;
    criarLista(&lista);
    inserirAlunoNaLista(&lista, a1);
    liberarLista(&lista);

    return 0;
}
