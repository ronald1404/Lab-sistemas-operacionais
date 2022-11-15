#include <stdio.h>
#include <stdlib.h>

int fibo(int);

int main()
{
    pid_t pid = fork();

    if (pid == 0)
    { 
        pid_t pid2 = fork();
        if (pid2 == 0){
            printf("pNeto:\n\tnNumero de fibonacci na posição 5 = %d\n",fibo(5));
            exit(0);
        }
        printf("pFilho:\n\tNumero de fibonacci na posição 4 = %d\n",fibo(4));
        wait(NULL);
        exit(0);
    }else
    printf("pPai:\n\tNumero de fibonacci na posição 3 = %d\n",fibo(3));
    
    return (0);
}

int fibo(int n){
    if (n == 1) return 1;
		int a = 0, b = 1, aux = 0;
		for(int i = 1;i < n;i++ ) {
			aux = a+b;
			a = b;
			b = aux;
		}
		return aux;
}