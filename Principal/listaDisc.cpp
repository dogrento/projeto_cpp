#include <iostream>
using std::cout;
using std::endl;
#include "listaDisc.h"

ListaDisc::ListaDisc(int nd, char* n){
    num_disc = nd;
    count_disc = 0;

    pElementoDiscPrim = NULL;
    pElementoDiscAtual = NULL;

    strcpy(nomeDisc, n);
}

ListaDisc::~ListaDisc()
{
    ElementoDisc *pAux1, 
                 *pAux2;

    pAux1 = pElementoDiscPrim;
    pAux2 = pElementoDiscAtual;

    while(pAux1!=NULL){
        pAux2 = pAux1->pNext;
        delete(pAux1);
        pAux1 = pAux2;
    }

    pElementoDiscPrim = NULL;
    pElementoDiscAtual = NULL;
}

void ListaDisc::Incluir_disc(Disciplina* pd){
    // ponteiro para lista de alunos
    ElementoDisc* pAux;

    // cria um objeto lista aluno com seu endereço
    // armazenado em aux
    pAux = new ElementoDisc();

    // recebe uma COPIA do obj
    pAux->Set_disc(pd);

    pAux->pNext = NULL;
    pAux->pPrev = NULL;

    if(
        (count_disc<num_disc) && (pd != NULL) ||
        ((num_disc == -1) && (pd!= NULL))
    ){
        if(pElementoDiscPrim == NULL){
            pElementoDiscPrim = pAux;
            pElementoDiscAtual = pAux;
        }
        else{
            pElementoDiscAtual->pNext = pAux;
            pAux->pPrev = pElementoDiscAtual;
            pElementoDiscAtual = pAux;
        }
        count_disc++;
    }

    else{
        cout<<"Disciplina não incluída. Quantia de disciplina lotada em "<< num_disc<< "disciplinas."<<endl;
    }
}

void ListaDisc::Listar_disc(){
    ElementoDisc* pAux = pElementoDiscPrim;

    while(pAux != NULL){
        cout << "Disciplina " << pAux->Get_nome() << " do departamento "<< nomeDisc <<"." << endl;
        pAux = pAux->pNext;
    }
}

void ListaDisc::Listar_disc2(){
    ElementoDisc* pAux = pElementoDiscAtual;

    while (pAux != NULL)
    {
        cout << " Disciplina " << pAux->Get_nome() << " do Departamento " << nomeDisc << "."<< endl;
    }
}