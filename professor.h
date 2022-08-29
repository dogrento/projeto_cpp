#ifndef _PROFESSOR_H_
#define _PROFESSOR_H_

#include <stdio.h>

#include "pessoa.h"
//#include "universidade.h"
//#include "departamento.h"

class Professor :public Pessoa{
	private:
		Universidade* pUnivFiliado;
		//Departamento* pDepartamentoFiliado;

	public:
		Professor(int diaNasc, int mesNasc, int anoNasc, const char* nome=""); 		
		Professor();
		~Professor();

		void setUnivFiliado(Universidade* pu);
		//void setDepartamento(Departamento* dpto);
		void getLocalTrabalho(Universidade* pu);
		//void getDepartamento();
};

#endif
