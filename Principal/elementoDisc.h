#ifndef _ELEMENTODISC_H_
#define _ELEMENTODISC_H_

#include "disciplina.h"

class ElementoDisc{
    private:
        Disciplina* pDisc;

    public:
        ElementoDisc* pNext;
        ElementoDisc* pPrev;

        void Set_disc(Disciplina* pd);
        Disciplina* Get_disc();

        char* Get_nome();
};

#endif