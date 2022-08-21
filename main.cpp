/*
 *
 * 
 * INTRODUÇÃO AO C++
 * 
 * PARA COMPILAR C++, USAR g++ 
 *
 * NOTE QUE A FUNÇÃO MAIN ESTÁ DIMINUIDO
 * 
 * */

//importando arquivo.h onde está struct com constructor
#include <stdio.h>
#include "pessoa_class.h"


int main(){

	// puxando a construct, inicializa a var passado os valores certos como parametros
	Pessoa douglas(13,02,1993, "Douglas Seiji Oshiro");
	Pessoa einstein(13,3,1879, "Albert Einstein");
	Pessoa newton(4,1,1643, "Isaac Newton");

	int diaAtual = 15,
	    mesAtual = 9,
	    anoAtual = 2022;

	// criando um objeto pessoa
	einstein.calcula_idade(diaAtual, mesAtual, anoAtual);
	newton.calcula_idade(diaAtual, mesAtual, anoAtual);
	
	printf("resultado usando construct e com a função junto da struct privada. \n");
	//printf("einstein : %d\n", einstein.idade);
	//printf("newton : %d", newton.idade);
	//printf("einstein: %d\n", einstein.getIdade());
	//printf("newton: %d\n", newton.getIdade());

	// não sei para o que serve exatamente
	getchar();

	return 0;
}
