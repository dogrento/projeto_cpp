#include <iostream>
using std::cout;
using std::endl;
#include "professor.h"
#include "universidade.h"

// construct
Professor::Professor(int diaNasc, int mesNasc, int anoNasc, const char* nome):
	Pessoa(diaNasc, mesNasc, anoNasc, nome)
{
	pUnivFiliado = NULL;
	pDptoFiliado = NULL;
}

Professor::Professor():
	Pessoa()
{
	pUnivFiliado = NULL;
	pDptoFiliado = NULL;
}

Professor::~Professor()
{
	pUnivFiliado = NULL;
	pDptoFiliado = NULL;
}

void Professor::setUnivFiliado(Universidade* pu){
	pUnivFiliado = pu;
}

void Professor::setDptoFiliado(Departamento* ponteiro_departamento){
	pDptoFiliado = ponteiro_departamento;
}

// char* Professor::getLocalTrabalho(Universidade* ponteiro_universidade){
	// cot << ponteiro_universidade->getLocal() << 
// }

// void Professor::setDpto(Departamento* dpto){
	// pDptoFiliado = dpto;
// }

void Professor::getLocalTrabalho(){
	cout << pUnivFiliado->getNome() << "trabalha para: " << pUnivFiliado->getNome() << endl;	
}

void getDpto(){
	cout << 
}
