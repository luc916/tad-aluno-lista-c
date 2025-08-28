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
void removerUltimo(Lista* l);
void imprimirLista(const Lista* l);
void liberarLista(Lista* l);

#endif
