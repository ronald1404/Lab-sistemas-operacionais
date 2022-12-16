#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>

#define BUFSIZE 80

float determinant(float [][25], float);
float cofactor(float [][25], float);
float transpose(float [][25], float [][25], float);

float inversaMatriz(float a[25][25])
{
  float k, d;
  int i, j;
  k = 2;

 float b[25][25], fac[25][25];
 int p, q, m, n;
 for (q = 0;q < k; q++)
 {
   for (p = 0;p < k; p++)
    {
     m = 0;
     n = 0;
     for (i = 0;i < k; i++)
     {
       for (j = 0;j < k; j++)
        {
          if (i != q && j != p)
          {
            b[m][n] = a[i][j];
            if (n < (k - 2))
             n++;
            else
             {
               n = 0;
               m++;
               }
            }
        }
      }
      fac[q][p] = pow(-1, q + p) * determinant(b, k - 1);
    }
  }

  float inverse[25][25];
  for (i = 0;i < k; i++)
    {
     for (j = 0;j < k; j++)
       {
         b[i][j] = fac[j][i];
        }
    }
  d = determinant(a, k);
  for (i = 0;i < k; i++)
    {
     for (j = 0;j < k; j++)
       {
        inverse[i][j] = b[i][j] / d;
        }
    }
    
    printf("\n\nThe original matrix is : \n");
    
    for (i = 0;i < k; i++)
    {
     for (j = 0;j < k; j++)
       {
         printf("%8.2f", a[i][j]);
        }
    printf("\n");
     }
    
   printf("\n\nThe inverse of matrix is : \n");
 
   for (i = 0;i < k; i++)
    {
     for (j = 0;j < k; j++)
       {
         printf("%8.2f", inverse[i][j]);
        }
    printf("\n");
     }
     a[0][0] = inverse[0][0];
     a[0][1] = inverse[0][1];
     a[1][0] = inverse[1][0];
     a[1][1] = inverse[1][1];
}

/*For calculating Determinant of the Matrix */
float determinant(float a[25][25], float k)
{
  float s = 1, det = 0, b[25][25];
  int i, j, m, n, c;
  if (k == 1)
    {
     return (a[0][0]);
    }
  else
    {
     det = 0;
     for (c = 0; c < k; c++)
       {
        m = 0;
        n = 0;
        for (i = 0;i < k; i++)
          {
            for (j = 0 ;j < k; j++)
              {
                b[i][j] = 0;
                if (i != 0 && j != c)
                 {
                   b[m][n] = a[i][j];
                   if (n < (k - 2))
                    n++;
                   else
                    {
                     n = 0;
                     m++;
                     }
                   }
               }
             }
          det = det + s * (a[0][c] * determinant(b, k - 1));
          s = -1 * s;
          }
    }
    return (det);
}
 
void multMatriz(float matrizA[25][25], float matrizB[25][25]){
    int i, j, linhaA, colunaA, linhaB, colunaB, x;

    float matrizC[25][25], aux = 0;
    linhaA = 2;
    colunaA = 2;
    linhaB = 2;
    colunaB = 2;

    if(colunaA == linhaB) {

	// Imprime as matrizes definidas
	printf("A⁻¹ x B⁻¹: \n\n");

	for(i = 0; i < linhaA; i++) {     
	    //printf("|");
		for(j = 0; j < colunaA; j++) {
			printf("%8.2f", matrizA[i][j]);
		}
//		printf("|");
		//printf("     |");
		for(j = 0; j < colunaB; j++) {
			printf("%8.2f", matrizB[i][j]); 
		}
		printf("\n");
		if (i == 0){
		    printf("\t\t x\t\t\n");
		}

	}

	printf("RESULTADO:\n\n");

	//Processamento e saida em tela  =  PRODUTO DAS MATRIZES
	for(i = 0; i < linhaA; i++) {
		for(j = 0; j < colunaB; j++) {
			matrizC[i][j] = 0;
			for(x = 0; x < linhaB; x++) {
				aux +=  matrizA[i][x] * matrizB[x][j];
			}

			matrizC[i][j] = aux;
			aux = 0;
		}
	}
	for(i = 0; i < linhaA; i++) {
		for(j = 0; j < colunaB; j++) {
			printf("%8.2f", matrizC[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
} else {
	printf("\n\n Nao ha com multiplicar as matrizes dadas ");
}

}

int main(void){
    float a[25][25], b[25][25];
    a[0][0] = 1;
    a[0][1] = 2;
    a[1][0] = 0;
    a[1][1] = 7;
    
    b[0][0] = 3;
    b[0][1] = 0;
    b[1][0] = 1;
    b[1][1] = 2;

    int fd[2];
    int n = 0;
    int i, c, j;
    char line[BUFSIZE];

    pipe(fd);


    if (fork() == 0){
        printf("\n---------------------------");
        printf("\n\nProcesso filho:");
        inversaMatriz(b);
        for(c = 0; c < 2; c++) {
            for(j = 0; j < 2; j++) {
		sprintf(line, "%f", b[c][j]);
                write(fd[1], line, BUFSIZE);
                printf("\n\t\tGravando %0.2f no arquivo!\n", atof(line));
                //sleep(1);
		        }
	        }
        }
        else{     
        wait(NULL);
        
        printf("Processo pai:");
        inversaMatriz(a);
        
        for (i=0; i < 2; i++) {
            for(int j = 0; j < 2;j++){
            read(fd[0], line, BUFSIZE);
            printf("\n \t\tLendo %0.2f do arquivo!\n", atof(line));
            	b[0][0] = atof(line);
        }
        
        
        printf("\n");
	}
        multMatriz(a, b);
    }
}
