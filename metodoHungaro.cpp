#include "auxiliares.h"

int main()
{
	int ordem, matriz[TF][TF], matrizAux[TF][TF];
	int minimoLinha[TF], minimoColuna[TF];
	int qtdeZerosLinha[TF], qtdeZerosColuna[TF];
	int designacoes[TF];
	int qtdeLinhaMark, qtdeColunaMark;
	int linhas = 0, colunas = 0;
	char vertices[TF];
	
	//executar();
	lerTxTMatrizAdjacencia(matriz, &ordem, &linhas, &colunas, vertices);
	textcolor(3),printf ("Matriz Inicializada\n");
	exibirMatriz(matriz, linhas, colunas, vertices);
	
	printf ("\n");
	textcolor(3),printf("Vetor de Minimos das Linhas\n");
	achaMinimoLinha(matriz, minimoLinha, linhas, colunas);
	exibirMinimo(minimoLinha, linhas);
	textcolor(3),printf ("\nRefazendo a Matriz a Partir dos Minimos das Linhas\n");
	refazerMatrizMinimoLinha(matriz, minimoLinha, linhas, colunas);
	exibirMatriz(matriz, linhas, colunas, vertices);
	
	printf ("\n");
	textcolor(3),printf("Vetor de Minimos das Colunas\n");
	achaMinimoColuna(matriz, minimoColuna, linhas, colunas);
	exibirMinimo(minimoColuna, colunas);
	textcolor(3),printf ("\nRefazendo a Matriz a Partir dos Minimos das Colunas\n");
	refazerMatrizMinimoColuna(matriz, minimoColuna, linhas, colunas);
	exibirMatriz(matriz, linhas, colunas, vertices);
	
	printf ("\n");
	
	int i = 0;
	do
	{
		qtdeLinhaMark = qtdeColunaMark = 0;
		inicializarMatriz(matrizAux, linhas);
		inicializarVetor(qtdeZerosLinha, linhas);
		inicializarVetor(qtdeZerosColuna, colunas);
		contarZerosLinha(matriz, qtdeZerosLinha, linhas, colunas);
		contarZerosColuna(matriz, qtdeZerosColuna, linhas, colunas);
		
		textcolor(3), printf("---%d Iteracao---\n\n", i + 1);
		
		textcolor(3),printf ("Vetor de Zeros das Linhas\n");
		exibirMinimo(qtdeZerosLinha, linhas);
		printf ("\n");
		
		textcolor(3),printf ("Vetor de Zeros das Colunas\n");
		exibirMinimo(qtdeZerosColuna, colunas);
		printf ("\n\n");
		
		grifar(matriz, matrizAux, qtdeZerosLinha, qtdeZerosColuna, &qtdeLinhaMark, &qtdeColunaMark, linhas);
		
		textcolor(3),printf ("Matriz Grifada\n");
		exibirMatrizGrifada(matrizAux, linhas, colunas, vertices);
		printf ("\n");

		refazerMatriz(matriz, matrizAux, linhas, colunas);
		
		textcolor(3),printf ("Matriz Reduzida\n");
		exibirMatriz(matriz, linhas, colunas, vertices);
		printf ("\n");
	
		i++;
	} while(qtdeLinhaMark + qtdeColunaMark < linhas);
	textcolor(3),printf ("--- FIM ---\n\n");
	
	//relatorio final
	inicializarVetor(qtdeZerosLinha, linhas);
	inicializarVetor(qtdeZerosColuna, colunas);
	contarZerosLinha(matriz, qtdeZerosLinha, linhas, colunas);
	contarZerosColuna(matriz, qtdeZerosColuna, linhas, colunas);
	matrizFinal(matriz, designacoes, qtdeZerosLinha, qtdeZerosColuna, linhas);
	textcolor(3),printf("### Resultado Final ###\n");
	exibirMatrizFinal(matriz, linhas, colunas, vertices);

	textcolor(7);
	return 0;
}

