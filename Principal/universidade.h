#ifndef _UNIVERSIDADE_H_
#define _UNIVERSIDADE_H_

#include "listaDpto.h"

class Universidade{

	// atributo da classe universidade
	private:
		char nome_universidade[130];
		ListaDptos objLDptos;

	// metodos	
	public:
		//constructor
		Universidade();

		//destructor
		~Universidade();

		void Set_nome(const char n[]);
		char* Get_nome();

		void Incluir_dpto(Departamento* dpto_pessoa);
		void Listar_dpto();
		void Listar_dpto2();
};

#endif
