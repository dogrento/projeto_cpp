#ifndef _DEPARTAMENTO_H_
#define _DEPARTAMENTO_H_

class Universidade;
class Disciplina;
class ListaDisc;
class Departamento{
	private:
		int id;
		char nomeDpto[100];

		// associação para uma universidade
		Universidade* univFiliado;

		ListaDisc* objDisc;

	public:
		Departamento(int i);
		~Departamento();

		int Get_id();

		void Set_nome(const char dpto_nome[]);
		char* Get_nome();

		void Set_universidade(Universidade* univ);
		Universidade* Get_universidade();

		void Set_disciplina(Disciplina* disc);
		void Listar_disc();
		void Listar_disc2();
};

#endif
