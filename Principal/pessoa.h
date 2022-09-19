#ifndef _PESSOA_H_
#define _PESSOA_H_

#include <stdio.h>
//#include "universidade.h" 
//#include "departamento.h"

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

	// referencia ao objeto associado (Universidade)
//	Universidade* pUnivFiliado; 
//	Departamento* pDptoFiliado;

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
	int getIdade();
	void print_info(int idade, char nome[]);
} ;

#endif
