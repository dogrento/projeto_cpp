#ifndef _PRINCIPAL_H_
#define _PRINCIPAL_H_

//#include "pessoa.h"
#include "professor.h"
#include "listaUniv.h"
#include "listaDpto.h"
#include "listaDisc.h"
#include "aluno.h"
class Principal
{
 private:

    // A T E N � � O !!!
    // A ORDEM DA DECLARA��O DOS OBJETOS/VARI�VEIS (AGREGADOS) NUMA CLASSE AFETA 
    // A ORDEM DA CHAMADA(OU DA EXECU��O) DE SEUS CONTRUTORES A PARTIR DO CONSTRUTOR
    // DESTA CLASSE AGREGADORA. NESTE CASO, A CLASSE QUE OS AGREGA � A PRINCIPAL!

    // Contadores para identificadores;
	int cont_idDisc;
	int cont_idDepart;
	int cont_idAluno;

    // Universidades
    Universidade UTFPR;
    Universidade Princeton;
    Universidade Cambridge;

    // Departamentos
    Departamento EletronicaUTFPR;
    Departamento MatematicaUTFPR;
    Departamento FisicaUTFPR;

    Departamento MatematicaPrinceton;
    Departamento FisicaPrinceton;

    Departamento MatematicaCambridge;
    Departamento FisicaCambridge;

    // Professores
    Professor	Simao;
    Professor	Einstein;
    Professor	Newton;

    // Disciplinas
    Disciplina	Computacao1_2006;
    Disciplina	Introd_Alg_2007;
    Disciplina	Computacao2_2007;
    Disciplina	Metodos2_2007;    
	
	// Alunos
    Aluno		AAA;
    Aluno		BBB;
    Aluno		CCC;
    Aluno		DDD;
    Aluno		EEE;

    int			diaAtual;
    int			mesAtual;
    int			anoAtual;

    ListaUnivs	LUniversidades;
	ListaDptos	LDepartamentos;
	ListaDisc	LDisciplinas;
	ListaAlunos			LAlunos;

  public:

    Principal ( );

    // Inicializa��es...
    void Init();
    void Init_univ();
    void Init_dpto();
    void Init_professor();
    void Init_aluno();
    void Init_disc();

    void Exec();
    
    void Calcula_idadeProfessor();
    void Get_univProfessor();
    void Get_dptoProfessor();
	void Listar_discDpto ( );
	void Listar_alunosDisc();

	void Cadastrar_disc();
	void Cadastrar_dpto();
	void Cadastrar_univ();
	void Cadastrar_aluno();

	void GravarTudo();
	void GravarUniversidades();
	void GravarDepartamentos();
	void GravarDisciplinas();
	void GravarAlunos();
	void GravarProfessores();

	void RecuperarTudo();
	void RecuperarUniversidades();
	void RecuperarDepartamentos();
	void RecuperarDisciplinas();
	void RecuperarAlunos();
	void RecuperarProfessores();

	void MenuCad();
	void MenuExe();
	void MenuGravar();
	void MenuRecuperar();
	void Menu();

};

#endif



// class Principal{

// 	// criando atributos de classe do tipo pessoa
// 	private:

// 		int diaAtual,
// 		    mesAtual,
// 		    anoAtual;

// 		Universidade UTFPR;
// 		Universidade Princeton;
// 		Universidade Cambridge;

// 		Departamento ModaUTFPR;
// 		Departamento TecnologiaUTFPR;
// 		Departamento DAELN;
// 		Departamento FisicaPrinceton;
// 		Departamento MatematicaCambridge;

// 		Professor Douglas;
// 		Professor Einstein;
// 		Professor Newton;

// 	public:
// 		//contructor
// 		Principal();
// 		~Principal(){}
// 		void Exec();
			
// };

// #endif
