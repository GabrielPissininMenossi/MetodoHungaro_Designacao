#include <stdio.h>
#include <conio2.h>
#include <string.h>
#include <stdlib.h>

#define TF 100

// ler matriz de adjacencia
void lerTxTMatrizAdjacencia(int m[TF][TF], int *qtdeVertices, int *qtdeLinhas, int *qtdeColunas, char vertices[TF])
{
	int j = 0, num, linhas = 0, colunas = 0;
	char linha[TF], aux[TF];
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
		//printf("%c", linha[i]);
	}
	// ler a matriz
	
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

void achaMinimos(int matriz[TF][TF], int minimoLinha[TF], int minimoColuna[TF])
{
	
}

void Moldura(int CI, int LI, int CF, int LF, int CorTxt, int CorFundo)
{
	int a;
	textcolor(CorTxt); // 0...15
	textbackground(CorFundo); // 0..7
	gotoxy(CI, LI); printf("%c", 201);
	gotoxy(CI, LF); printf("%c", 200);
	gotoxy(CF, LI); printf("%c", 187);
	gotoxy(CF, LF); printf("%c", 188);
	
	for(a=CI+1; a<CF; a++)
	{
		gotoxy(a, LI);	printf("%c", 205);
		gotoxy(a, LF);	printf("%c", 205);
	}
	
	for(a=LI+1; a<LF; a++)
	{
		gotoxy(CI, a);	printf("%c", 186);
		gotoxy(CF, a);	printf("%c", 186);
	}
	
	textcolor(7);
	textbackground(0);
}

void exibirMatrizAdjacenciaComVertices(int m[TF][TF], char vertices[TF], int qtdeLinhas, int qtdeColunas)
{
    //Moldura(1,1, 120,30, 7, 7);
	gotoxy(40,4), printf("     ====================================");
	gotoxy(50,5), textcolor(3),printf ("Representacao Computacional");
	gotoxy(62,6), textcolor(3),printf ("De");
	gotoxy(60,7), textcolor(3),printf ("Grafos");
	gotoxy(40,8), textcolor(7),printf("     ====================================");
	
	gotoxy(5,3), textcolor(3),printf("MA"); 
    for (int j = 0; j < qtdeLinhas; j++)
	{
        gotoxy(9 + j*4,3), textcolor(3),printf("%c", vertices[j]);
        getch();
    }
    for (int i = 0; i < qtdeLinhas; i++)
	{
        gotoxy(5,5+i), textcolor(3),printf("%c", vertices[i]);
        for (int j = 0; j < qtdeLinhas; j++)
		{
            if (m[i][j] != 0)	
				gotoxy(8+j * 4,5+i), textcolor(2),printf("%2d", m[i][j]); // x y (coluna, linha)
			else
				gotoxy(8+j * 4,5+i), textcolor(7),printf("%2d", m[i][j]); // x y (coluna, linha)
        }
    }
}

