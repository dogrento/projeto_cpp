#include "myList.h"

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