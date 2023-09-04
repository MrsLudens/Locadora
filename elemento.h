struct strElemento
{
	int codigo;
	char nome[20];
	char vulnerabilidade[20];
};

typedef struct strElemento elemento;

int inicializarElemento();
int encerraElemento(); 
int cadastrarElemento(elemento e);
int quantidadeElemento();
int obterElementoPeloIndice(int indice, elemento* e);
int obterElementoPeloCodigo(int codigo, elemento* e);
int ApagarElementoPeloCodigo(int codigo);
void listarElemento();
int aumentarTamanhoE();
int reduzirTamanhoE();
int RETORNAMAXE();
int alterarElemento(int codigo, elemento e);




