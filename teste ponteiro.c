#include <stdio.h>
#include <stdlib.h>

#define LIN_COL 3

void main()
{
	int linhas_colunas, 
	i, 
	j;
	float **matriz, 
	determinante,
	C1,
	C2;
	
	// apresentação do programa
	printf("---------------(*-.-*)----------------------\n");
	printf("Leitura de Matriz e Calculo de Determinante\n");
	printf("--------------------------------------------\n\n");

	// leitura de linhas e colunas
	do 
  	{
		printf("Qual serah a quantidade de linhas/colunas da matriz?\n");
		printf("\t(digite soh uma vez, ela serah quadrada)\n");
		scanf("%d", &linhas_colunas); 
		
			if(linhas_colunas <= 0 || linhas_colunas > LIN_COL)
		   	 printf("Esse valor nao eh valido, digite novamente!!!\n\n");
		    
 	}while(linhas_colunas <= 0 || linhas_colunas > LIN_COL);

	// alocando vetor de matriz
	matriz= (float**)malloc(linhas_colunas * sizeof(float*));
	
	
	// alocando cada uma das linhas da matriz
	for(i = 0; i < linhas_colunas; i++)
		matriz[i] = (float*)malloc(linhas_colunas * sizeof(float));

	
	// preenchendo a matriz
	printf("Agora digite o valor de cada elemento:\n");
	
	for(i=0; i<linhas_colunas; i++)
	{
		for(j=0; j<linhas_colunas; j++)
	 	{
			printf("M[%d][%d] = ", i+1, j+1);
			scanf("%f", &matriz[i][j]);
	  	}
	}
	printf("--------------------------------------------\n"); 
	
	// mostrando os elementos da matriz
	printf("\tMatriz definida: \n");
	
	for(i=0; i<linhas_colunas; i++)
	{
		for(j=0; j<linhas_colunas; j++)
	  	{
	  	  printf("\t|%.1f|", matriz[i][j]);
	  	}
	  	printf("\n\n");
	}
	  
	// cálculo da determinante
	if(linhas_colunas == 1)
	{
		determinante= matriz[0][0];
		printf("\t--> O determinate dessa matriz eh %.1f\n", determinante);
	}
	
	else if (linhas_colunas == 2)
	{
		C1= (matriz[0][0]*matriz[1][1]);
		C2= (matriz[0][1]*matriz[1][0]);
		
		determinante= C1-C2;	
		printf("\t--> O determinate dessa matriz eh %.1f\n", determinante);	
	} 
	
	else 
	{
		C1= (matriz[0][0]*matriz[1][1]*matriz[2][2]+
			 matriz[0][1]*matriz[1][2]*matriz[2][0]+
			 matriz[0][2]*matriz[1][0]*matriz[2][1]);
			 
		C2= (matriz[0][2]*matriz[1][1]*matriz[2][0]+
			 matriz[2][1]*matriz[1][2]*matriz[0][0]+
		   	 matriz[0][1]*matriz[1][0]*matriz[2][2]);
			
		determinante= C1-C2;	
		printf("\t--> O determinate dessa matriz eh %.1f\n", determinante);
	}

}
