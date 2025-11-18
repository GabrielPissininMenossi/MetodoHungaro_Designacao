#include "auxiliares.h"

void executar()
{
	int ordem, matriz[TF][TF], matrizAux[TF][TF];
	int minimoLinha[TF], minimoColuna[TF];
	int qtdeZeroLinha[TF], qtdeZeroColuna[TF];
	int qtdeLinhaMark, qtdeColunaMark;
	
	//variaveis inuteis
	int linhas, colunas;
	char vertices[TF];
	
	// ler a matriz do arquivo
	lerTxTMatrizAdjacencia(matriz, &ordem, &linhas, &colunas, vertices);
	
	// achar os minimos da linha e refaz matriz
	achaMinimoLinha(matriz, minimoLinha);
	refazerMatrizMinimoLinha(matriz, minimoLinha);
	
	// achar os minimos da coluna e refaz matriz
	achaMinimoColuna(matriz, minimoColuna);
	refazerMatrizMinimoColuna(matriz, coluna);
	
	// contar os zeros das colunas e linhas
	contarZeros(matriz, qtdeZeroLinha, qtdeZeroColuna);
	
	// marcar a coluna e linha -> entra lido e sai lido
	marcarColunaELinha(matriz, qtdeZeroLinha, qtdeZeroColuna);
	while(qtdeLinhaMark+qtdeColunaMark < ordem)
	{
		refazerMatriz(matriz, matrizAux);
		
		marcarColunaELinha(matriz, matrizAux, qtdeZeroLinha, qtdeZeroColuna);
	}
	
	// marcar designacoes finais
	marcarDesignacoes(matriz);
}

int main()
{
	executar();
	
	return 0;
}
