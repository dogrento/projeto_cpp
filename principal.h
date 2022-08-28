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

	public:
		//contructor
		Principal();
		void Exec();
			
};
