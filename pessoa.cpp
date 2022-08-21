/*
 *
 * 
 * INTRODUÇÃO AO C++
 * 
 * PARA COMPILAR C++, USAR g++ -o nome.c outro.h ...
 *
 * NOTE QUE A FUNÇÃO MAIN ESTÁ DIMINUIDO
 * */



#include "pessoa_class.h"
#include <string.h> 
#include <iostream> 
using std::cout;
using std::endl;
	
/*
 * Construtor
 *
 * */
void Pessoa::Init(int diaNasc, int mesNasc, int anoNasc,const char nomeP[]){
	dia = diaNasc;
	mes = mesNasc;
	ano = anoNasc;
	idade = 0;
	strcpy(nome, nomeP);
}

Pessoa::Pessoa(int diaNasc, int mesNasc, int anoNasc, const char nome[]){
	Init(diaNasc, mesNasc, anoNasc, nome);
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
	idade = anoAtual - ano;
	
	// se o mes do aniversário da pessoa for maior que o atual,
	if(mes > mesAtual){
		// ele nao fez aniversario ainda
		idade = idade - 1;
	}
	// caso contrario o aniversario vai depender do dia do mes
	else{
		//se o mes da pessoa for igual ao atual,
		if(mes == mesAtual){
			// se o dia da pessoa for > que o dia atual,
			if(dia > diaAtual){
				// nao fez aniversario ainda
				idade = idade - 1;
			}
		}
	print_info(idade, nome);		
	}
}

int Pessoa::getIdade(){
	return idade ;
}

void Pessoa::print_info(int idade, char nome[]){
	cout << "Pessoa: " << nome << ", Idade: " << idade << endl;
}
