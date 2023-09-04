#include "guerreiro.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "dragao.h"
#include "elemento.h"
#include "locacao.h"

int MAX_GUERREIRO = 10;
int qtdGuerreiro = 0;
int codAtual = 1;

guerreiro *LtGuerreiro;
FILE * ag;

int inicializarGuerreiro()
{
	
	ag = fopen ("guerreiro.txt", "r+b");
	if(ag == NULL)
	{
		printf("\nErro na abertura do arquivo!\n");
		system("pause");
		return 0;
	}
	fseek (ag,0, SEEK_END);
	int recebe = ftell(ag);
	qtdGuerreiro= recebe/sizeof(guerreiro);
	fseek(ag,0, SEEK_SET);
	
	int i;
	
	guerreiro g;
	
	for(i = 0; i < qtdGuerreiro; i++)
	{
		fread(&g, sizeof(guerreiro), 1, ag);
		if(g.codigo > codAtual)
		{
			codAtual = g.codigo;
		}
	}
	codAtual++;
	printf("Codigo atual: %d", codAtual);
	printf("\nQuantidade de guerreiros: %d", qtdGuerreiro);
	printf("\n");
	
	/*LtGuerreiro = (guerreiro*) malloc (MAX_GUERREIRO * sizeof(guerreiro));
	if(LtGuerreiro == NULL) 
	{
		return 0;
	}
	
	int i;
	for(i = 0; i < MAX_GUERREIRO; i++)
	{
		LtGuerreiro[i].nome[0] = '\0';
		LtGuerreiro[i].reino[0] = '\0';
		LtGuerreiro[i].titulo[0]= '\0';
		LtGuerreiro[i].codigo = 0;
	}
	
	strcpy(LtGuerreiro[0].nome, "Gabriela");
	strcpy(LtGuerreiro[0].reino, "Pinhal");
	strcpy(LtGuerreiro[0].titulo, "Rainha");
	LtGuerreiro[0].codigo = codAtual;
	codAtual++;
	qtdGuerreiro++;
	
	strcpy(LtGuerreiro[1].nome, "Iasmin");
	strcpy(LtGuerreiro[1].reino, "Gravatai");
	strcpy(LtGuerreiro[1].titulo, "Enfermeira");
	LtGuerreiro[1].codigo = codAtual;
	codAtual++;
	qtdGuerreiro++;*/
	
}

int encerraGuerreiros()
{
	fclose(ag);
	//free(LtGuerreiro);
	//LtGuerreiro = NULL;
}

int cadastrarGuerreiro(guerreiro g)
{
	g.codigo = codAtual;
	
	fseek(ag, 0, SEEK_END);
	fwrite(&g, sizeof(guerreiro), 1, ag);
	qtdGuerreiro++;
	
	return 1;
	
	/*
	if(qtdGuerreiro < MAX_GUERREIRO)
	{
		g.codigo = codAtual++;
		LtGuerreiro[qtdGuerreiro] = g;
		qtdGuerreiro++;
		return 1;
	}
	
	else
	{
		return 0; //quando falha
	}*/
}

int quantidadeGuerreiro()
{
	return qtdGuerreiro;
}

int obterGuerreiroPeloIndice(int indice, guerreiro* g)
{
	guerreiro gi;
	rewind(ag);
	fseek(ag, indice* sizeof(guerreiro), SEEK_SET);
	fread(&gi, sizeof(guerreiro), 1, ag);
	*g = gi;
	
	return 1;
//	*g = LtGuerreiro[indice];
//	return 1;
}

int obterGuerreiroPeloCodigo(int codigo, guerreiro* g)
{
	guerreiro gc;
	rewind(ag);
	fseek(ag, 0, SEEK_CUR);
	int i;
	
	for(i = 0; i < qtdGuerreiro; i++)
	{
		fread(&gc, sizeof(guerreiro), 1, ag);
		if(codigo == gc.codigo);
		{
			*g = gc;
			return 1;
		}
	}
//	int i;
//	for(i = 0; i < qtdGuerreiro; i++)
//	{
//		*g = LtGuerreiro[i];
//		if(g->codigo == codigo)
//		{
//			*g = LtGuerreiro[i];
//			return 1;
//		}
//	}
	return 0;	
}

int excluirGuerreiroPeloCodigo(int codigo)
{
	FILE *excluirG;
	guerreiro exg;
	
	rewind(ag);
	
	if(ag == NULL || excluirG == NULL)
	{
		printf("\nErro na abertura do arquivo!\n");
		system("pause");
	}
	else
	{
		fflush(ag);
		while(fread(&exg, sizeof(guerreiro), 1, ag) == 1)
		{
			if(codigo != exg.codigo)
			{
				fwrite(&exg, sizeof(guerreiro), 1, excluirG);
				codAtual--;
			}
		}
	}
	
	fclose(ag);
	fclose(excluirG);
	remove("guerreiro.txt");
	rename("novoG.txt", "guerreiro.txt");
	
	ag = fopen("guerreiro.txt", "r+b");
	return 1;
	
//	int i;
//	for(i = 0; i < qtdGuerreiro; i++)
//	{
//		if(LtGuerreiro[i].codigo == codigo)
//		{
//			LtGuerreiro[i] = LtGuerreiro[qtdGuerreiro-1];
//			LtGuerreiro[qtdGuerreiro -1].codigo = 0;
//			qtdGuerreiro--;
//			return 1;
//		}
//	}
//	return 0; // caso falhe
}

int aumentarTamanhoG()
{
/*	if(qtdGuerreiro == MAX_GUERREIRO)
	{
		MAX_GUERREIRO +=2;
		guerreiro* novaListaG = (guerreiro*) realloc (LtGuerreiro, MAX_GUERREIRO * sizeof(guerreiro));
		if(novaListaG != NULL)
		{
			LtGuerreiro = novaListaG;
			free(novaListaG);
			novaListaG = NULL;
			return 1;
		}
	}*/
}

int reduzirTamanhoG()
{
/*	if(qtdGuerreiro < (MAX_GUERREIRO * 0.4))
	{
		MAX_GUERREIRO = qtdGuerreiro +2;
		guerreiro* novaListaGR = (guerreiro*) realloc (LtGuerreiro, MAX_GUERREIRO * sizeof(guerreiro));
		if(novaListaGR != NULL)
		{
			LtGuerreiro = novaListaGR;
			free(novaListaGR);
			novaListaGR = NULL;
			return 1;
		}
	}*/
}

int RETORNAMAXG()
{
	return MAX_GUERREIRO;
}

int alterarGuerreiro(int codigo, guerreiro g)
{
	guerreiro alg;
	
	FILE* rodar = fopen("novoGuerreiro.txt", "w+b");
	rewind(ag);
	
	while(fread(&alg, sizeof(guerreiro), 1, ag) == 1)
	{
		if(alg.codigo != g.codigo)
		{
			fwrite(&alg, sizeof(guerreiro), 1, rodar);
		}
		else
		{
			fwrite(&g, sizeof(guerreiro), 1, rodar);
		}
	}
	
	fclose(ag);
	fclose(rodar);
	
	remove("guerreiro.txt");
	rename("novoGuerreiro.txt", "guerreiro.txt");
	ag= fopen("guerreiro.txt", "r+b");
	return 1;
	
/*	int i;
	for (i = 0; i < qtdGuerreiro; i++)
	{
		guerreiro h = LtGuerreiro [i];
		if(h.codigo == codigo)
		{
			LtGuerreiro[i] = g;
			return 1;
		}
	}
	return 0;*/
}

