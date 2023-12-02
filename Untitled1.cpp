//programa que implementa a ordenação topologica de um grafo

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//declaracao de tamanho do grafo

const int qtdvertices = 711;

//funcao que cria o grafo

void criar(int grafo[qtdvertices][qtdvertices], int aleatorio) {
	int j = 0;
	int i = 0;
	int conexao = 0;
	
	for (i = 0; i < qtdvertices; i++) {
		for (j = 0; j < qtdvertices; j++) {
			grafo[i][j] = 0;
			if (aleatorio) {
				conexao = (rand() % 2);
			} else {
				printf("Digite <1> se %d esta conectado a %d: ", i, j);
				scanf("%d", &conexao);
			}
			grafo[i][j] = conexao;
		}
	}
}

//funcao recursiva que ordena topologicamente o grafo

void ordenarTopologicoRecursivo(int grafo[qtdvertices][qtdvertices], int visitado[qtdvertices], int vertice) {
	int i;
	visitado[vertice] = 1;
	
	for (i = 0; i < qtdvertices; i++) {
		if ((grafo[vertice][i]) && (! visitado[i])) {
			ordenarTopologicoRecursivo(grafo, visitado, i);
		}
	}
	
	printf("%d\t", vertice);
}

//funcao que ordena topologicamente o grafo

void ordenarTopologico(int grafo[qtdvertices][qtdvertices]) {
	int vertice;
	int visitado[qtdvertices];
	
	for (vertice = 0; vertice < qtdvertices; vertice++) {
		visitado[vertice] = 0;
	}
	
	for (vertice = 0; vertice < qtdvertices; vertice++) {
		if (! visitado[vertice]) {
			ordenarTopologicoRecursivo(grafo, visitado, vertice);
		}
	}
	
	printf("\n");
}

//funcao principal de execucao de um programa;

int main() {
	time_t t;
	srand((unsigned) time(&t));
	
	int grafo
	
	
	[qtdvertices][qtdvertices];
	criar(grafo, 1);
	ordenarTopologico(grafo);
}
