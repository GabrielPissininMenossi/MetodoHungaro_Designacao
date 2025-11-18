#include <stdio.h>
#include <conio2.h>
#include <string.h>
#include <stdlib.h>

#define TF 100

// ler matriz de adjacencia
void lerTxTMatrizAdjacencia(int m[TF][TF], int *qtdeVertices, int *qtdeLinhas, int *qtdeColunas, char vertices[TF])
{

	int j = 0, num, linhas = 0, colunas = 0;
	char linha[50], aux[50];
	FILE * Ptr = fopen("entradaMA.txt", "r");
	rewind(Ptr); // joga o ponteiro para o inicio
	fgets(linha, sizeof(linha), Ptr); // le a primeira linha, contendo todos meus vertices
	for (int i = 0; i < strlen(linha);i++)
	{
		if (linha[i] != ' ' && linha[i] != '\n')
		{
			vertices[j] = linha[i];
			*qtdeVertices = *qtdeVertices + 1;
			j++;
		}
	}
	
	while(fgets(linha, sizeof(linha), Ptr))
	{
		j = 0;
		colunas = 0;
		for(int i = 0; i < strlen(linha); i++)
		{
			if(linha[i] != ' ' && linha[i] != '\n')
			{
				aux[j] = linha[i];
				j++;
			}
			else
			{
				aux[j] = '\0';
				num = atoi(aux);
				m[linhas][colunas] = num;
				j = 0;
				colunas++;
			}
		
			
		}
		if (j > 0)
		{
			
			aux[j] = '\0';
			num = atoi(aux);
			m[linhas][colunas] = num;

		}
		if (colunas > *qtdeColunas)
			*qtdeColunas = colunas;
		linhas++;
	}
	*qtdeLinhas = linhas;
	
	fclose(Ptr);
}


void achaMinimoLinha(int matriz[TF][TF], int minimoLinha[TF], int linhas, int colunas)
{
	// achar o minimo da linha
	int menor;
	for (int i = 0; i < linhas; i++)
	{
		menor = 9999;
		for (int j = 0; j < colunas; j++)
		{
			if (matriz[i][j] < menor)
			{
				menor = matriz[i][j];
			}
			
		}
		minimoLinha[i] = menor;
	}
	
	
}
void achaMinimoColuna (int matriz[TF][TF], int minimoColuna[TF], int linhas, int colunas)
{
	int menor;
	for (int j = 0; j < colunas; j++)
	{
		menor = 9999;
		for (int i = 0; i < linhas; i++)
		{
			
			if (matriz[i][j] < menor)
			{
				menor = matriz[i][j];
			}
			
		}
		minimoColuna[j] = menor;
	}
}
void refazerMatrizMinimoLinha (int matriz[TF][TF], int minimoLinha[TF], int linhas, int colunas)
{
	for (int i = 0; i < linhas; i++)
	{
		for (int j = 0; j < colunas; j++)
		{
			matriz[i][j] = matriz[i][j] - minimoLinha[i];
		}
	}
	
}
void refazerMatrizMinimoColuna (int matriz[TF][TF], int minimoColuna[TF], int linhas, int colunas)
{
	
	for (int j = 0; j < colunas; j++)
	{
		for (int i = 0; i < linhas; i++)
		{
			matriz[i][j] = matriz[i][j] - minimoColuna[j];
		}
	}
}
void inicializarVetor(int vet[], int tam)
{
	for (int i = 0; i < tam; i++)
	{
		vet[i] = 0;
	}
}
void contarZerosLinha(int matriz[TF][TF], int qtdeZerosLinha[TF], int linhas, int colunas)
{
	for (int i = 0; i < linhas; i++)
	{
		for (int j = 0; j < colunas; j++)
		{
			if (matriz[i][j] == 0)
				qtdeZerosLinha[i]++;
		}
	}
}
void contarZerosColuna(int matriz[TF][TF], int qtdeZerosColuna[TF], int linhas, int colunas)
{
	for (int j = 0; j < colunas; j++)
	{
		for (int i = 0; i < linhas; i++)
		{
			if (matriz[i][j] == 0)
				qtdeZerosColuna[j]++;
		}
	}
}
int acharMenor(int matriz[TF][TF], int matrizAux[TF][TF], int linhas, int colunas)
{
	int menor = 9999;
	for (int i = 0; i < linhas; i++)
	{
		for (int j = 0; j < colunas; j++)
		{
			if (matrizAux[i][j] == 0 && matriz[i][j] < menor)
				menor = matriz[i][j];

		}
	}
	return menor;
}
void refazerMatriz(int matriz[TF][TF], int matrizAux[TF][TF], int linhas, int colunas)
{
	int menor = acharMenor(matriz, matrizAux, linhas, colunas);
	for (int i = 0; i < linhas; i++)
	{
		for (int j = 0; j < colunas; j++)
		{
			if (matrizAux[i][j] > 1) // soma
			{
				matriz[i][j] = matriz[i][j] + menor;
			}
			else
			if (matrizAux[i][j] == 0) // subtrai
			{

				matriz[i][j] = matriz[i][j] - menor;
			}
		}
	}
}
void exibirMinimo(int vet[], int tam)
{
	for (int i = 0; i < tam; i++)
		textcolor(7),printf("[%d] ", vet[i]);
}
void exibirColunas(char vertices[TF])
{
	textcolor(2),printf ("    D1   ");
	for (int i = 1; i < strlen(vertices); i++)
    {
    	textcolor(2),printf ("D%d   ", i+1);
    }
    printf ("\n");
	
}
void exibirMatriz(int m[TF][TF], int qtdeLinhas, int qtdeColunas, char vertices[TF])
{
	exibirColunas(vertices);
	for (int i = 0; i < qtdeLinhas; i++)
	{
		textcolor(2),printf (" P%d ", i + 1);
		for (int j = 0; j < qtdeColunas; j++)
		{
			if (m[i][j] != 0)
				textcolor(7),printf ("[%d] ", m[i][j]);
			else
				textcolor(12),printf ("[%d] ", m[i][j]);
		}
		printf ("\n");
	}
}
void exibirMatriz(int m[TF][TF], int qtdeLinhas, int qtdeColunas)
{
	for (int i = 0; i < qtdeLinhas; i++)
	{
		for (int j = 0; j < qtdeColunas; j++)
		{
			if (m[i][j] != 0)
				textcolor(7),printf ("[%d] ", m[i][j]);
			else
				textcolor(12),printf ("[%d] ", m[i][j]);
		}
		printf ("\n");
	}
}
void exibirMatrizGrifada(int m[TF][TF], int qtdeLinhas, int qtdeColunas, char vertices[TF])
{
	exibirColunas(vertices);
	for (int i = 0; i < qtdeLinhas; i++)
	{
		textcolor(2),printf (" P%d ", i + 1);
		for (int j = 0; j < qtdeColunas; j++)
		{
			if (m[i][j] == 1)
				textcolor(14),printf ("[%d] ", m[i][j]);
			else
			if (m[i][j] > 1)
				textcolor(4),printf ("[%d] ", m[i][j]);
			else
				textcolor(7),printf ("[%d] ", m[i][j]);
		}
		printf ("\n");
	}	
	
}
void exibirMatrizFinal(int m[TF][TF], int qtdeLinhas, int qtdeColunas, char vertices[TF])
{
	exibirColunas(vertices);
	for (int i = 0; i < qtdeLinhas; i++)
	{
		textcolor(2),printf (" P%d ", i + 1);
		for (int j = 0; j < qtdeColunas; j++)
		{
			if (m[i][j] == -1)
				textcolor(8),printf ("[%d] ", m[i][j]);
			else
			if (m[i][j] != 0)
				textcolor(7),printf ("[%d] ", m[i][j]);
			else
				textcolor(12),printf ("[%d] ", m[i][j]);
		}
		printf ("\n");
	}
}
void inicializarMatriz(int matrizAux[TF][TF], int ordem)
{
	for(int i=0; i<ordem; i++)
	{
		for(int j=0; j<ordem; j++)
		{
			matrizAux[i][j] = 0;
		}
	}
}
int maiorIndiceVet(int vet[TF], int TL, int *qtde)
{
	int pos = 0;
	for(int i=0; i<TL; i++)
	{
		if(vet[i]>vet[pos])
			pos = i;
	}
	*qtde = vet[pos];
	return pos;
}
void grifarLinha(int matriz[TF][TF], int matrizAux[TF][TF], int ordem, int linha, int qtdeZerosColuna[TF])
{
	for(int i=0; i<ordem; i++)
	{
		if(matriz[linha][i] == 0)
		{
			qtdeZerosColuna[i] = qtdeZerosColuna[i] - 1;
		}
		matrizAux[linha][i] = matrizAux[linha][i] + 1;
	}
}
void grifarColuna(int matriz[TF][TF], int matrizAux[TF][TF], int ordem, int coluna, int qtdeZerosLinha[TF])
{
	for(int i=0; i<ordem; i++)
	{
		if(matriz[i][coluna] == 0)
		{
			qtdeZerosLinha[i] = qtdeZerosLinha[i] - 1;
		}
		matrizAux[i][coluna] = matrizAux[i][coluna] + 1;
	}
}
void grifar(int matriz[TF][TF], int matrizAux[TF][TF], int qtdeZerosLinha[TF], int qtdeZerosColuna[TF], int *qtdeLinhasMark, int *qtdeColunasMark, int ordem)
{
	int linha, coluna, qtdeLin, qtdeCol;

	//entra lido
	linha = maiorIndiceVet(qtdeZerosLinha, ordem, &qtdeLin);
	coluna = maiorIndiceVet(qtdeZerosColuna, ordem, &qtdeCol);

	while(qtdeLin>0 || qtdeCol>0) //se verdade, ainda possui alguma linha ou coluna para ser grifada
	{
		if(qtdeLin>qtdeCol) //grifar a linha
		{
			grifarLinha(matriz, matrizAux, ordem, linha, qtdeZerosColuna);
			qtdeZerosLinha[linha] = 0;
			*qtdeLinhasMark = *qtdeLinhasMark + 1;
			//printf("Grifei a linha %d!\n", linha+1);
		}
		else //grifar a coluna em caso dela ser maior ou de der empate
		{
			grifarColuna(matriz, matrizAux, ordem, coluna, qtdeZerosLinha);
			qtdeZerosColuna[coluna] = 0;
			*qtdeColunasMark = *qtdeColunasMark + 1;
			//printf("Grifei a coluna %d!\n", coluna+1);
		}

		//exibirMatriz(matrizAux, ordem, ordem);
		//getch();
		//sai lido
		linha = maiorIndiceVet(qtdeZerosLinha, ordem, &qtdeLin);
		coluna = maiorIndiceVet(qtdeZerosColuna, ordem, &qtdeCol);
	}
}
void retirarZerosColuna(int matriz[TF][TF], int ordem, int linha, int coluna)
{
	for(int l=0; l<ordem; l++)
	{
		if(linha!=l && matriz[l][coluna] == 0)
		{
			matriz[l][coluna] = -1;
		}
	}
}
void retirarZerosLinha(int matriz[TF][TF], int ordem, int linha, int coluna)
{
	for(int c=0; c<ordem; c++)
	{
		if(coluna!=c && matriz[linha][c] == 0)
		{
			matriz[linha][c] = -1;
		}
	}
}
void matrizFinal(int matriz[TF][TF], int designacoes[TF], int qtdeZerosLinha[TF], int qtdeZerosColuna[TF], int ordem)
{
	//inicializar o vetor com nada atribuido -1
	for(int i=0; i<ordem; i++)
	{
		designacoes[i] = -1;
	}

	//primeiro verificar os unicos da linha e coluna
	for(int i=0; i<ordem; i++)
	{
		for(int j=0; j<ordem; j++)
		{
			if(matriz[i][j] == 0 && qtdeZerosLinha[i] == 1 && qtdeZerosColuna[j] == 1) //unico da linha e coluna
			{
				designacoes[i] = j;
			}
		}
	}

	//segundo verificar os unicos apenas da coluna
	for(int i=0; i<ordem; i++)
	{
		for(int j=0; j<ordem; j++)
		{
			if(matriz[i][j] == 0 && qtdeZerosColuna[j] == 1 && designacoes[i] == -1)
			{
				designacoes[i] = j;

				//preciso modificar a quantidade de zeros restantes na linha
				retirarZerosLinha(matriz, ordem, i, j);
				inicializarVetor(qtdeZerosLinha, ordem);
				inicializarVetor(qtdeZerosColuna, ordem);
				contarZerosLinha(matriz, qtdeZerosLinha, ordem, ordem);
				contarZerosColuna(matriz, qtdeZerosColuna, ordem, ordem);
			}
		}
	}

	//depois verificar os unicos apenas da linha
	for(int i=0; i<ordem; i++)
	{
		for(int j=0; j<ordem; j++)
		{
			if(matriz[i][j] == 0 && qtdeZerosLinha[i] == 1 && designacoes[i] == -1)
			{
				designacoes[i] = j;

				//preciso modificar a quantidade de zeros restantes na coluna
				retirarZerosColuna(matriz, ordem, i, j);
				inicializarVetor(qtdeZerosLinha, ordem);
				inicializarVetor(qtdeZerosColuna, ordem);
				contarZerosLinha(matriz, qtdeZerosLinha, ordem, ordem);
				contarZerosColuna(matriz, qtdeZerosColuna, ordem, ordem);
			}
		}
	}
}

