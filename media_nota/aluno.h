#ifndef ALUNO_H
#define ALUNO_H
typedef struct {
    char nome[50];
    int rm;
    float nota;
} Aluno;
// Operações do TAD
Aluno criarAluno(const char *nome, int rm, float nota);
void imprimirAluno(Aluno a);
// Lista encadeada
typedef struct Elo {
    Aluno aluno;
    struct Elo* proximo;
} Elo;
typedef struct {
    Elo* inicio;
} Lista;
void criarLista(Lista* l);
void inserirAlunoNaLista(Lista* l, Aluno a);
void liberarLista(Lista* l);
float calcularMedia(Lista* l);
#endif