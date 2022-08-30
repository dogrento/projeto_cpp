#include <time.h>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include "principal.h"

//metodo construtor
//
Principal::Principal(){
	Douglas.Init(13,2,1993, "Douglas Oshiro");
	Einstein.Init(14,3,1879, "Albert Einstein");
	Newton.Init(4,1,1643, "Isaac Newton");

	UTFPR.setNome("UTFPR");
	UTFPR.setLocal("Curitiba, PR, BR");

	Princeton.setNome("Princeton");
	Princeton.setLocal("Nova Jersey, EUA");
	Cambridge.setNome("Cambridge");
	Cambridge.setLocal("Cambridge, Inglaterra");

	Douglas.setUnivFiliado(&UTFPR);
	Einstein.setUnivFiliado(&Princeton);
	Newton.setUnivFiliado(&Cambridge);

	//agregação dos Departamentos
	ModaUTFPR.setNome("Moda");
	TecnologiaUTFPR.setNome("Tecnologia da UTFPR");
	DAELN.setNome("Eletrônica");
	FisicaPrinceton.setNome("Fisica");
	MatematicaCambridge.setNome("Matemática");

	UTFPR.setDpto(&DAELN);
	UTFPR.setDpto(&ModaUTFPR);
	UTFPR.setDpto(&TecnologiaUTFPR);
	Princeton.setDpto(&FisicaPrinceton);
	Cambridge.setDpto(&MatematicaCambridge);

	Douglas.setDptoFiliado(&DAELN);
	Einstein.setDptoFiliado(&FisicaPrinceton);
	Newton.setDptoFiliado(&MatematicaCambridge);

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

	Douglas.getLocalTrabalho();
	Einstein.getLocalTrabalho();
	Newton.getLocalTrabalho();

	Douglas.getDepartamento();
	Einstein.getDepartamento();
	Newton.getDepartamento();
} 
