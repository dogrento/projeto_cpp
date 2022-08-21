/*
 *
 * 
 * INTRODUÇÃO AO C++
 * 
 * PARA COMPILAR C++, USAR g++ -o nome.c outro.h ...
 *
 * NOTE QUE A FUNÇÃO MAIN ESTÁ DIMINUIDO
 *
 *
 * 
 * */



#include <stdio.h>

/*
 *Criando class PRIVADA com função ja dentro dele (principio de OO)
 *
 * criando CONSTRUCT: construct inicializa variável
 * 
 * note mudanças em relação ao C
 *
 * */
class Pessoa{
	
	// indicar que struct será publica (pode ser acessada por todo o projeto)
	// não é recomendado declarar atributos(variaveis) de forma publica.
	private:

	//declarando atributos da classe Pessoa
	int dia,
	    mes,
	    ano,
	    idade;
	
	char nome[30];

	/*
	 *METODOS DA CLASSE
	 * 
	 * CHAMANDO OS METODOS QUE ESTAO DEFINIDOS EM PESSOA_CLASS.CPP
	 *
	 * 
	 * */

	public:
	
	// contructor
	// com parametros default, *note, valores default de params aparecem na assinatura 
	// do metodo (no arquivo .h e não em sua implementação (.cpp))
	Pessoa(int diaNasc, int mesNasc, int anoNasc, const char nameP[] = "");

	// Toda classe deve ter uma função-membro  contrutora sem parametro;
	Pessoa();
	void Init(int diaNasc, int mesNasc, int anoNasc,const char nomeP[] = "");
	
	// metodos gerais
	void calcula_idade(int diaAtual, int mesAtual, int anoAtual);
	int getIdade();
	void print_info(int idade, char nome[]);
} ;

