#ifndef _PROFESSOR_H_
#define _PROFESSOR_H_


#include "pessoa.h"
#include "universidade.h"

class Professor :public Pessoa{
	private:
		Universidade* pUnivFiliado;
		Departamento* pDptoFiliado;

	public:
		Professor(int diaNasc, int mesNasc, int anoNasc, const char* nome=""); 		
		Professor();
		~Professor();

		void Set_univFiliado(Universidade* pu);
		void Set_dptoFiliado(Departamento* ponteiro_departamento);
		void Onde_trabalho();
		void QualDptoTrabalho();
};

#endif
