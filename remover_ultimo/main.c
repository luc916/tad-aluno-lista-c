#include <stdio.h>
#include "aluno.h"

int main() {
    Aluno a1 = criarAluno("Maria", 559087, 8.5f);
    Aluno a2 = criarAluno("Joao", 558761, 7.0f);
    Aluno a3 = criarAluno("Ana", 560001, 9.3f);

    Lista lista;
    criarLista(&lista);

    // Vamos inserir no início (padrão do repo): a3 -> a2 -> a1
    inserirAlunoNaLista(&lista, a1);
    inserirAlunoNaLista(&lista, a2);
    inserirAlunoNaLista(&lista, a3);

    printf("Lista antes de removerUltimo:\n");
    imprimirLista(&lista);

    removerUltimo(&lista);
    printf("\nLista apos removerUltimo (remove 'a1'):\n");
    imprimirLista(&lista);

    // Testa remover até esvaziar
    removerUltimo(&lista);
    removerUltimo(&lista);
    printf("\nLista apos removerUltimo 2x adicionais (vazia):\n");
    imprimirLista(&lista);

    liberarLista(&lista);
    return 0;
}
