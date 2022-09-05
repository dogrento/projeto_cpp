#ifndef _DEPARTAMENTO_H_
#define _DEPARTAMENTO_H_

#include <stdio.h>
#include <cstring>

class Departamento{
	private:
		int id;
		char nome_departamento[100];

	public:
		Departamento();
		~Departamento();
		int getId();
		void setNome(const char dpto_nome[]);
		char* getNome();
};

#endif
