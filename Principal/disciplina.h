#ifndef _DISCIPLINA_H_
#define _DISCIPLINA_H_

#include "departamento.h"
#include "listaAlunos.h"
class Disciplina
{ 
private:
	int id;
	char nomeDisc[150];
	char areaConhecimento[150];
		
	// associa cada disciplina a um departamento;
	Departamento* dptoFiliado;
	ListaAlunos objListAlunos;
   
public:
	Disciplina(int i, int na = 45, char* ac= "");
	~Disciplina();
	
	void Set_id(int i);	
	int Get_id();

	void Set_disc(char* n);
	char* Get_disc();

	void Set_dpto(Departamento* dpto);
	Departamento* Get_dpto();

	void Inclua_aluno(Aluno* aluno);
	void Listar_alunos();
	void Listar_alunos2();
};

#endif
