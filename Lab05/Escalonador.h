#include <stdlib.h>
#include <stdio.h>
typedef struct
{
    int Prioridade;
    int id;
    float Tempo;
} Processo;

typedef struct
{
    int Primeiro, Ultimo;
    int aux;
    Processo processos[3];
} Escalonador;


void FLVazia(Escalonador *escalonador)
{
    escalonador->Primeiro = 0;
    escalonador->Ultimo = escalonador->Primeiro;
    escalonador->aux = 1;
}

int Vazia(Escalonador escalonador)
{
    return (escalonador.Primeiro == escalonador.Ultimo);
}

void Insere(Processo x, Escalonador *escalonador)
{
    if (escalonador->Ultimo > 2)
        printf("ERRO LISTA CHEIA\n");
    else
    {
        escalonador->processos[escalonador->Ultimo] = x;
        escalonador->processos[escalonador->Ultimo].id = escalonador->aux;
        escalonador->aux++;
        escalonador->Ultimo++;
    }
}

void Retira(int posicao, Escalonador *escalonador, Processo *Item)
{
    int Aux;

    if (Vazia(*escalonador) || posicao >= escalonador->Ultimo)
    {
        printf(" ERRO POSIÇÃO NÃO EXISTE\n");
        return;
    }
    *Item = escalonador->processos[posicao];
    escalonador->Ultimo--;
    for (Aux = posicao; Aux < escalonador->Ultimo; Aux++)
        escalonador->processos[Aux] = escalonador->processos[Aux + 1];
}
