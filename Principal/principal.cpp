#include <time.h>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include "principal.h"

// A T E N � � O
// A ordem de chamada dos construtores dos objetos (agredados) nesta classe
// � definida pela sua ordem de declara��o na classe Principal e N�O (estra-
// nhamente) pela sua ordem de chamada aqui (a partir do construtor da Principal).

Principal::Principal ( ):
// "geradores" de identifica��o
cont_idAluno		(0),
cont_idDisc			(0),
cont_idDepart		(0),
// Contrutores dos objetos da Classe Disciplina
Computacao1_2006	(cont_idDisc++),
Introd_Alg_2007		(cont_idDisc++),
Computacao2_2007	(cont_idDisc++),
Metodos2_2007		(cont_idDisc++),
// Contrutores dos objetos da Classe Aluno
AAA					(cont_idAluno++),
BBB					(cont_idAluno++),
CCC					(cont_idAluno++),
DDD					(cont_idAluno++),
EEE					(cont_idAluno++),
//Contrutores dos Objetos da Classe Departamento
EletronicaUTFPR		(cont_idDepart++),	
MatematicaUTFPR		(cont_idDepart++),
FisicaUTFPR			(cont_idDepart++),
MatematicaPrinceton	(cont_idDepart++),
FisicaPrinceton		(cont_idDepart++),
MatematicaCambridge	(cont_idDepart++),
FisicaCambridge		(cont_idDepart++)
{   
 	// ponteiro do tipo struct tm, que contem data e hora
	struct tm* local;
	time_t segundos;
	time(&segundos);
	local = localtime(&segundos);

	//retorna o dia
	diaAtual = local -> tm_mday;
	//retorna o mes
	mesAtual = local -> tm_mon+1;

	//retorna o ano
	// é necessário add 1900, pois o sistema retorna a partir desse ano
	// ao inves de 2022, retorna 122
	anoAtual = local -> tm_year + 1900;
    Init ( ); 
	Exec ( ); 
}

void Principal::Init ( )
{   
	Init_aluno ( );
    Init_univ ( );
    Init_dpto ( );
    Init_professor ( );
    Init_disc ( );
}

void Principal::Init_aluno()
{ 
	AAA.Set_nome	("AAA");
	LAlunos.Inclua_aluno(&AAA);

	BBB.Set_nome	("BBB");
	LAlunos.Inclua_aluno(&BBB);

	CCC.Set_nome	("CCC");
	LAlunos.Inclua_aluno(&CCC);

	DDD.Set_nome	("DDD");
	LAlunos.Inclua_aluno(&DDD);

	EEE.Set_nome	("EEE");
	LAlunos.Inclua_aluno(&EEE);
}

void Principal::Init_univ ( )
{  
    // Init_professor do(s) nome(s) da(s) universidade(s)
    UTFPR.Set_nome( "UTFPR");
	LUniversidades.Incluir_univ( &UTFPR );

    Princeton.Set_nome ( "Princeton" );
	LUniversidades.Incluir_univ( &Princeton );

    Cambridge.Set_nome ( "Cambridge" );
	LUniversidades.Incluir_univ( &Cambridge );
}

void Principal::Init_dpto ( )
{ 
    // Registro do(s) nome(s) do(s) departamento(s)
    EletronicaUTFPR.Set_nome		( "Eletronica UTFPR" );
	MatematicaUTFPR.Set_nome		( "Matematica UTFPR" );
    FisicaUTFPR.Set_nome			( "Fisica UTFPR" );
    MatematicaPrinceton.Set_nome ( "Matematica Princeton" );
    FisicaPrinceton.Set_nome		( "Fisica Pirnceton" );
    MatematicaCambridge.Set_nome ( "Matematica Cambridge" );
    FisicaCambridge.Set_nome		( "Fisica Cambridge" );   

	LDepartamentos.Inclua_dpto(&EletronicaUTFPR);
	LDepartamentos.Inclua_dpto(&MatematicaUTFPR);
	LDepartamentos.Inclua_dpto(&FisicaUTFPR);
	LDepartamentos.Inclua_dpto(&MatematicaPrinceton);
	LDepartamentos.Inclua_dpto(&FisicaPrinceton);
	LDepartamentos.Inclua_dpto(&MatematicaCambridge);
	LDepartamentos.Inclua_dpto(&FisicaCambridge);
     
    // "Agrega��o" do(s) Departamento(s) a(s) Universidade(s).
    UTFPR.Incluir_dpto		( &EletronicaUTFPR );
    UTFPR.Incluir_dpto		( &MatematicaUTFPR );
    UTFPR.Incluir_dpto		( &FisicaUTFPR );

    Princeton.Incluir_dpto	( &MatematicaPrinceton );
    Princeton.Incluir_dpto	( &FisicaPrinceton );
    Cambridge.Incluir_dpto	( &MatematicaCambridge );
    Cambridge.Incluir_dpto	( &FisicaCambridge );
}

void Principal::Init_professor ( )
{   

    // Inicializa��o do(s) ojeto(s) da classe Professor
    Simao.Init	( 3, 10, 1976, "Jean Sim�o" );
    Einstein.Init ( 14, 3, 1879, "Albert Einstein" );
    Newton.Init	( 4, 1, 1643, "Isaac Newton" );

    // "Filia��o" a universidade.
    Simao.Set_univFiliado	( &UTFPR );
    Einstein.Set_univFiliado ( &Princeton );
    Newton.Set_univFiliado	( &Cambridge );

    // Area de Conhecimento.
    // Simao.setDominio		( "Computa��o� );
    // Einstein.setDominio	( "F�sica" );
    // Newton.setDominio	( "Matem�tica-F�sica" );

    // "Filia��o" ao departamento.
    Simao.Set_dptoFiliado	( &EletronicaUTFPR );
    Einstein.Set_dptoFiliado( &FisicaPrinceton );
    Newton.Set_dptoFiliado	( &MatematicaCambridge );
 }

void Principal::Init_disc ( )
{
    Computacao1_2006.Set_disc	( "Computacao I 2006" );
    Introd_Alg_2007.Set_disc		( "Introducao de Algoritmos de Programacao 2007" );
	Computacao2_2007.Set_disc	( "Computao II" );
	Metodos2_2007.Set_disc		( "M�todos II" );

	LDisciplinas.Incluir_disc(&Computacao1_2006);
	LDisciplinas.Incluir_disc(&Introd_Alg_2007);
	LDisciplinas.Incluir_disc(&Computacao2_2007);
	LDisciplinas.Incluir_disc(&Metodos2_2007);

    Computacao1_2006.Set_dpto  ( &EletronicaUTFPR );
    Introd_Alg_2007.Set_dpto	  ( &EletronicaUTFPR );
    Computacao2_2007.Set_dpto  ( &EletronicaUTFPR );
    Metodos2_2007.Set_dpto     ( &EletronicaUTFPR );

    Metodos2_2007.Inclua_aluno ( &AAA );
    Metodos2_2007.Inclua_aluno ( &BBB );
    Metodos2_2007.Inclua_aluno ( &CCC );
    Metodos2_2007.Inclua_aluno ( &DDD );
    Metodos2_2007.Inclua_aluno ( &EEE );

	Computacao2_2007.Inclua_aluno ( &AAA );
    Computacao2_2007.Inclua_aluno ( &EEE );
    Computacao2_2007.Inclua_aluno ( &DDD );
}

void Principal::Calcula_idadeProfessor ( )
{
    // C�lculo da idade.
    Simao.calcula_idade    ( diaAtual, mesAtual, anoAtual );
    Einstein.calcula_idade ( diaAtual, mesAtual, anoAtual );
    Newton.calcula_idade	( diaAtual, mesAtual, anoAtual );
    printf ("\n");
}

void Principal::Get_univProfessor ( )
{
    // Universidade que a Pessoa trabalha.
    Simao.Onde_trabalho ( );
    Einstein.Onde_trabalho ( );
    Newton.Onde_trabalho ( );
    
	cout << endl;
}

void Principal::Get_dptoProfessor ( )
{
    // Departamento que a Pessoa trabalha.
    Simao.QualDptoTrabalho ( );
    Einstein.QualDptoTrabalho ( );
    Newton.QualDptoTrabalho ( );
    //printf ( "\n" );
	cout << endl;
}

void Principal::Listar_discDpto()
{
    EletronicaUTFPR.Listar_disc();
 	cout << endl;
}

void Principal::Listar_alunosDisc()
{
    Metodos2_2007.Listar_alunos();
    cout << endl;

    Computacao2_2007.Listar_alunos();  
    cout << endl;

	//Metodos2_2007.listeAlunos2();
    //cout << endl;
}

void Principal::Exec()
{
    //Calcula_idadeProfessor();
    //Get_univProfessor();
    //Get_dptoProfessor();
	//Listar_discDpto();
    //Listar_alunosDisc();
	Menu();
}

void Principal::Cadastrar_disc()
{

}

void Principal::Cadastrar_dpto()
{
    char nomeUniversidade[150];
	char nomeDepartamento[150];
	Universidade* univ;
	Departamento* depart;

	cout << "Qual o nome da universidade do departamento" << endl;
	cin  >> nomeUniversidade;

	univ = LUniversidades.Localizar(nomeUniversidade);
	
	if ( univ != NULL )
	{
		cout << "Qual o nome do departamento" << endl;
		cin >> nomeDepartamento;
	    depart = new Departamento(cont_idDepart);
		cont_idDepart++;
		depart->Set_nome(nomeDepartamento);
		LDepartamentos.Inclua_dpto(depart);
		LUniversidades.Incluir_univ(univ);
	}
	else
	{
		cout << "Universidade inexistente." << endl;
	}
}

void Principal::Cadastrar_univ()
{
    char nomeUniversidade[150];
	Universidade* univ;

	cout << "Qual o nome da universidade" << endl;
	cin  >> nomeUniversidade;

    univ = new Universidade();
	univ->Set_nome(nomeUniversidade);

	LUniversidades.Incluir_univ(univ);
}

void Principal::Cadastrar_aluno()
{
    char	nomeAluno[150];
	int		ra;
	Aluno*	al;

	cout << "Qual o nome do aluno. " << endl;
	cin  >> nomeAluno;

	cout << "Qual o RA do aluno."	<< endl;
	cin  >> ra;

    al = new Aluno(cont_idAluno++);
	al->Set_nome(nomeAluno);
	al->Set_ra(ra);

	LAlunos.Inclua_aluno(al);
}

void Principal::GravarTudo()
{
}

void Principal::GravarUniversidades()
{
}

void Principal::GravarDepartamentos()
{
}

void Principal::GravarDisciplinas()
{
}

void Principal::GravarAlunos()
{
	LAlunos.Grave_alunos();
}

void Principal::GravarProfessores()
{
}

void Principal::RecuperarTudo()
{
}

void Principal::RecuperarUniversidades()
{
}

void Principal::RecuperarDepartamentos()
{
}

void Principal::RecuperarDisciplinas()
{
}

void Principal::RecuperarAlunos()
{
	LAlunos.Recuperar_alunos();
}

void Principal::RecuperarProfessores()
{
}

void Principal::MenuCad()
{
    int op = -1;

    while (op != 5)
    {
		system("cls");
        cout << "  Informe sua op��o:			"	<< endl;
        cout << "  1 - Cadastrar Disciplina.	"	<< endl;
        cout << "  2 - Cadastrar Departamentos. "	<< endl;
        cout << "  3 - Cadastrar Universidade.	"	<< endl;
		cout << "  4 - Cadastrar Aluno.			"	<< endl;
        cout << "  5 � Sair. "						<< endl;
        cin >> op;

        switch (op)
        {
            case 1 :{ Cadastrar_disc ();	 }
                break;

            case 2: { Cadastrar_dpto(); }
				break;

			case 3:	{ Cadastrar_univ(); }
				break;

			case 4:	{ Cadastrar_aluno(); }
				break;

            case 5:	{ cout << " FIM " << endl; }
                break;

            default:{                      
					  cout << "Op��o Inv�lida - Pressione uma tecla." << endl;
					  getchar();
				    }
        }
    }
}

void Principal::MenuExe()
{
    int op = -1;
    while ( op != 6 )
    {
		system("cls");
        cout << "  Informe sua op��o:		"	<< endl;
        cout << "  1 - Listar Disciplinas.  "	<< endl;
        cout << "  2 - Listar Departamentos."	<< endl;
        cout << "  3 - Listar Universidade. "	<< endl;
		cout << "  4 - Listar Alunos. "			<< endl;
		cout << "  5 - Listar Professores."		<< endl;
        cout << "  6 � Sair. "					<< endl;
        cin  >> op;

        switch ( op )
        {
			case 1:  { 
					   LDisciplinas.Listar_disc();
					   fflush(stdin);
					   getchar(); 	
					 }
                break;
			case 2:  { 
				       LDepartamentos.Listar_dptos();
					   fflush(stdin);
					   getchar(); 
					 }
				break;
			case 3:  { 
				       LUniversidades.Listar_univ(); 
				       fflush(stdin);
					   getchar();
					 }
				break;
			case 4:  { 
					   LAlunos.Listar_alunos(); 
				       fflush(stdin);
					   getchar(); 
					 }
                break;
	        case 5:  { 
						Get_dptoProfessor(); 
						fflush(stdin);
						getchar();
					 }
                break; 
            case 6:  { 
						cout << " FIM " << endl; 
					 }
                break;
            default: { 
					   cout << "Op��o Inv�lida - Pressione uma tecla." << endl;
					   getchar(); 
					 }
        }
    }
}

void Principal::MenuGravar()
{
	int op = -1; 
    while (op != 6)
    {
		system("cls");
        cout << "  Informe sua op��o:			"	<< endl;
		cout << "  0 - Gravar Tudo.				"	<< endl;
        cout << "  1 - Gravar Universidades.	"	<< endl;
        cout << "  2 - Gravar Departamentos.	"	<< endl;
		cout << "  3 - Gravar Disciplinas.		"	<< endl;
		cout << "  4 - Gravar Alunos.			"	<< endl;
		cout << "  5 - Gravar Professores.		"	<< endl;
        cout << "  6 � Sair.					"	<< endl;
        cin >> op;

        switch (op)
        {
			case 0: {	GravarTudo();			 }
                break;
            case 1: {	GravarUniversidades();	 }
                break;
            case 2: {	GravarDepartamentos();	 }
				break;
			case 3: {	GravarDisciplinas();	 }
				break;
			case 4: {	GravarAlunos();			 }
				break;
			case 5: {	GravarProfessores();	 }
				break;
			case 6: {	cout << " FIM " << endl; }
                break;
            default: { cout << "Op��o Inv�lida - Pressione uma tecla." << endl;
					   getchar(); }
        }
    }	
}

void Principal::MenuRecuperar()
{
	int op = -1;
    
    while (op != 6)
    {
		system("cls");

        cout << "  Informe sua op��o:			"	<< endl;
		cout << "  0 - Recuperar Tudo.			"	<< endl;
        cout << "  1 - Recuperar Universidades.	"	<< endl;
        cout << "  2 - Recuperar Departamentos.	"	<< endl;
		cout << "  3 - Recuperar Disciplinas.	"	<< endl;
		cout << "  4 - Recuperar Alunos.		"	<< endl;
		cout << "  5 - Recuperar Professores.	"	<< endl;
        cout << "  6 � Sair.					"	<< endl;
        cin >> op;

        switch (op)
        {
			case 0: {	RecuperarTudo();			 }
                break;
            case 1: {	RecuperarUniversidades();	 }
                break;
            case 2: {	RecuperarDepartamentos();	 }
				break;
			case 3: {	RecuperarDisciplinas();	 }
				break;
			case 4: {	RecuperarAlunos();			 }
				break;
			case 5: {	RecuperarProfessores();	 }
				break;
			case 6: {	cout << " FIM " << endl; }
                break;
            default: { cout << "Op��o Inv�lida - Pressione uma tecla." << endl;
					   getchar(); }
        }
    }	
}

void Principal::Menu()
{
	int op = -1;
    while (op != 5)
    {
		system("cls");
        cout << "  Informe sua op��o:"	<< endl;
        cout << "  1 - Cadastrar.	 "	<< endl;
        cout << "  2 - Exec.	 "	<< endl;
		cout << "  3 - Gravar.		 "  << endl;
		cout << "  4 - Recuperar.	 "  << endl;
        cout << "  5 � Sair.		 "	<< endl;
        cin >> op;

        switch (op)
        {
            case 1: {	MenuCad();			}
                break;
            case 2: {	MenuExe();			}
				break;
			case 3: {	MenuGravar();		}
				break;
			case 4: {	MenuRecuperar();	}
				break;
			case 5: {	cout << " FIM " << endl; }
                break;
            default: { cout << "Op��o Inv�lida - Pressione uma tecla." << endl;
					   getchar(); }
        }
    }	
}


// #include <time.h>
// #include <iostream>
// using std::cout;
// using std::cin;
// using std::endl;
// #include "principal.h"

// //metodo construtor
// //
// Principal::Principal(){
// 	Douglas.Init(13,2,1993, "Douglas Oshiro");
// 	Einstein.Init(14,3,1879, "Albert Einstein");
// 	Newton.Init(4,1,1643, "Isaac Newton");

// 	UTFPR.Set_nome("UTFPR");
// 	UTFPR.setLocal("Curitiba, PR, BR");

// 	Princeton.Set_nome("Princeton");
// 	Princeton.setLocal("Nova Jersey, EUA");
// 	Cambridge.Set_nome("Cambridge");
// 	Cambridge.setLocal("Cambridge, Inglaterra");

// 	Douglas.Set_univFiliado(&UTFPR);
// 	Einstein.Set_univFiliado(&Princeton);
// 	Newton.Set_univFiliado(&Cambridge);

// 	//agregação dos Departamentos
// 	ModaUTFPR.Set_nome("Moda");
// 	TecnologiaUTFPR.Set_nome("Tecnologia da UTFPR");
// 	DAELN.Set_nome("Eletrônica");
// 	FisicaPrinceton.Set_nome("Fisica");
// 	MatematicaCambridge.Set_nome("Matemática");

// 	UTFPR.setDpto(&DAELN);
// 	UTFPR.setDpto(&ModaUTFPR);
// 	UTFPR.setDpto(&TecnologiaUTFPR);
// 	Princeton.setDpto(&FisicaPrinceton);
// 	Cambridge.setDpto(&MatematicaCambridge);

// 	Douglas.setDptoFiliado(&DAELN);
// 	Einstein.setDptoFiliado(&FisicaPrinceton);
// 	Newton.setDptoFiliado(&MatematicaCambridge);

// 	// ponteiro do tipo struct tm, que contem data e hora
// 	struct tm* local;
// 	time_t segundos;
// 	time(&segundos);
// 	local = localtime(&segundos);

// 	//retorna o dia
// 	diaAtual = local -> tm_mday;
// 	//retorna o mes
// 	mesAtual = local -> tm_mon+1;

// 	//retorna o ano
// 	// é necessário add 1900, pois o sistema retorna a partir desse ano
// 	// ao inves de 2022, retorna 122
// 	anoAtual = local -> tm_year + 1900;

// 	Exec();
// }

// //metodo Exec
// void Principal::Exec(){
// 	Douglas.calcula_idade(diaAtual, mesAtual, anoAtual);
// 	Newton.calcula_idade(diaAtual, mesAtual, anoAtual);
// 	Einstein.calcula_idade(diaAtual, mesAtual, anoAtual);

// 	Douglas.getLocalTrabalho();
// 	Einstein.getLocalTrabalho();
// 	Newton.getLocalTrabalho();

// 	Douglas.getDpto();
// 	Einstein.getDpto();
// 	Newton.getDpto();
// } 
