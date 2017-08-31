#include "sorting.h"

//faz a intercalação dos subarrays
static void Merge(int tabela[], int aux[], int iniEsq, int iniDir, int finalDir)
{
	int i, finalEsq, nElementos, posAux;
	
	finalEsq = iniDir - 1;
	posAux = iniEsq;
	nElementos = finalDir - iniEsq + 1;
	

	//intercala enquanto os dois subarrays contiverem elementos
	while((iniEsq <= finalEsq) && (iniDir <= finalDir))
	{
		if(tabela[iniEsq] <= tabela[iniDir])
		{
			aux[posAux++] = tabela[iniEsq++];
		}
		else
		{
			aux[posAux++] = tabela[iniDir++];
		}
	}

	//adiciona o resto dos elementos, se ouver
	while(iniEsq <= finalEsq)
	{
		aux[posAux++] = tabela[iniEsq++];
	}

	while(iniDir <= finalDir)
	{
		aux[posAux++] = tabela[iniDir++];
	}

	//tabela = aux
	for(i = 0; i < nElementos; i++, finalDir--)
	{
		tabela[finalDir] = aux[finalDir];
	}
}

//ordena usando intercalação com uma tabela auxiliar
static void MSort(int *tabela, int *aux, int esquerda, int direita)
{
	int centro;
	
	if(esquerda < direita)
	{
		centro = (esquerda + direita)/2;
		
		//metade inferior
		MSort(tabela, aux, esquerda, centro);
		
		//metade superior
		MSort(tabela, aux, centro + 1, direita);
		
		//intercala as duas metades - que são reduzidas a arrays unitários, e por fim a tabela é ordenada de dentro para fora
		Merge(tabela, aux, esquerda, centro + 1, direita);
	}
}

//cria tabela auxiliar, é a função principal que chama as outras
void mergeSort(int tabela[], int nElem)
{
	int *aux;
	
	//aloca espaço para tabela auxiliar
	aux = malloc(nElem * sizeof(int));
	
	//faz o serviço
	MSort(tabela, aux, 0, nElem - 1);
	
	free(aux);
}
