struct strGuerreiro
{
	int codigo;
	char nome[20];
	char reino[20];
	char titulo[20];
};

typedef struct strGuerreiro guerreiro;

int inicializarGuerreiro();
int encerraGuerreiros(); 
int cadastrarGuerreiro(guerreiro g);
int quantidadeGuerreiro();
int obterGuerreiroPeloIndice(int indice, guerreiro* g);
int obterGuerreiroPeloCodigo(int codigo, guerreiro* g);
int excluirGuerreiroPeloCodigo(int codigo);
int aumentarTamanhoG();
int reduzirTamanhoG();
int RETORNAMAXG();
int alterarGuerreiro(int codigo, guerreiro g);



