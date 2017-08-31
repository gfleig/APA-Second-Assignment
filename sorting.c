#include "sorting.h"

//MERGESORT
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



//QUICKSORT
//função auxiliar que partilha a tabela(array)
static void Partilha(int *tabela, int inf, int sup, int *posPivo)
{
	int pivo, esq, dir, aux;
	
	pivo = tabela[inf];			//pivô é o primeiro elemento

	esq = inf;						//apontador
	dir = sup;						//apontador

	while(esq < dir)				//enquanto não s eencontram
	{
		while(tabela[esq] <= pivo && esq < sup)		//enquanto o elem atual for menor que o pivo e os apontadores não se encontrarem
		{
			esq++;					//sobe a tabela
		}
		while(tabela[dir] > pivo)							//enquanto elem atual for maior
		{
			dir--;					//desce a tabela
		}
		if(esq < dir)
		{
			aux = tabela[dir];	//troca-se os elementos
			tabela[dir] = tabela[esq];
			tabela[esq] = aux;
		}
	}

	tabela[inf] = tabela[dir];	//troca-se as posições de dir e inf
	tabela[dir] = pivo;

	*posPivo = dir;				//a dir(apontador direito) aponta para a pos final do pivô
}

//carga pesada
static void Quick(int tabela[], int inf, int sup)
{
	int posPivo;
	
	if(inf >=sup)
	{
		return;						//já deve estar ordenada
	}
	
	Partilha(tabela, inf, sup, &posPivo);	//divide a tabela
	
	Quick(tabela, inf, posPivo - 1);			//ordena parte inferior
	
	Quick(tabela, posPivo + 1, sup);			//ordena parte superior
}

//função principal
void quickSort(int tabela[], int nElem)
{
	Quick(tabela, 0, nElem -1);	
}

//HEAPSORT
//função de percolação
static void percolaAbaixo(int heap[], int i, int n)
{
	int filho, aux;
	
	//verifica-se a ordenação do i e seus filhos
	aux = heap[i];
	while(2 * i + 1 < n)
	{
		filho = 2 * i + 1;		//filho esquerdo
		
		if((filho != n-1) && (heap[filho + 1] > heap[filho]))	//se não estourar e o da direita for o maior
		{
			filho++;					//filho da direita é maior
		}
		
		if(aux < heap[filho])	//fora de ordem
		{
			heap[i] = heap[filho];//troca
		}
		else
		{
			break;
		}
		
		i = filho;
	}
	
	heap[i] = aux;					//completa a troca
}

//função de ordenação em si
void heapSort(int tabela[], int nElem)
{
	int i, aux;
	
	for(i = (nElem - 2) / 2; i >= 0; i--)		//contróis o heapa  partir do pai do último elemento
	{
		percolaAbaixo(tabela, i, nElem);
	}
	
	for(i = nElem - 1; i >= 1; i--)				//coloca o primeiro(maior) elemento da tabela no fim
	{
		aux = tabela[0];
		tabela[0] = tabela[i];
		tabela[i] = aux;
		
		percolaAbaixo(tabela, 0, i);				//reordena o heap
	}
	
}








