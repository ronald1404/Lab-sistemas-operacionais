#include <stdio.h>
#include <stdlib.h>

long fatorial(int);

int main()
{
    // printf("pPai: %d\n", (int)getpid());

    pid_t pid = fork();

    if (pid == 0)
    {
        pid_t pid2 = fork();
        // if (pid2 != 0 ) printf("pNeto criado: %d\n", (int)pid2);
        if (pid2 == 0)
        {
            printf("fatorial de 6 pNeto = %d\n", fatorial(6));
            // printf("pNeto terminado\n");
            exit(0);
        }
        // printf("pFilho esperando pNeto\n");
        wait(NULL);
        printf("fatorial de 5 pFilho = %d\n", fatorial(5));
        // printf("pFilho terminado\n");
        exit(0);
    }
    // printf("pPai esperando o filho terminar\n");
    wait(NULL);
    printf("fatorial de 4 pPai = %d\n", fatorial(4));
    // printf("pPai terminado\n");
    return (0);
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