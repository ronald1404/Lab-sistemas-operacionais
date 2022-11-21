#include <stdio.h>
#include <stdlib.h>

int fibo(int);
long fatorial(int);
void TorreHanoi(int, int, int, int);

int main()
{

    pid_t pid = fork();

    if (pid == 0)
    {
        pid_t pid2 = fork();
        if (pid2 == 0)
        {
            printf("pNeto, pid = %d:\n", getpid());
            TorreHanoi(0, 2, 1, 6);
            exit(0);
        }
        else
        {
            printf("pFilho, pid = %d :\n\tFatorial de 6 = %d\n", getpid(), fatorial(5));
            wait(NULL);
            exit(0);
        }
    }
    else
    {
        // printf("pPai:\n");
        printf("pPai, pid = %d :\n\tn de fibonacci = 5: %d\n", getpid(), fibo(5));
    }

    return (0);
}

int fibo(int n)
{
    if (n == 1)
        return 1;
    int a = 0, b = 1, aux = 0;
    for (int i = 1; i < n; i++)
    {
        aux = a + b;
        a = b;
        b = aux;
    }
    return aux;
}

long fatorial(int n)
{
    if (n == 1)
        return 1;
    int fat = 1;
    for (int i = n; i != 1; i--)
        fat *= i;
    return fat;
}
int count = 0;

void TorreHanoi(int origem, int destino, int auxiliar, int quantidade)
{
    if (quantidade == 1)
    {
        printf("Move de %d para %d \n ", origem, destino);
        count += 1;
    }
    else
    {
        TorreHanoi(origem, auxiliar, destino, quantidade - 1);
        TorreHanoi(origem, destino, auxiliar, 1);
        TorreHanoi(auxiliar, destino, origem, quantidade - 1);
    }
}
