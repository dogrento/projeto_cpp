#include "pessoa_class.h"

class Principal{

	// criando atributos de classe do tipo pessoa
	private:
		Pessoa Douglas;
		Pessoa Einstein;
		Pessoa Newton;

		int diaAtual,
		    mesAtual,
		    anoAtual;

	public:
		//contructor
		Principal();
		void Exec();
			
};
