#include "elementoDisc.h"

ElementoDisc::ElementoDisc(){
    pNext = NULL;
    pPrev = NULL;
}

ElementoDisc::~ElementoDisc(){
    pNext = NULL;
    pPrev = NULL;
}

void ElementoDisc::Set_disc(Disciplina* pd){
    pDisc = pd;
}

Disciplina* ElementoDisc::Get_disc(){
    return pDisc;
}

char* ElementoDisc::Get_nome(){
    return pDisc->Get_disc();
}