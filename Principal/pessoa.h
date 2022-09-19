#ifndef _PESSOA_H_
#define _PESSOA_H_

#include <string.h>

class Pessoa{
	
	// não é recomendado declarar atributos(variaveis) de forma publica.
	protected:

		//declarando atributos da classe Pessoa
		int dia_pessoa,
			mes_pessoa,
			ano_pessoa,
			idade_pessoa,
			id;
		
		char nome_pessoa[30];

	/*
	 *METODOS DA CLASSE
	 * 
	 * METODOS QUE ESTAO DEFINIDOS EM PESSOA_CLASS.CPP
	 *
	 * 
	 * */

	public:
		
		// contructor
		// com parametros default, *note, valores default de params aparecem na assinatura 
		// do metodo (no arquivo .h e não em sua implementação (.cpp))
		Pessoa(int diaNasc, int mesNasc, int anoNasc, const char nomeP[] = "");

		// Toda classe deve ter uma função-membro  contrutora sem parametro;
		Pessoa();
		void Init(int diaNasc, int mesNasc, int anoNasc,const char nomeP[] = "");
		
		// metodos gerais
		void calcula_idade(int diaAtual, int mesAtual, int anoAtual);
		int Get_idade();

		void Set_id(int i) { id = i;}
		int Get_id(){return id;}

		void Set_nome(char* nome){strcpy(nome_pessoa, nome);}
		char* Get_nome(){return nome_pessoa;}
} ;

#endif
