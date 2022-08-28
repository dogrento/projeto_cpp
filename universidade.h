//#ifndef _UNIVERSIDADE_CLASS_H
//#define _UNIVERSIDADE_CLASS_H
//#pragma once // faz a mesma coisa que os linhas comentadas acima 

class Universidade{

	// atributo da classe universidade
	private:
		char nome[30];
		char local[30];

	// metodos	
	public:
		//constructor
		Universidade(const char n[] = "");

		//destructor
		~Universidade();

		void setNome(const char n[]);
		void setLocal(const char nome_local[]);
		char* getNome();
		char* getLocal();

};

//#endif
