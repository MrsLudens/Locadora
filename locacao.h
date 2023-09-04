struct strLocacao
{
	int codigo;
	char pago[10];
	char inicioLocacao[20];
	char finalLocacao[20];
	int codGuerreiro;
	int codDragao;
};

typedef struct strLocacao Locar;

int inicializarLocacao(); 
int encerraLocacao();
int salvarLocacao(Locar l);
int quantidadeLocado();
int obterLocacaoPeloIndice(int indice, Locar* l);
int obterLocacaoPeloCodigo(int codigo, Locar* l);
int ApagarLocacaoPeloCodigo(int cod);
int aumentarTamanhoL();
int reduzirTamanhoL();
int RETORNAMAXL();
int alterarLocacao(int cod, Locar l);


