#include "listaAlunos.h"

ListaAlunos::ListaAlunos(int na, char* n){
    numAlunos = na;
    countAlunos = 0;

    elAlunoAtual = NULL;
    elAlunoPrim = NULL;

    strcpy(nome, n);
}

ListaAlunos::~ListaAlunos(){
    Limpa_lista();
}

void ListaAlunos::Limpa_lista(){
    Elemento<Aluno>* pAux1 = elAlunoPrim;
    Elemento<Aluno>* pAux2 = pAux1;

    while ((pAux1 != NULL))
    {
        pAux2 = pAux1->Get_next();
        delete(pAux1);
        pAux1 = pAux2;
    }

    elAlunoPrim = NULL;
    elAlunoAtual = NULL;
}

void ListaAlunos::Inclua_aluno(Aluno* aluno){
    // criando ponteiro para lista de alunos
    // e criando um obj com seu endereço em aux
    Elemento<Aluno>* pAux = new Elemento<Aluno>();

    pAux->Set_nome(aluno->Get_nome());

    // recebendo copia do obj
    pAux->Set_info(aluno);

 if (
		  ( ( countAlunos < numAlunos ) && ( pAux != NULL) ) ||
	  	  ( ( -1 == numAlunos)			&& ( pAux != NULL) )
	   )
    {   
       if ( elAlunoPrim == NULL )
       {
          elAlunoPrim   = pAux;
          elAlunoAtual  = pAux;
       }
       else
       {
          elAlunoAtual->Set_next(pAux);
          pAux->Set_prev(elAlunoAtual);
          elAlunoAtual = pAux;
       }
       countAlunos++;
    }
    else
    {
       //printf ("Aluno n�o inclu�do. Turma j� lotada em %i alunos \n", numero_alunos );
	   cout << "Aluno não incluído. Turma já lotada em " << numAlunos << " alunos." << endl;
    }
}

void ListaAlunos::Listar_alunos()
{
    Elemento<Aluno>* pAux;
    pAux = elAlunoPrim;

    while (pAux != NULL)
    {
         //printf(" Aluno %s matriculado na Disciplina %s. \n", aux->Get_nome(), nome);
		 cout << " Aluno " << pAux->Get_nome() << " matriculado na Disciplina " << nome << "." << endl;
         pAux = pAux->Get_next();
    }
}

void ListaAlunos::Listar_alunos2()
{
    Elemento<Aluno>* pAux;
    pAux = elAlunoAtual;

    while (pAux != NULL)
    {
       //printf(" Aluno %s matriculado na Disciplina %s \n", aux->Get_nome(), nome);
	   cout << " Aluno " << pAux->Get_nome() << " matriculado na Disciplina " << nome << "." << endl;
       pAux = pAux->Get_prev();
    }
}


void ListaAlunos::Grave_alunos()
{
	ofstream GravacaoAlunos ("alunos.dat", ios::out);

	if (!GravacaoAlunos)
	{
		cerr << "Arquivo n�o pode ser aberto" << endl;
		fflush(stdin);
		getchar();
	}

    Elemento<Aluno>* pauxElAluno;
	pauxElAluno = elAlunoPrim;

    while (pauxElAluno != NULL)
    {
		 Aluno* pauxAluno;
         
		 pauxAluno = pauxElAluno->Get_info();

		 GravacaoAlunos << pauxAluno->Get_id() << ' ' 
						<< pauxAluno->Get_ra() << ' ' 
						<< pauxAluno->Get_nome() 
						<< endl;
         pauxElAluno = pauxElAluno->Get_next();
    } 

	GravacaoAlunos.close();
}

void ListaAlunos::Recuperar_alunos()
{
	ifstream RecuperacaoAlunos ("alunos.dat", ios::in);

	if (!RecuperacaoAlunos)
	{
		cerr << "Arquivo n�o pode ser aberto" << endl;
		fflush(stdin);
		getchar();
	}

	Limpa_lista();

	while (!RecuperacaoAlunos.eof())
    {
		Aluno* pauxAluno;
         
		pauxAluno = new Aluno(-1);

		int				id;
	   	int				RA;
        char			nome[150] ;

		RecuperacaoAlunos	>> id >> RA >> nome;

		if (0 != strcmp(nome, ""))
		{
			pauxAluno->Set_id(id);
			pauxAluno->Set_ra(RA);
			pauxAluno->Set_nome(nome);
		
			Inclua_aluno(pauxAluno);  
		}
    } 

	RecuperacaoAlunos.close();
}