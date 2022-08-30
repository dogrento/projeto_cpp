//#ifndef _UNIVERSIDADE_CLASS_H
//#define _UNIVERSIDADE_CLASS_H
//#pragma once // faz a mesma coisa que os linhas comentadas acima 
#include "departamento.h"
#include <vector>
using namespace std;

class Universidade{

	// atributo da classe universidade
	private:
		char nome_universidade[30];
		char local_universidade[30];
		//objeto do tipo Departamento
		//Departamento* dpto_list[50];
		vector<Departamento*> lista_departamento;

	// metodos	
	public:
		//constructor
		Universidade();

		//destructor
		~Universidade();

		void setNome(const char n[]);
		void setLocal(const char nome_local[]);
		char* getNome();
		char* getLocal();
		void setDpto(Departamento* dpto_pessoa);
		void print_dpto();

};

//#endif
