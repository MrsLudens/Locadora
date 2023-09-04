#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#include "guerreiro.h"
#include "dragao.h"
#include "elemento.h"
#include "locacao.h"


// ------------ Menu principal --------------
void listarMenu()
{	
	printf(" -------------- Locadora Kaleesi -------------- \n");
	printf("\n         0. Sair               \n");
	printf("\n         1. Guerreiros         \n");
	printf("\n         2. Dragoes            \n");
	printf("\n         3. Elementos          \n");
	printf("\n         4. Locacoes           \n");
	printf("\n\n");
}

// ---------- SUB Menus ------------
void subMenuG()
{	
	printf(" -------------- Locadora Kaleesi -------------- \n");
	printf("\n       0. Sair                 \n");
	printf("\n       1. Listar guerreiros      \n");
	printf("\n       2. Cadastrar guerreiros    \n");
	printf("\n       3. Pesquisar guerreiros    \n");
	printf("\n       4. Excluir guerreiros      \n");
	printf("\n       5. Alterar guerreiros      \n");
	printf("\n\n");
}

void subMenuD()
{
	printf(" -------------- Locadora Kaleesi -------------- \n");
	printf("\n         0. Voltar              \n");
	printf("\n         1. Listar dragoes      \n");
	printf("\n         2. Cadastrar dragao    \n");
	printf("\n         3. Pesquisar dragao    \n");
	printf("\n         4. Excluir dragao      \n");
	printf("\n         5. Alterar dragao      \n");
	printf("\n\n");
}

void subMenuE()
{
	printf(" -------------- Locadora Kaleesi -------------- \n");
	printf("\n         0. Voltar                \n");
	printf("\n         1. Listar elementos      \n");
	printf("\n         2. Cadastrar elemento    \n");
	printf("\n         3. Pesquisar elemento      \n");
	printf("\n         4. Excluir elemento      \n");
	printf("\n         5. Alterar elemento     \n");
	printf("\n\n");
}

void subMenuL()
{
	
	printf(" -------------- Locadora Kaleesi -------------- \n");
	printf("\n         0. Voltar                \n");
	printf("\n         1. Listar locacoes      \n");
	printf("\n         2. Locar     \n");
	printf("\n         3. Devolver       \n");
	printf("\n         4. Pesquisar locacao      \n");
	printf("\n         5. Alterar locacao      \n");
	printf("\n\n");
}

//  ---------- Listar ------------

void listaGuerreiro()
{
	printf("\n ------- Lista de Guerreiros ------- \n");
			
	int i;
	for(i = 0; i < quantidadeGuerreiro(); i++)
	{
		guerreiro g;
		
		if(obterGuerreiroPeloIndice(i, &g) == 1)
		{
			printf("\nCodigo: %d    \nNome: %s    \nReino: %s    \nTitulo: %s \n",
				g.codigo,
				g.nome,
				g.reino,
				g.titulo);
		}
	}
	
	printf("\nCapacidade da lista: %d", RETORNAMAXG());
	printf("\n");
}

void listaDragao()
{
	printf("\n -------- Lista de dragoes -------- \n");
			
	int i;
	for(i = 0; i < quantidadeDragao(); i++)
	{
		Dragao d;
		elemento e;
		if(obterDragaoPeloIndice(i, &d) == 1)
		{
			obterElementoPeloCodigo(d.idElemento, &e);
			printf("\nCodigo: %d  \nNome: %s  \nIdade: %d   \nValor Diario:R$ %.2f  \nQuantidade em Estoque: %d \nElemento: %s \n",
			d.codigo,
			d.nome,
			d.idade,
			d.valorDiario,
			d.unidadeEstoque,
			e.nome
			);
		}
	}
	printf("\n Capacidade da lista: %d",RETORNAMAXD());
	printf("\n");
}

void listaElemento()
{
	printf("\n ------ Lista de elementos ------ \n");
			
	int i;
	for(i = 0; i < quantidadeElemento(); i++)
	{
		elemento e;
		
		if(obterElementoPeloIndice(i, &e) == 1)
		{
			printf("\nCodigo: %d  \nNome: %s  \nVulnerabilidade: %s \n",
			e.codigo,
			e.nome,
			e.vulnerabilidade);
		}
	}
	printf("\n Capacidade da lista: %d", RETORNAMAXE());
	printf("\n");
}

void ListaLocacao()
{
	printf("\n ------ Lista de Locacoes ------ \n");
	
	int i;
	for(i = 0; i < quantidadeLocado(); i++)
	{
		Locar l;
		if(obterLocacaoPeloIndice(i, &l) == 1)
		{
			guerreiro g;
			obterGuerreiroPeloCodigo(l.codGuerreiro, &g);
			Dragao d;
			obterDragaoPeloCodigo(l.codDragao, &d);
			
			printf("\nCodigo: %d \nDragao: %s \nGuerreiro: %s \nData locacao: %s \nData devolucao: %s \nPago: %s \n",
			l.codigo,
			d.nome,
			g.nome,
			l.inicioLocacao,
			l.finalLocacao,
			l.pago);
		}
	}
	printf("\n Capacidade da lista: %d", RETORNAMAXL());
	printf("\n");
	
}

// ------------- Guerreiro ------------

void cadastrarGuerreiros()
{
	
	printf("\n ------- Cadastrar guerreiro ------- \n");
		
	guerreiro g;
		
	printf("\nDigite o nome do guerreiro: \n");
	fflush(stdin);
	scanf("%[^\n]s", g.nome);
		
	printf("\nDigite o reino do guerreiro: \n");
	fflush(stdin);
	scanf("%[^\n]s", g.reino);
		
	printf("\nDigite o titulo do guerreiro: \n");
	fflush(stdin);
	scanf("%[^\n]s", g.titulo);
		
	if(cadastrarGuerreiro(g) == 1)
	{
		printf("\nGuerreiro cadastrado com sucesso! \n");
		aumentarTamanhoG();
		system("pause");
	}
	else
	{
		printf("\nNao foi possivel cadastrar o guerreiro! \n");
		system("pause");
	}
}

void pesquisarGuerreiro()
{
	printf("\n ------ Pesquisar Guerreiro ------ \n");
	int codigoGuerreiro;
		
	printf("\nDigite o codigo do guerreiro a ser pesquisado: \n");
	scanf("%d", &codigoGuerreiro);
			
	guerreiro g;
			
	if(obterGuerreiroPeloCodigo(codigoGuerreiro, &g) == 1)
	{
		printf("\nCodigo: %d ||| Nome: %s ||| Reino: %s ||| Titulo: %s \n",
		g.codigo,
		g.nome,
		g.reino,
		g.titulo);
	}
	else
	{
		printf("\nGuerreiro nao encontrado! \n");
	}
	system("pause");
	system("cls");
}

void excluiGuerreiro()
{
	printf("\n ------ Excluir Guerreiro ------ \n");
	listaGuerreiro();
	int codigo;
	printf("\nDigite o codigo do guerreiro que deseja excluir: \n");
	scanf("%d", &codigo);
	
	int ok = 0;
	int i;
	
	for(i = 0; i <= quantidadeLocado(); i++)
	{
		Locar y;
		obterLocacaoPeloCodigo(i, &y);
		if(y.codGuerreiro == codigo)
		{
			printf("Guerreiro possui locacao ativa! Nao eh possivel excluir o guerreiro!");
			ok++;
			break;
		}
	}
	if(ok == 0)
	{
		if(excluirGuerreiroPeloCodigo(codigo) == 1)
		{
			printf("\nGuerreiro excluido com sucesso!\n");
			reduzirTamanhoG();
		}
	}
	else
	{
		printf("\nFalha ao excluir guerreiro!\n");
	}
	
	system("pause");
	system("cls");
}

void alteraGuerreiro()
{
	printf("\n ------ Alterar Guerreiro ------ \n");
	listaGuerreiro();
	int resposta;
	int resposta2;
	
	printf("\nDigite o codigo do guerreiro que deseja alterar: ");
	scanf("%d", &resposta);
	system("cls");
	
	guerreiro g;
	if(obterGuerreiroPeloCodigo(resposta, &g) == 1)
	{
		printf("\nCodigo: %i    \nNome: %s    \nReino: %s    \nTitulo: %s \n",
				g.codigo,
				g.nome,
				g.reino,
				g.titulo);
		printf("O que deseja alterar? \n1 - Nome \n2 - Reino \n3 - Titulo\n");
		scanf("%d", &resposta2);
		
		switch(resposta2)
		{
			case 1:
				printf("\nDigite o nome: ");
				fflush(stdin);
				scanf("%[^\n]s", g.nome);
				break;
			case 2:
				printf("\nDigite o reino: ");
				fflush(stdin);
				scanf("%[^\n]s", g.reino);
				break;
			case 3:
				printf("\nDigite o titulo: ");
				fflush(stdin);
				scanf("%[^\n]s", g.titulo);
				break;
		}
		if(alterarGuerreiro(g.codigo, g) == 1)
		{
			printf("\nO guerreiro %s foi alterado com sucesso!\n", g.nome);
			system("pause");
		}
		else
		{
			printf("\nFalha na alteracao!\n");
			system("pause");
		}
		
	}
	else
	{
		printf("\nCodigo nao encontrado!\n");
		system("pause");
	}
}

// ------------- Dragao ------------

void cadastraDragao()
{
	
	printf("\n ------ Cadastrar dragao ------ \n");
		
	Dragao d;
			
	printf("\nDigite o nome do dragao: \n");
	fflush(stdin);
	scanf("%[^\n]s", d.nome);
		
	printf("\nDigite a idade do dragao: \n");
	scanf("%d", &d.idade);
		
	printf("\nDigite valor do aluguel diario do drag?o: \n");
	scanf("%f", &d.valorDiario);
		
	printf("\nDigite a quantidade de dragao cadastrado: \n");
	scanf("%d", &d.unidadeEstoque);
	
	//Cadastra e atribuir elemento
	
	listaElemento();
	
	int res;	
	printf("\nDigite o codigo do elemento do dragao\n");
	scanf("%d", &res);
	
	elemento e;
	int encontrado = 0;
	
	if(obterElementoPeloCodigo(res, &e) == 1)
	{
		d.idElemento == res;
		encontrado++;
	}
	else
	{
		printf("\nCodigo nao encontrado!\n");
	}
	if(cadastrarDragao(d, encontrado) == 1)
	{
		printf("\nDragao cadastrado com sucesso!");
		aumentarTamanhoD();
		system("pause");
	}
	else
	{
		printf("\nFalha ao cadastrar!\n");
		system("pause");
	}
	system("cls");
	
}

void pesquisarDragao()
{
	printf("\n ------ Pesquisar dragao ------ \n");
	
	int codigoDragao;		
	printf("\nDigite o codigo do dragao a ser pesquisado: \n");
	scanf("%d", &codigoDragao);
			
	Dragao d;
	elemento e;
	if(obterDragaoPeloCodigo(codigoDragao, &d) == 1)
	{
		obterElementoPeloCodigo(d.idElemento, &e);
		printf("\nCodigo: %d ||| Nome: %s ||| Idade: %d ||| Valor Diario: %.2f ||| Quantidade em Estoque: %d ||| Elemento: %s\n",
		d.codigo,
		d.nome,
		d.idade,
		d.valorDiario,
		d.unidadeEstoque,
		e.nome);
	}		
	else
	{
		printf("\nDragao nao encontrado! \n");
	}
	
	system("pause");
	system("cls");
}

void excluiDragao()
{
	printf("\n ------ Excluir dragao ------ \n");
	listaDragao();
	int codigo;
	
	printf("\nDigite o codigo do dragao que deseja excluir: \n");
	scanf("%d", &codigo);
	
	int ok = 0;
	int i;
	
	for(i = 0; i <= quantidadeLocado(); i++)
	{
		Locar y;
		obterLocacaoPeloCodigo(i, &y);
		
		if(y.codDragao == codigo)
		{
			printf("\nEste dragao esta locado! Nao eh possivel excluir!\n");
			ok++;
			break;
		}
	}
	if(ok == 0)
	{
		if(ApagarDragaoPeloCodigo(codigo) == 1)
		{
			printf("\nDragao apagado com sucesso!\n");
			reduzirTamanhoD();
		}
	}
	else
	{
		printf("\nFalha ao apagar o dragao!\n");
	}
	
	system("pause");
	system("cls");

}

void alteraDragao()
{
	printf("\n ------ Alterar dragao ------ \n");
	listaDragao();
	int resposta;
	int resposta2;
	
	printf("\nDigite o codigo do dragao que deseja alterar: ");
	scanf("%d", &resposta);
	system("cls");
	
	Dragao d;
	if(obterDragaoPeloCodigo(resposta, &d) == 1)
	{
		elemento e;
		obterElementoPeloCodigo(d.idElemento, &e);
		
		printf("\nCodigo: %d  \nNome: %s  \nIdade: %d   \nValor Diario:R$ %.2f  \nQuantidade em Estoque: %d \nElemento: %s \nVulnerabilidade Elemento: %s \n",
			d.codigo,
			d.nome,
			d.idade,
			d.valorDiario,
			d.unidadeEstoque,
			e.nome,
			e.vulnerabilidade);
		printf("\n1 - Nome \n2 - Idade \n3 - Valor diario \n4 - Estoque \n5 - Elemento \nO que voce deseja alterar?\n");
		scanf("%d", &resposta2);
		
		switch(resposta2)
		{
			case 1:
				printf("\nDigite o nome: ");
				fflush(stdin);
				scanf("%[^ \n]s", d.nome);
				break;
			case 2:
				printf("\nDigite a idade: ");
				fflush(stdin);
				scanf("%d", &d.idade);
				break;
			case 3:
				printf("\nDigite o valor da diaria: ");
				fflush(stdin);
				scanf("%f", &d.valorDiario);
				break;
			case 4:
				printf("\nDigite as unidades em estoque: ");
				fflush(stdin);
				scanf("%d", &d.unidadeEstoque);
				break;
			case 5:
				printf("\nDigite o codigo do elemento: ");
				fflush(stdin);
				scanf("%d", &d.idElemento);
				break;
		}
		
		if(alterarDragao(d.codigo, d) == 1)
		{
			printf("\nO dragao %s foi alterado com sucesso!\n", d.nome);
			system("pause");
		}
		else
		{
			printf("\nFalha ao alterar!");
			system("pause");
		}
	}
	else
	{
		printf("\nCodigo nao encontrado!\n");
		system("pause");
	}
	
}

// ------------- Elemento ------------

void cadastraElemento()
{
	
	printf("\n ------ Cadastrar elementos ------ \n");
		
	elemento e;	
	printf("\nDigite o nome do elemento: \n");
	fflush(stdin);
	scanf("%[^\n]s", e.nome);
		
	printf("\nDigite a vulnerabilidade do elemento: \n");
	fflush(stdin);
	scanf("%[^\n]s", e.vulnerabilidade);
		
	if(cadastrarElemento(e) == 1)
	{
		printf("\nElemento cadastrado com sucesso! \n");
		aumentarTamanhoE();
		system("pause");
	}
	else
	{
		printf("\nNao foi possivel cadastrar o elemento! \n");
		system("pause");
	}
	system("cls");
}

void pesquisarElemento()
{
	printf("\n ------ Pesquisar elementos ------ \n");
	int codigoElemento;
		
	printf("\nDigite o codigo do elemento a ser pesquisado: \n");
	scanf("%d", &codigoElemento);
			
	elemento e;
			
	if(obterElementoPeloCodigo(codigoElemento, &e) == 1)
	{
		printf("\nCodigo: %d ||| Nome: %s ||| Vulnerabilidade %s \n",
		e.codigo,
		e.nome,
		e.vulnerabilidade);
	}
	else
	{
		printf("\nCodigo nao encontrado!\n");
	}
	system("pause");
	system("cls");
}

void excluiElemento()
{
	printf("\n ------ Excluir elementos ------ \n");
	
	listaElemento();
	int codigo;
	
	printf("\nDigite o codigo do elemento que deseja excluir: \n");
	scanf("%d", &codigo);
	
	int ok = 0;
	int i;
	
	for(i = 0; i <= quantidadeDragao(); i++)
	{
		Dragao y;
		obterDragaoPeloCodigo(i, &y);
		if(y.idElemento == codigo)
		{
			printf("Existem dragoes deste elemento com cadastro ativo!\nApagar os dragoes primeiro!\n");
			ok++;
			break;
		}
	}
	
	if(ok == 0)
	{
		if(ApagarElementoPeloCodigo(codigo) == 1)
		{
			printf("\nElemento apagado com sucesso!\n");
			reduzirTamanhoE();
		}
	}
	else
	{
		printf("\nFalha ao apagar o elemento!\n");
	}
	
	system("pause");
	system("cls");

}

void alteraElemento()
{
	printf("\n ------ Alterar elementos ------ \n");
	
	listaElemento();
	int resposta;
	int resposta2;
	
	printf("\nDigite o codigo do elemento que deseja alterar: ");
	scanf("%d", &resposta);
	system("cls");
	
	elemento e;
	if(obterElementoPeloCodigo(resposta, &e) == 1)
	{
		printf("\nCodigo: %d  \nNome: %s  \nVulnerabilidade: %s \n",
			e.codigo,
			e.nome,
			e.vulnerabilidade);
		printf("\n1 - Nome \n2 - Vulnerabilidade \nO que voce deseja alterar? ");
		scanf("%d", &resposta2);
		
		switch(resposta2)
		{
			case 1:
				printf("\nDigite o nome: ");
				fflush(stdin);
				scanf("%[^\n]s", e.nome);
				break;
			case 2:
				printf("\nDigite a vulnerabilidade: ");
				fflush(stdin);
				scanf("%[^\n]s", e.vulnerabilidade);
				break;
		}
		if(alterarElemento(e.codigo, e) == 1)
		{
			printf("\nElemento alterado com sucesso!\n");
			system("pause");
		}
		else
		{
			printf("\nFalha ao alterar!\n");
			system("pause");
		}
	}
	else
	{
		printf("\nCodigo nao encontrado!\n");
		system("pause");
	}
	
}

// ------------- Locacao ------------

void Aluga()
{
	printf("\n ------ Locacao ------ \n");
	
	listaGuerreiro();
	
	Locar l;
	
	printf("\nDigite o codigo do guerreiro: ");
	scanf("%d", &l.codGuerreiro);
	system("cls");
	
	listaDragao();
	
	printf("\nDigite o codigo do dragao que ira alugar: ");
	scanf("%d", &l.codDragao);
	system("cls");
	
	printf("\nDigite a data da retirada do dragao: ");
	fflush(stdin);
	scanf("%[^\n]s", l.inicioLocacao);
	
	printf("\nDigite a data da entrega do dragao: ");
	fflush(stdin);
	scanf("%[^\n]s", l.finalLocacao);
	
	printf("\nO pagamento esta realizado? S - sim | N - nao : ");
	fflush(stdin);
	scanf("%[^\n]s", l.pago);
	
	if(salvarLocacao(l) == 1 && diminuirUnidade(l.codDragao) == 1)
	{
		printf("\nA locacao foi realizada com sucesso!\n");
		aumentarTamanhoL();
		system("pause");
	}
	else
	{
		printf("\nFalha ao realizar a locacao!\n");
		system("pause");	
	}
	system("cls");
}

void devolver()
{
	printf("\n ------ Devolver Locacao ------ \n");
	ListaLocacao();
	int cod;

	printf("\nDigite o codigo do dragao que ira devolver: ");
	scanf("%d", &cod);
	
	Locar l;
	obterLocacaoPeloCodigo(cod, &l);
	int codDrag = l.codDragao;
	if(ApagarLocacaoPeloCodigo(cod) == 1 && aumentarUnidadeDrag(codDrag) == 1)
	{
		printf("\nDragao devolvido com sucesso!\n");
		reduzirTamanhoL();
	}
	else
	{
		printf("\nFalha ao devolver!\n");
	}
	system("pause");
	system("cls");
}

void pesquisarLocacao()
{
	printf("\n ------ Pesquisar Locacao ------ \n");
	int resposta;
	printf("\nDigite o codigo da locacao a ser pesquisada: ");
	scanf("%d", &resposta);
	
	Locar l;
	if(obterLocacaoPeloCodigo(resposta, &l) == 1)
	{
		guerreiro g;
		Dragao d;
		obterGuerreiroPeloCodigo(l.codGuerreiro, &g);
		obterDragaoPeloCodigo(l.codDragao, &d);
		
		printf("\nCodigo: %d ||| Guerreiro: %s ||| Dragao: %s ||| Inicio: %s ||| Fim: %s ||| Pago: %s \n",
		l.codigo,
		g.nome,
		d.nome,
		l.inicioLocacao,
		l.finalLocacao,
		l.pago);	
	}
	else
	{
		printf("\nCodigo nao encontrado!\n");
	}
	system("pause");
	system("cls");
	
}

void alteraLocacao()
{
	printf("\n ------ Altera Locacao ------ \n");
	ListaLocacao();
	
	int resposta;
	int resposta2;
	printf("\nDigite o codigo da locacao que deseja alterar: ");
	scanf("%d", &resposta);
	system("cls");
	
	Locar l;
	if(obterLocacaoPeloCodigo(resposta, &l) == 1)
	{
		guerreiro g;
		obterGuerreiroPeloCodigo(l.codGuerreiro, &g);
		Dragao d;		
		obterDragaoPeloCodigo(l.codDragao, &d);
		
		printf("\nCodigo: %d \nDragao: %s \nGuerreiro: %s \nData locacao: %s \nData devolucao: %s \n Pago: %s \n",
			l.codigo,
			d.nome,
			g.nome,
			l.inicioLocacao,
			l.finalLocacao,
			l.pago);
		printf("\n1 - Inicio Locacao \n2 - Fim da Locacao \n3 - Pago \nO que deseja alterar? ");
		scanf("%d", &resposta2);
		
		switch(resposta2)
		{
			case 1:
				printf("\nDigite o inicio da locacao: ");
				fflush(stdin);
				scanf("%[^\n]s", l.inicioLocacao);
				break;
			case 2:
				printf("\nDigite o fim da locacao: ");
				fflush(stdin);
				scanf("%[^\n]s", l.finalLocacao);
				break;
			case 3:
				printf("\nO pagamento foi realizado? ");
				fflush(stdin);
				scanf("%[^\n]s", l.pago);
				break;
		}
		if(alterarLocacao(l.codigo, l) == 1)
		{
			printf("\nA locacao foi alterada com sucesso!\n");
			system("pause");
		}
		else
		{
			printf("\nFalha na alteracao!\n");
			system("pause");
		}
		
	}
	else
	{
		printf("\nCodigo nao encontrado!\n");
		system("pause");
	}
	
		
}


int main(int argc, char *argv[]) 
{
	
	inicializarGuerreiro();
	inicializarDragao();
	inicializarElemento();
	inicializarLocacao();
	
	int menu;
	int codG, codD, codE, codL;
	
	do
	{
		listarMenu();
		scanf("%d", &menu);
		system("cls");	
		switch(menu)
		{
			case 1:
				do
				{
					//SUB MENU GUERREIRO
					subMenuG();
					scanf("%d", &codG);
					switch(codG)
					{
						case 1:
							listaGuerreiro();
							system("pause");
							break;
						case 2:
							cadastrarGuerreiros();
							break;
						case 3:
							pesquisarGuerreiro();
							break;
						case 4:
							excluiGuerreiro();
							break;
						case 5:
							alteraGuerreiro();
							break;
					}
					system("cls");
				}while(codG != 0);
			break;
			case 2:	
				system("cls");	
				do
				{
					//SUB MENU DRAGAO
					subMenuD();
					scanf("%d", &codD);
					system("cls");
					switch(codD)
					{
						case 1:
							listaDragao();
							system("pause");
							break;
						case 2:
							cadastraDragao();
							break;
						case 3:
							pesquisarDragao();
							break;
						case 4:
							excluiDragao();
							break;
						case 5:
							alteraDragao();
							break;
					} system("cls");
				}while(codD != 0);
			break;
					
			case 3:
				do
				{
					//SUB MENU ELEMENTO
					subMenuE();
					scanf("%d", &codE);
					switch(codE)
					{
						case 1:
							listaElemento();
							system("pause");
							break;
						case 2:
							cadastraElemento();
							break;
						case 3:
							pesquisarElemento();
							break;
						case 4:
							excluiElemento();
							break;
						case 5:
							alteraElemento();
							break;
					} system("cls");
				}while(codE != 0);
			break;
			
			case 4:
				do
				{
					//SUB MENU LOCACAO
					subMenuL();
					scanf("%d", &codL);
					switch(codL)
					{
						case 1:
							ListaLocacao();
							system("pause");
							break;
						case 2:
							Aluga();
							break;
						case 3:
							devolver();
							break;
						case 4:
							pesquisarLocacao();
							break;
						case 5:
							alteraLocacao();
							break;
					}system("cls");
				}while(codL != 0);
				break;
				
		}
		
	}while(menu != 0);	
	
	//Encerrar
	encerraGuerreiros();
	encerraDragao();
	encerraElemento();
	encerraLocacao();
	printf("\nVolte sempre!\n");
	
	return 0;
}


