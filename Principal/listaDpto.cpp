#include "listaDisc.h"

ListaDisc::ListaDisc(int nd, char* n)
{
	num_disc		= nd;
	count_disc		= 0;           

	pElementoDiscPrim  = NULL;
	pElementoDiscAtual = NULL;

	strcpy (nomeDisc, n ); 
}

ListaDisc::~ListaDisc()
{
   ElementoDisc *paux1, *paux2;
   
   paux1 = pElementoDiscPrim;
   paux2 = paux1;

   while (paux1 != NULL)
   {
	     paux2 = paux1->pNext;
	     delete (paux1);
         paux1 = paux2;		 
   }

   pElementoDiscPrim  = NULL;
   pElementoDiscAtual = NULL;
}


void ListaDisc::Set_nome(const char* n)
{
	strcpy(nomeDisc, n);
}

void ListaDisc::Incluir_disc(Disciplina* pd)
{
    // Aqui � criado um ponteiro para LAluno
    ElementoDisc* paux;
    // Aqui � criado um objeto LAluno, sendo seu endere�o armazenado em aux
    paux = new ElementoDisc ( );

    // Aqui recebe uma c�pia do objeto interm.
    paux->Set_disc ( pd );

    paux->pNext = NULL;
    paux->pPrev = NULL;

    if ( 
		  ( ( count_disc < num_disc ) && ( pd != NULL) ) 
		  ( ( num_disc == -1 )		&& ( pd != NULL) )
	   )
    {
    
      if ( pElementoDiscPrim == NULL )
      {
         pElementoDiscPrim   = paux;
         pElementoDiscAtual  = paux;
      }
      else
      {
         pElementoDiscAtual->pNext	= paux;
         paux->pPrev				= pElementoDiscAtual;
         pElementoDiscAtual         = paux;
      }
      count_disc++;

    }
    else
    {
       //printf ("Aluno n�o inclu�do. Turma j� lotada em %i alunos \n", numero_alunos );
	   cout << "Disciplina n�o inclu�da. Quantia de disc. j� lotada em " << num_disc << " disciplinas." << endl;
    }
}

void ListaDisc::Listar_disc()
{
    ElementoDisc* paux;
    paux = pElementoDiscPrim;

    while (paux != NULL)
    {
         //printf(" Aluno %s matriculado na Disciplina %s. \n", aux->getNome(), nome);
		 cout << " Disciplina " << paux->Get_nome() << " do deparatamento " << nomeDisc << "." << endl;
         paux = paux->pNext;
    }
}

void ListaDisc::Listar_disc2()
{
    ElementoDisc* paux;
    paux = pElementoDiscAtual;

    while (paux != NULL)
    {
       //printf(" Aluno %s matriculado na Disciplina %s \n", aux->getNome(), nome);
	   cout << " Disciplina " << paux->Get_nome() << " do Departamento " << nomeDisc << "." << endl;
       paux = paux->pPrev;
    }

}