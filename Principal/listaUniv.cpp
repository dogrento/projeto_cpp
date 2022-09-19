#include "listaUniv.h"

ListaUnivs::ListaUnivs(int nu, char* n)
{
	numUniv = nu;
	countUniv = 0;           

	pElUniversidadePrim  = NULL;
	pElUniversidadeAtual = NULL;

	strcpy (nome, n ); 
}

ListaUnivs::~ListaUnivs()
{
   ElementoUniv *paux1, *paux2;
   
   paux1 = pElUniversidadePrim;
   paux2 = paux1;

   while (paux1 != NULL)
   {
	     paux2 = paux1->pNext;
	     delete (paux1);
         paux1 = paux2;		 
   }

   pElUniversidadePrim  = NULL;
   pElUniversidadeAtual = NULL;
}

void ListaUnivs::Incluir_univ ( Universidade* pu )
{
    // Aqui � criado um ponteiro para LAluno
    ElementoUniv* paux;

    // Aqui � criado um objeto LAluno, sendo seu endere�o armazenado em aux
    paux = new ElementoUniv ( );

    // Aqui recebe uma c�pia do objeto interm.
    paux->Set_univ ( pu );

    paux->pNext = NULL;
    paux->pPrev = NULL;

    if ( 
		  ( ( countUniv < numUniv ) && ( pu != NULL) )     ||
		  ( ( numUniv == -1 )		&& ( pu != NULL) )
	   )
    {
    
      if ( pElUniversidadePrim == NULL )
      {
         pElUniversidadePrim   = paux;
         pElUniversidadeAtual  = paux;
      }
      else
      {
         pElUniversidadeAtual->pNext	= paux;
         paux->pPrev					= pElUniversidadeAtual;
         pElUniversidadeAtual		= paux;
      }
      countUniv++;

    }
    else
    {
       //printf ("Aluno n�o inclu�do. Turma j� lotada em %i alunos \n", numero_alunos );
	   cout << "Universidade n�o inclu�da. Sistema j� lotado em " << numUniv << " universidades." << endl;
    }

}

void ListaUnivs::Listar_univ()
{
    ElementoUniv* paux;
    paux = pElUniversidadePrim;

    while (paux != NULL)
    {
         //printf(" Aluno %s matriculado na Disciplina %s. \n", aux->getNome(), nome);
		 cout << " Universidade " << paux->Get_nome() << " no sistema " << nome << "." << endl;
         paux = paux->pNext;
    }
}

void ListaUnivs::Listar_univ2()
{
    ElementoUniv* paux;
    paux = pElUniversidadeAtual;

    while (paux != NULL)
    {
       //printf(" Aluno %s matriculado na Disciplina %s \n", aux->getNome(), nome);
	   cout << " Universidade " << paux->Get_nome() << " no sistema " << nome << "." << endl;
       paux = paux->pPrev;
    }
}

Universidade* ListaUnivs::Localizar(char* n)
{
	ElementoUniv* paux;
    paux = pElUniversidadePrim;
    while (paux != NULL)
    {
		if (0 == strcmp(n, paux->Get_nome()))
		{
			return paux->Get_univ();
		}
        paux = paux->pNext;
    }
	return NULL;
}
