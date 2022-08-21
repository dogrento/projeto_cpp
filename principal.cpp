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

	cout << "Informe a data atual:" << endl;
	cin >> diaAtual >> mesAtual >> anoAtual;

	Exec();
}

//metodo Exec
void Principal::Exec(){
	Douglas.calcula_idade(21,8,2022);
	Newton.calcula_idade(21,8,2022);
	Einstein.calcula_idade(21,8,2022);
} 
