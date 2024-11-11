#include "myList.h"

/*
    CLASSE DPTOEL
*/
MyList::DptoEl::DptoEl(){
    pNextDpto = nullptr;
    pPrevDpto = nullptr;
}

MyList::DptoEl::~DptoEl(){
    pNextDpto = nullptr;
    pPrevDpto = nullptr;
}

void MyList::DptoEl::setDpto(Dpto* pd){
    pDpto = pd;
}

Dpto* MyList::DptoEl::getDpto(){
    return pDpto;
}

/*
    CLASSE DPTOLIST
*/
MyList::DptoList::DptoList(int cd, int md){
    countDpto = cd;
    maxDpto   = md;
}

MyList::DptoList::DptoList():
countDpto(0),
maxDpto(-1)
{
    pFirstDptoEl = nullptr;
    pAtDptoEl    = nullptr;
}

MyList::DptoList::~DptoList(){
    MyList::DptoEl *paux1, *paux2;

    paux1 = pFirstDptoEl;
    paux2 = paux1;

    while(paux1 != nullptr){
        paux2 = paux1->pNextDpto;
        delete(paux1);
        paux1 = paux2;
    }

    pFirstDptoEl = nullptr;
    pAtDptoEl    = nullptr;
}

void MyList::DptoList::insertDpto(Dpto* d){
    if(
        (countDpto < maxDpto) && (d != nullptr) ||
        (maxDpto == -1)       && (d != nullptr)
    ){
        MyList::DptoEl* paux;
        paux = new DptoEl();

        paux->setDpto(d);
        
        // Se lista estiver vazia
        if(pFirstDptoEl == nullptr){
            pFirstDptoEl = paux;
            pAtDptoEl = paux;
        }else{ // se nao
            pAtDptoEl->pNextDpto = paux;
            paux->pPrevDpto      = pAtDptoEl;
            pAtDptoEl            = paux;
        }
        countDpto++;
    }
    else{
        cerr << "Departamento nao pode se inserida."
             << "Quantidade de dpto ja lotada em: "
             << maxDpto << " departamentos." << endl; 
             
    }
}
