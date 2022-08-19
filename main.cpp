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
//#include "pessoa_public.h"
#include "pessoa_private.h"


int main(){

	// puxando a construct, inicializa a var passado os valores certos como parametros
	Pessoa einstein(13,3,1879);
	Pessoa newton(4,1,1643);

	int diaAtual = 15,
	    mesAtual = 9,
	    anoAtual = 2022;

	// criando um objeto pessoa
	einstein.calcula_idade(diaAtual, mesAtual, anoAtual);
	newton.calcula_idade(diaAtual, mesAtual, anoAtual);
	
	printf("resultado usando construct e com a função junto da struct privada. \n");
	//printf("einstein : %d\n", einstein.idade);
	//printf("newton : %d", newton.idade);
	printf("einstein: %d\n", einstein.getIdade());
	printf("newton: %d\n", newton.getIdade());

	// não sei para o que serve exatamente
	getchar();

	return 0;
}
