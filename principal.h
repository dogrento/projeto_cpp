#ifndef _PRINCIPAL_H_
#define _PRINCIPAL_H_

#include "pessoa.h"

class Principal{

	// criando atributos de classe do tipo pessoa
	private:

		Pessoa Douglas;
		Pessoa Einstein;
		Pessoa Newton;

		int diaAtual,
		    mesAtual,
		    anoAtual;

		Universidade UTFPR;
		Universidade Princeton;
		Universidade Cambridge;

		Departamento ModaUTFPR;
		Departamento TecnologiaUTFPR;
		Departamento DAELN;
		Departamento FisicaPrinceton;
		Departamento MatematicaCambridge;

	public:
		//contructor
		Principal();
		~Principal(){}
		void Exec();
			
};

#endif
