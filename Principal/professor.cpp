#include <iostream>
using std::cout;
using std::endl;
#include "professor.h"
//#include "universidade.h"

// construct
Professor::Professor(int diaNasc, int mesNasc, int anoNasc, const char* nome):
	Pessoa(diaNasc, mesNasc, anoNasc, nome)
{
}

Professor::Professor():
Pessoa()
{
}

Professor::~Professor()
{
}

void Professor::Set_univFiliado(Universidade* pu){
	pUnivFiliado = pu;
}

void Professor::Set_dptoFiliado(Departamento* ponteiro_departamento){
	pDptoFiliado = ponteiro_departamento;
}

void Professor::Onde_trabalho(){
	cout << nome_pessoa << " trabalha para: " << pUnivFiliado->Get_nome() << endl;	
}

void Professor::QualDptoTrabalho(){
	cout << nome_pessoa << " trabalha para: " << pDptoFiliado->Get_nome() << endl;	
}
