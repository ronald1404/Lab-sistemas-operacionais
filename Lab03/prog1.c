#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
int main(){
	/*
	Laboratório 03 de sistemas operacionais
	*/
	//ponteiro com dados do buffer e variável para o nome do arquivo
	char *buff, fn[10];
	int fd, n, i;
	buff = malloc(100);

	printf("Entre com o nome de um arquivo novo:\n");
	scanf("%s",fn);
	printf("\nEntre com um texto qualquer:");
	scanf("%s",buff);

	//ler o texto com o input pelo teclado
	fgets(buff,100,stdin); 
	//criar o arquivo caso não exista em modo de escrita, O nome do arquivo será o fn
	fd = open(fn,O_CREAT|O_WRONLY);
	//chamada de sistema, parêmetros: (descritor de arquivo, dados do buffer, numero de contagem de dados do buffer)
	n = write(fd,buff,strlen(buff));

	//printf("%d",fd);
	//printf("%d",n);
	// if ( n == -1) perror("Error open()");
	
	close(fd);
	free(buff);
	printf("\n\nVeja o conteúdo do arquivo criado\n");
}