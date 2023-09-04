#include "elemento.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "dragao.h"
#include "guerreiro.h"

int MAX_ELEMENTO = 5;
int qtdElemento = 0;
int codAtualE = 1;

elemento *LtElemento;
FILE * ae;

int inicializarElemento()
{
	
	ae = fopen ("elemento.txt", "r+b");
	if(ae == NULL)
	{
		printf("\nErro na abertura do arquivo!\n");
		system("pause");
		exit(1);
	}
	fseek (ae,0, SEEK_END);
	int recebe = ftell(ae);
	qtdElemento= recebe/sizeof(elemento);
	fseek(ae,0, SEEK_SET);
	
	int i;
	
	elemento e;
	
	for(i = 0; i < qtdElemento; i++)
	{
		fread(&e, sizeof(elemento), 1, ae);
		if(e.codigo > codAtualE)
		{
			codAtualE = e.codigo;
		}
	}
	codAtualE++;
	printf("\nCodigo atual: %d", codAtualE);
	printf("\nQuantidade de dragoes: %d", qtdElemento);
	printf("\n");

//	LtElemento = (elemento*) malloc (MAX_ELEMENTO * sizeof(elemento));
//	if(LtElemento == NULL)
//	{
//		return 0;
//	}
//	
//	int i;
//	for(i = 0; i < MAX_ELEMENTO; i++)
//	{
//		strcpy(LtElemento[i].nome, "");
//		strcpy(LtElemento[i].vulnerabilidade, "");
//		LtElemento[i].codigo = 0;
//	}
//
//	strcpy(LtElemento[0].nome, "Destruicao");
//	strcpy(LtElemento[0].vulnerabilidade, "Indestrutivel");
//	LtElemento[0].codigo = codAtualE;
//	qtdElemento++;
//	codAtualE++;
//	
//	strcpy(LtElemento[1].nome, "Fofura");
//	strcpy(LtElemento[1].vulnerabilidade, "Chatisse");
//	LtElemento[1].codigo = codAtualE;
//	qtdElemento++;
//	codAtualE++;
}

int encerraElemento()
{
	fclose(ae);
//	free(LtElemento);
}

int cadastrarElemento(elemento e)
{
	e.codigo = codAtualE;
	
	fseek(ae, 0, SEEK_END);
	fwrite(&e, sizeof(elemento), 1, ae);
	qtdElemento++;
	
	return 1;
//	if(qtdElemento < MAX_ELEMENTO)
//	{
//		e.codigo = codAtualE++;
//		LtElemento[qtdElemento] = e;
//		qtdElemento++;
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}		
}

int quantidadeElemento()
{
	return qtdElemento;
}

int obterElementoPeloIndice(int indice, elemento* e)
{
	elemento ei;
	
	rewind(ae);
	fseek(ae, indice* sizeof(elemento), SEEK_SET);
	fread(&ei, sizeof(elemento), 1, ae);
	*e = ei;
	
	return 1;
//	*e = LtElemento[indice];
//	return 1;
}

int obterElementoPeloCodigo(int codigo, elemento* e)
{
	elemento ec;
	rewind(ae);
	fseek(ae, 0, SEEK_CUR);
	int i;
	
	for(i = 0; i < qtdElemento; i++)
	{
		fread(&ec, sizeof(elemento), 1, ae);
		if(codigo == ec.codigo);
		{
			*e = ec;
			return 1;
		}
	}
//	int i;
//	for(i = 0; i < qtdElemento; i++)
//	{
//		*e = LtElemento[i];
//		if(e->codigo == codigo)
//		{
//			return 1;
//		}
//	}
//	return 0;
		
}

int ApagarElementoPeloCodigo(int codigo)
{
	FILE *excluirE;
	elemento exe;
	
	
	excluirE = fopen("novoE.txt", "w+b");
	
	rewind(ae);
	
	if(ae == NULL || excluirE == NULL)
	{
		printf("\nErro na abertura do arquivo!\n");
		system("pause");
	}
		
	else
	{
		fflush(ae);
			
		while(fread(&exe, sizeof(elemento), 1, ae) == 1)
		{
			if(codigo != exe.codigo)
			{
				fwrite(&exe, sizeof(elemento), 1, excluirE);
				codAtualE--;
			}
		}
	}
		
	fclose(ae);
	
	fclose(excluirE);
		
	remove("elemento.txt");
		
	rename("novoE.txt", "elemento.txt");
		
	ae = fopen("elemento.txt", "r+b");
		
	return 1;
	
/*	int i;
	for(i = 0; i < qtdElemento; i++)
	{
		if(LtElemento[i].codigo == codigo)
		{
			LtElemento[i] = LtElemento[qtdElemento-1];
			LtElemento[qtdElemento-1].codigo = 0;
			qtdElemento--;
			return 1;
		}
	}*/
	return 0; // caso falhe
}

int aumentarTamanhoE()
{
/*	if(qtdElemento == MAX_ELEMENTO)
	{
		MAX_ELEMENTO +=2;
		elemento* novaListaE = (elemento*) realloc (LtElemento, MAX_ELEMENTO * sizeof(elemento));
		if(novaListaE != NULL)
		{
			LtElemento = novaListaE;
			free(novaListaE);
			novaListaE = NULL;
			return 1;
		}
	}*/
}

int reduzirTamanhoE()
{
/*	if(qtdElemento < (MAX_ELEMENTO * 0.4))
	{
		MAX_ELEMENTO = qtdElemento +2;
		elemento* novaListaEL = (elemento*) realloc (LtElemento, MAX_ELEMENTO * sizeof(elemento));
		if(novaListaEL != NULL)
		{
			LtElemento = novaListaEL;
			free(novaListaEL);
			novaListaEL = NULL;
			return 1;
		}
	}*/
}

int RETORNAMAXE()
{
	return MAX_ELEMENTO;
}

int alterarElemento(int codigo, elemento e)
{
	elemento ale;
		
	FILE* rodarE = fopen("novoElemento.txt", "w+b");
	
	rewind(ae);
	
	while(fread (&ale, sizeof(elemento), 1, ae) ==1)
	{

		if(ale.codigo != e.codigo)
		{
			fwrite(&ale, sizeof(elemento), 1, rodarE);
		}
		
		else
		{
			fwrite(&e, sizeof(elemento), 1, rodarE);
		}
	}
	
	fclose(ae);
	
	fclose(rodarE);
	
	remove("elemento.txt");
	
	rename("novoElemento.txt", "elemento.txt");
	
	ae = fopen("elemento.txt", "r+b");

	return 1;
/*	int i;
	for(i = 0; i < qtdElemento; i++)
	{
		elemento h = LtElemento[i];
		if(h.codigo == codigo)
		{
			LtElemento[i] = e;
			return 1;
		}
	}*/
	return 0;
}

