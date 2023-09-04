#include "dragao.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "elemento.h"
#include "locacao.h"

int MAX_DRAGAO = 5;
int qtdDragao = 0;
int codAtualD = 1;

Dragao *LtDragao;
FILE * ad;

int inicializarDragao()
{
	ad = fopen ("dragao.txt", "r+b");
	if(ad == NULL)
	{
		printf("\nErro na abertura do arquivo!\n");
		system("pause");
		exit(1);
	}
	
	fseek (ad,0, SEEK_END);
	int recebe = ftell(ad);
	qtdDragao= recebe/sizeof(Dragao);
	fseek(ad,0, SEEK_SET);
	
	int i;
	
	Dragao d;
	
	for(i = 0; i < qtdDragao; i++)
	{
		fread(&d, sizeof(Dragao), 1, ad);
		if(d.codigo > codAtualD)
		{
			codAtualD = d.codigo;
		}
	}
	codAtualD++;
	printf("\nCodigo atual: %d", codAtualD);
	printf("\nQuantidade de dragoes: %d", qtdDragao);
	printf("\n");
	
	
//	LtDragao = (Dragao*) malloc (MAX_DRAGAO * sizeof (Dragao));
//	if(LtDragao == NULL)
//	{
//		return 0;
//	}	
//	
//	int i;
//	for(i = 0; i < MAX_DRAGAO; i++)
//	{
//		LtDragao[i].codigo = codAtualD;
//		LtDragao[i].nome[0] = '\0';
//		LtDragao[i].idade = 0;
//		LtDragao[i].valorDiario = 0;
//		LtDragao[i].unidadeEstoque = 0;
//		LtDragao[i].idElemento = 0;
//	}
//	
//	LtDragao[0].codigo = codAtualD;
//	strcpy(LtDragao[0].nome, "Bozena");
//	LtDragao[0].idade = 1;
//	LtDragao[0].valorDiario = 24.90;
//	LtDragao[0].unidadeEstoque = 5;
//	LtDragao[0].idElemento = 1;
//	qtdDragao++;
//	codAtualD++;
//	
//	LtDragao[1].codigo = codAtualD;
//	strcpy(LtDragao[1].nome, "Josiane");
//	LtDragao[1].idade = 3;
//	LtDragao[1].valorDiario = 24.90;
//	LtDragao[1].unidadeEstoque = 5;
//	LtDragao[1].idElemento = 2;
//	qtdDragao++;
//	codAtualD++;
	
}

int encerraDragao()
{
	fclose(ad);
//	free(LtDragao);
}

int cadastrarDragao(Dragao d, int encontrado)
{
	d.codigo = codAtualD;
	
	fseek(ad, 0, SEEK_END);
	fwrite(&d, sizeof(Dragao), 1, ad);
	qtdDragao++;
	
	return 1;
	
//	if(qtdDragao < MAX_DRAGAO && encontrado != 0)
//	{
//		d.codigo = codAtualD++;
//		LtDragao[qtdDragao] = d;
//		qtdDragao++;
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}	
}

int quantidadeDragao()
{
	return qtdDragao;
}

int obterDragaoPeloIndice(int indice, Dragao* d)
{
	Dragao di;
	
	rewind(ad);
	fseek(ad, indice* sizeof(Dragao), SEEK_SET);
	fread(&di, sizeof(Dragao), 1, ad);
	*d = di;
	
	return 1;
	
//	*d = LtDragao[indice];
//	return 1;
}

int obterDragaoPeloCodigo(int codigo, Dragao* d)
{
	Dragao dc;
	rewind(ad);
	fseek(ad, 0, SEEK_CUR);
	int i;
	
	for(i = 0; i < qtdDragao; i++)
	{
		fread(&dc, sizeof(Dragao), 1, ad);
		if(codigo == dc.codigo);
		{
			*d = dc;
			return 1;
		}
	}
	
//	int i;
//	for(i = 0; i < qtdDragao; i++)
//	{
//		*d = LtDragao[i];
//		if(d->codigo == codigo)
//		{
//			return 1;
//		}
//	}
//	return 0;		
}

int ApagarDragaoPeloCodigo(int codigo)
{
	FILE *excluirD;
	Dragao exd;
	
	excluirD = fopen("novoD.txt", "w+b");
	
	rewind(ad);
	
	if(ad== NULL || excluirD == NULL)
	{
		printf("\nErro na abertura do arquivo!\n");
		system("pause");
	}
	else
	{
		fflush(ad);
		while(fread(&exd, sizeof(Dragao), 1, ad) == 1)
		{
			if(codigo != exd.codigo);
			{
				fwrite(&exd, sizeof(Dragao), 1, excluirD);
				codAtualD--;
			}
		}
	}
	
	fclose(ad);
	fclose(excluirD);
	remove("dragao.txt");
	rename("novoD.txt", "dragao.txt");
	
	ad = fopen("dragao.txt", "r+b");
	
	return 1;
	
/*	int i;
	for(i = 0; i < qtdDragao; i++)
	{
		if(LtDragao[i].codigo == codigo)
		{
			LtDragao[i] = LtDragao[qtdDragao-1];
			LtDragao[qtdDragao-1].codigo = 0;
			qtdDragao--;
			return 1;
 		}
	}*/
	return 0; // caso falhe 
}

int diminuirUnidade(int codigo)
{
/*	int i;
	for(i = 0; i < qtdDragao; i++)
	{
		Dragao d= LtDragao[i];
		if(d.codigo == codigo)
		{
			LtDragao[i].unidadeEstoque--;
			return 1;
		}
	}*/
	return 0;
}

int aumentarUnidadeDrag(int codigo)
{
/*	int i;
	for(i = 0; i < qtdDragao; i++)
	{
		Dragao d = LtDragao[i];
		if(d.codigo == codigo)
		{
			LtDragao[i].unidadeEstoque++;
			return 1;
		}
	}*/
	return 0;
}

int aumentarTamanhoD()
{
/*	if(qtdDragao == MAX_DRAGAO)
	{
		MAX_DRAGAO +=2;
		Dragao* novaListaD = (Dragao*) realloc (LtDragao, MAX_DRAGAO * sizeof(Dragao));
		if(novaListaD != NULL)
		{
			LtDragao = novaListaD;
			free(novaListaD);
			novaListaD = NULL;
			return 1;
		}
	}*/
}

int reduzirTamanhoD()
{
/*	if(qtdDragao < (MAX_DRAGAO * 0.4))
	{
		MAX_DRAGAO = qtdDragao +2;
		Dragao* novaListaDR = (Dragao*) realloc (LtDragao, MAX_DRAGAO * sizeof(Dragao));
		if(novaListaDR != NULL)
		{
			LtDragao = novaListaDR;
			free(novaListaDR);
			novaListaDR = NULL;
			return 1;
		}
	}*/
}

int RETORNAMAXD()
{
	return MAX_DRAGAO;
}

int alterarDragao(int cod, Dragao d)
{
	Dragao ald;
	FILE* rodarD = fopen("novoDragao.txt", "w+b");
	
	rewind(ad);
	
	while(fread (&ald, sizeof(Dragao), 1, ad) ==1)
	{

		if(ald.codigo != d.codigo)
		{
			fwrite(&ald, sizeof(Dragao), 1, rodarD);
		}
		
		else
		{
			fwrite(&d, sizeof(Dragao), 1, rodarD);
		}
	}
	
	fclose(ad);
	
	fclose(rodarD);
	
	remove("dragao.txt");
	
	rename("novoDragao.txt", "dragao.txt");
	
	ad = fopen("dragao.txt", "r+b");

	return 1;
	
/*	int i;
	for(i = 0; i < qtdDragao; i++)
	{
		Dragao h = LtDragao[i];
		if(h.codigo == cod)
		{
			LtDragao[i] = d;
			return 1;
		}
	}
	return 0;*/
}

