#include <iostream>
using std::cout;
using std::endl;
#include "professor.h"
//#include "universidade.h"

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

void Professor::Set_univFiliado(Universidade* pu){
	pUnivFiliado = pu;
}

void Professor::Set_dptoFiliado(Departamento* ponteiro_departamento){
	pDptoFiliado = ponteiro_departamento;
}

void Professor::Print_univ(){
	cout << nome_pessoa << " trabalha para: " << pUnivFiliado->getNome() << endl;	
}

void Professor::Print_dpto(){
	cout << nome_pessoa << " trabalha para: " << pDptoFiliado->getNome() << endl;	
}
