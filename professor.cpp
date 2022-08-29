#include <iostream>
using std::cout;
using std::endl;
#include "professor.h"

// construct
Professor::Professor(int diaNasc, int mesNasc, int anoNasc, const char* nome):
	Pessoa(diaNasc, mesNasc, anoNasc, nome)
{
	pUnivFiliado = NULL;
	//pDepartamentoFiliado = NULL;
}

Professor::Professor():
	Pessoa()
{
	pUnivFiliado = NULL;
	//pDepartamentoFiliado = NULL;
}

Professor::~Professor()
{
	pUnivFiliado = NULL;
	//pDepartamentoFiliado = NULL;
}

void Professor::setUnivFiliado(Universidade* pu){
	pUnivFiliado = pu;
}

//void Professor::setDepartamento(Departamento* dpto){
//	pDepartamentoFiliado = dpto;
//}

void Professor::getLocalTrabalho(Universidade* pu){
	cout << nome_pessoa << "trabalha para: " << pUnivFiliado->getNome() << endl;	
}
