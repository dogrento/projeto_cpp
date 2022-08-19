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

void calcula_idade(int diaAtual, int mesAtual, int anoAtual){
	
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
	}
}

int getIdade(){
	return idade ;
}

