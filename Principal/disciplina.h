#ifndef _DISCIPLINA_H_
#define _DISCIPLINA_H_

#include "departamento.h"

class Universidade;
class Disciplina;


class Disciplina
{ 
private:
	int id;
	char nomeDisc[150];
	char areaConhecimento[150];
		
	// associa cada disciplina a um departamento;
	Departamento* dptoFiliado;
   
public:
	Disciplina(char* ac = "");
	~Disciplina();
		
	// ponteiros para a lista encadeada;
	Disciplina* next;
	
	void Set_id(int i);	
	int Get_id();
	void Set_disc(char* n);
	char* Get_disc();
	void Set_dpto(Departamento* pd);
	Departamento* Get_dpto();
};

#endif
