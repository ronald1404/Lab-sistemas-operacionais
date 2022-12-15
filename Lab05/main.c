// #include "Circular.h"
#include "Escalonador.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    Escalonador escalonador;
    FLVazia(&escalonador);
    Processo p;

    p.Prioridade = 4;
    p.Tempo = 200;
    Insere(p, &escalonador);

    p.Prioridade = 1;
    p.Tempo = 300;
    Insere(p, &escalonador);

    p.Prioridade = 2;
    p.Tempo = 25;
    Insere(p, &escalonador);

    float time_slice = 10;
    while(!Vazia(escalonador)){
        for (int i = escalonador.Primeiro; i < escalonador.Ultimo; i++){
            if ((escalonador.processos[i].Tempo) - time_slice <= 0){
            printf("P%d, %0.2f*\n",escalonador.processos[i].id, escalonador.processos[i].Tempo );
            Retira(i,&escalonador,&p);
        }
            else{
            printf("P%d, %0.2f\n",escalonador.processos[i].id, escalonador.processos[i].Tempo);
            escalonador.processos[i].Tempo -= time_slice;

            }
        }
    }
    return 0;
}
