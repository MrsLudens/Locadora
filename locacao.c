#include "locacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "dragao.h"
#include "guerreiro.h"

int MAX_LOCACAO = 5;
int qtdLocacao = 0;
int codAtualL = 1;

Locar *LtAlugar;
FILE * al;

int inicializarLocacao()
{
	al = fopen ("locacao.txt", "r+b");
	if(al == NULL)
	{
		printf("\nErro na abertura do arquivo!\n");
		system("pause");
		exit(1);
	}
	fseek (al,0, SEEK_END);
	int recebe = ftell(al);
	qtdLocacao= recebe/sizeof(Locar);
	fseek(al,0, SEEK_SET);
	
	int i;
	
	Locar l;
	
	for(i = 0; i < qtdLocacao; i++)
	{
		fread(&l, sizeof(Locar), 1, al);
		if(l.codigo > codAtualL)
		{
			codAtualL = l.codigo;
		}
	}
	codAtualL++;
	printf("\nCodigo atual: %d", codAtualL);
	printf("\nQuantidade de dragoes: %d", qtdLocacao);
	printf("\n");
	
//	LtAlugar = (Locar*) malloc (MAX_LOCACAO * sizeof(Locar));
//	if(LtAlugar == NULL)
//	{
//		return 0;
//	}
//	
//	int i;
//	for(i = 0; i < MAX_LOCACAO; i++)
//	{
//		LtAlugar[i].codigo = 0;
//		LtAlugar[i].pago[0] = '\0';
//		LtAlugar[i].finalLocacao[0] = '\0';
//		LtAlugar[i].inicioLocacao[0] = '\0';
//		LtAlugar[i].codGuerreiro = '\0';
//		LtAlugar[i].codDragao = '\0';
//	}
//	
//	LtAlugar[0].codigo = codAtualL;
//	strcpy(LtAlugar[0].inicioLocacao, "16/06/2022");
//	strcpy(LtAlugar[0].finalLocacao, "20/12/2022");
//	strcpy(LtAlugar[0].pago, "S");
//	LtAlugar[0].codGuerreiro = 1;
//	LtAlugar[0].codDragao = 1;
//	qtdLocacao++;
//	codAtualL++;
}

int encerraLocacao()
{
	fclose(al);
//	free(LtAlugar);
}

int salvarLocacao(Locar l)
{
	l.codigo = codAtualL;
	
	fseek(al, 0, SEEK_END);
	fwrite(&l, sizeof(Locar), 1, al);
	qtdLocacao++;
	
	return 1;
//	if(qtdLocacao < MAX_LOCACAO)
//	{
//		l.codigo = codAtualL++;
//		LtAlugar[qtdLocacao] = l;
//		qtdLocacao++;
//		
//		return 1;
//	} 
//	else
//	{
//		return 0; //caso falhe
//	}
}

int quantidadeLocado()
{
	return qtdLocacao;
}

int obterLocacaoPeloIndice(int indice, Locar* l)
{
	Locar li;
	
	rewind(al);
	fseek(al, indice* sizeof(Locar), SEEK_SET);
	fread(&li, sizeof(Locar), 1, al);
	*l = li;
	
	return 1;
	
//	*l = LtAlugar[indice];
//	return 1;
}

int obterLocacaoPeloCodigo(int codigo, Locar* l)
{
	Locar lc;
	rewind(al);
	fseek(al, 0, SEEK_CUR);
	int i;
	
	for(i = 0; i < qtdLocacao; i++)
	{
		fread(&lc, sizeof(Locar), 1, al);
		if(codigo == lc.codigo);
		{
			*l = lc;
			return 1;
		}
	}
	
//	int i;
//	for(i = 0; i <qtdLocacao; i++)
//	{
//		*l = LtAlugar[i];
//		if(l->codigo == codigo)
//		{
//			return 1;
//		}	
//	}
//	return 0;	
}

int ApagarLocacaoPeloCodigo(int cod)
{
	FILE *excluirL;
	Locar exl;
	
	
	excluirL = fopen("novoL.txt", "w+b");
	
	rewind(al);
	
	if(al == NULL || excluirL == NULL)
	{
		printf("\nErro na abertura do arquivo!\n");
		system("pause");
	}
		
	else
	{
		fflush(al);
			
		while(fread(&exl, sizeof(Locar), 1, al) == 1)
		{
			if(cod != exl.codigo)
			{
				fwrite(&exl, sizeof(Locar), 1, excluirL);
				codAtualL--;
			}
		}
	}
		
	fclose(al);
		
	close(excluirL);
		
	remove("locacao.txt");
		
	rename("novoL.txt", "locacao.txt");
		
	al = fopen("locacao.txt", "r+b");
		
	return 1;
/*	int i;
	for(i = 0; i < qtdLocacao; i++)
	{
		if(LtAlugar[i].codigo == cod)
		{
			LtAlugar[i] = LtAlugar[qtdLocacao-1];
			LtAlugar[qtdLocacao - 1].codigo = 0;
			qtdLocacao--;
			return 1;
		}
	}*/
	return 0;
}

int aumentarTamanhoL()
{
/*	if(qtdLocacao == MAX_LOCACAO)
	{
		MAX_LOCACAO +=2;
		Locar* novaListaLo = (Locar*) realloc (LtAlugar, MAX_LOCACAO * sizeof(Locar));
		if(novaListaLo != NULL)
		{
			LtAlugar = novaListaLo;
			free(novaListaLo);
			novaListaLo = NULL;
			return 1;
		}
	}*/
}

int reduzirTamanhoL()
{
/*	if(qtdLocacao < (MAX_LOCACAO * 0.4))
	{
		MAX_LOCACAO = qtdLocacao +2;
		Locar* novaListaL = (Locar*) realloc (LtAlugar, MAX_LOCACAO * sizeof(Locar));
		if(novaListaL != NULL)
		{
			LtAlugar = novaListaL;
			free(novaListaL);
			novaListaL = NULL;
			return 1;
		}
	}*/
}

int RETORNAMAXL()
{
	return MAX_LOCACAO;
}

int alterarLocacao(int cod, Locar l)
{
	Locar all;
		
	FILE* rodarL = fopen("novaLocacao.txt", "w+b");
	
	rewind(al);
	
	while(fread (&all, sizeof(Locar), 1, al) ==1)
	{

		if(all.codigo != l.codigo)
		{
			fwrite(&all, sizeof(Locar), 1, rodarL);
		}
		
		else
		{
			fwrite(&l, sizeof(Locar), 1, rodarL);
		}
	}
	
	fclose(al);
	
	fclose(rodarL);
	
	remove("locacao.txt");
	
	rename("novaLocacao.txt", "locacao.txt");
	
	al = fopen("locacao.txt", "r+b");

	return 1;
/*	int i;
	for(i = 0; i < qtdLocacao; i++)
	{
		Locar h = LtAlugar[i];
		if(LtAlugar[i].codigo > 0)
		{
			if(h.codigo == cod)
			{
				LtAlugar[i] = l;
				return 1;
			}
		}
	}*/
	return 0;
}

