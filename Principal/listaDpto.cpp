#include <iostream>
using std::cout;
using std::endl;

#include "listaDpto.h"

ListaDptos::ListaDptos(int nd,const char* n)
{
	numDpto			= nd;
	countDpto			= 0;           

	pElDepartamentoPrim  = NULL;
	pElDepartamentoAtual = NULL;

	strcpy (nome, n ); 
}

ListaDptos::~ListaDptos()
{
   ElementoDpto *paux1, *paux2;
   
   paux1 = pElDepartamentoPrim;
   paux2 = paux1;

   while (paux1 != NULL)
   {
	     paux2 = paux1->pNext;
	     delete (paux1);
         paux1 = paux2;		 
   }

   pElDepartamentoPrim  = NULL;
   pElDepartamentoAtual = NULL;
}

void ListaDptos::Set_nome (const char* n)
{
	strcpy(nome, n);
}

void ListaDptos::Inclua_dpto ( Departamento* pd )
{
    // Aqui � criado um ponteiro para LAluno
    ElementoDpto* paux;
    // Aqui � criado um objeto LAluno, sendo seu endere�o armazenado em aux
    paux = new ElementoDpto ( );

    // Aqui recebe uma c�pia do objeto interm.
    paux->Set_dpto ( pd );

    paux->pNext = NULL;
    paux->pPrev = NULL;

    if ( 
		 ( ( countDpto < numDpto ) && ( pd != NULL) ) ||
		 ( ( numDpto == -1 )		 && ( pd != NULL) ) 
	   )
    {
    
      if ( pElDepartamentoPrim == NULL )
      {
         pElDepartamentoPrim   = paux;
         pElDepartamentoAtual  = paux;
      }
      else
      {
         pElDepartamentoAtual->pNext = paux;
         paux->pPrev            = pElDepartamentoAtual;
         pElDepartamentoAtual    = paux;
      }
      countDpto++;

    }
    else
    {
       //printf ("Aluno n�o inclu�do. Turma j� lotada em %i alunos \n", numero_alunos );
	   cout << "Departamento n�o inclu�do. Quantia de deps j� lotada em " << numDpto << " departamentos." << endl;
    }
}

void ListaDptos::Listar_dptos()
{
    ElementoDpto* paux;
    paux = pElDepartamentoPrim;

    while (paux != NULL)
    {
         //printf(" Aluno %s matriculado na Disciplina %s. \n", aux->Get_nome(), nome);
		 cout << " Departamento " << paux->Get_nome() << " da universidade " << nome << "." << endl;
         paux = paux->pNext;
    }
}

void ListaDptos::Listar_dptos2()
{
    ElementoDpto* paux;
    paux = pElDepartamentoAtual;

    while (paux != NULL)
    {
       //printf(" Aluno %s matriculado na Disciplina %s \n", aux->Get_nome(), nome);
	   cout << " Departamento " << paux->Get_nome() << " da Universidade" << nome << "." << endl;
       paux = paux->pPrev;
    }

}
