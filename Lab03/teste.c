#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	char *palavra;
	scanf("%c",palavra);
	//printf("ola %d\n",strlen(palavra));
	//printf("%c",*palavra);
	write (1,palavra,4);
}
