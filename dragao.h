struct strDragao
{
	int codigo;
	char nome[20];
	int idade;
	float valorDiario;
	int unidadeEstoque;
	int idElemento;
};

typedef struct strDragao Dragao;

int inicializarDragao();
int encerraDragao(); 
int cadastrarDragao(Dragao d, int encontrado);
int quantidadeDragao();
int obterDragaoPeloIndice(int indice, Dragao* d);
int obterDragaoPeloCodigo(int codigo, Dragao* d);
int ApagarDragaoPeloCodigo(int codigo);
int diminuirUnidade(int codigo);
int aumentarUnidadeDrag(int codigo);
int aumentarTamanhoD();
int reduzirTamnhoD();
int RETORNAMAXD();
int alterarDragao(int cod, Dragao d);


