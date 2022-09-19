#ifndef _ELEMENTOUNIV_H_
#define _ELEMENTOUNIV_H_

#include "universidade.h"

class ElementoUniv
{
 private:
    Universidade* pUniv;

 public:
    ElementoUniv( );
    ~ElementoUniv( );
    ElementoUniv *pNext;
    ElementoUniv *pPrev;
    void Set_univ(Universidade* pu);
    Universidade* Get_univ ( );
    char* Get_nome();
};

#endif
