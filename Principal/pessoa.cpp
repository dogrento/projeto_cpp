#include <string.h> 
#include <iostream> 
using std::cout;
using std::endl;
#include "pessoa.h"
	
/*
 * Construtor
 *
 * */
void Pessoa::Init(int diaNasc, int mesNasc, int anoNasc,const char nomeP[]){
	dia_pessoa = diaNasc;
	mes_pessoa = mesNasc;
	ano_pessoa = anoNasc;
	idade_pessoa = 0;
	strcpy(nome_pessoa, nomeP);
}

Pessoa::Pessoa(int diaNasc, int mesNasc, int anoNasc, const char nomeP[]){
	Init(diaNasc, mesNasc, anoNasc, nomeP);
}

Pessoa::Pessoa(){
	Init(0, 0, 0);
}


/*Calcula a idade considerando a data atual
 *
 * params: note que não precisa passar o tipo pessoa no param
 * 	   int dia atual
 * 	   int mes atual
 * 	   int ano atual					
 *
 * return: função com passsagem por referencia*
 *
 * */

void Pessoa::calcula_idade(int diaAtual, int mesAtual, int anoAtual){
	
	//o campo idade apontado por p recebe:
	idade_pessoa = anoAtual - ano_pessoa;
	
	// se o mes do aniversário da pessoa for maior que o atual,
	if(mes_pessoa > mesAtual){
		// ele nao fez aniversario ainda
		idade_pessoa = idade_pessoa - 1;
	}
	// caso contrario o aniversario vai depender do dia do mes
	else{
		//se o mes da pessoa for igual ao atual,
		if(mes_pessoa == mesAtual){
			// se o dia da pessoa for > que o dia atual,
			if(dia_pessoa > diaAtual){
				// nao fez aniversario ainda
				idade_pessoa = idade_pessoa - 1;
			}
		}
	print_info(idade_pessoa, nome_pessoa);		
	}
}

int Pessoa::getIdade(){
	return idade_pessoa;
}

void Pessoa::print_info(int idade, char nome[]){
	cout << "Pessoa: " << nome_pessoa << ", Idade: " << idade_pessoa << endl;
}