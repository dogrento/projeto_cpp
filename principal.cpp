#include <time.h>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include "principal_class.h"

//metodo construtor
//
Principal::Principal(){
	Douglas.Init(13,2,1993, "Douglas Oshiro");
	Einstein.Init(14,3,1879, "Albert Einstein");
	Newton.Init(4,1,1643, "Isaac Newton");

	UTFPR.setNome("UTFPR");

	Douglas.setUnivFiliado(&UTFPR);

	// ponteiro do tipo struct tm, que contem data e hora
	struct tm* local;
	time_t segundos;
	time(&segundos);
	local = localtime(&segundos);

	//retorna o dia
	diaAtual = local -> tm_mday;
	//retorna o mes
	mesAtual = local -> tm_mon+1;

	//retorna o ano
	// é necessário add 1900, pois o sistema retorna a partir desse ano
	// ao inves de 2022, retorna 122
	anoAtual = local -> tm_year + 1900;

	Exec();
}

//metodo Exec
void Principal::Exec(){
	Douglas.calcula_idade(diaAtual, mesAtual, anoAtual);
	Newton.calcula_idade(diaAtual, mesAtual, anoAtual);
	Einstein.calcula_idade(diaAtual, mesAtual, anoAtual);

	Douglas.OndeTrabalho();
} 
