#ifndef _LISTADPTO_H_
#define _LISTADPTO_H_

#include <string.h>

#include "elementoDpto.h"
#include "departamento.h"

class ListaDptos
{ 
private:
	int countDpto;
	int numDpto;
	char nome[150];

	ElementoDpto *pElDepartamentoPrim;
    ElementoDpto *pElDepartamentoAtual;

public:

	ListaDptos(int nd = 1000, const char* n = "");
	~ListaDptos();
	void Set_nome (const char* n);
	void Inclua_dpto(Departamento* pd);
    void Listar_dptos();
    void Listar_dptos2();
};

#endif
