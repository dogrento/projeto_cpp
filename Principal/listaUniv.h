#ifndef _LISTAUNIV_H_
#define _LISTAUNIV_H_

#include "elementoUniv.h"
#include "universidade.h"

class ListaUnivs
{ 
private:
	int  countUniv;
	int  numUniv;
	char nome[150];

	ElementoUniv *pElUniversidadePrim;
    ElementoUniv *pElUniversidadeAtual;
public:

	ListaUnivs(int nu = 1000, char* n = "");
	~ListaUnivs();
	
	void Incluir_univ(Universidade* pu);
    void Listar_univ();
    void Listar_univ2();

	Universidade* Localizar(char* n);
};

#endif
