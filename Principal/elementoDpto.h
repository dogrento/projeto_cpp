#ifndef _ELEMENTODPTO_H_
#define _ELEMENTODPTO_H_

#include "departamento.h"

class ElementoDpto
{
 private:
    Departamento* pDpto;

 public:
    ElementoDpto( );
    ~ElementoDpto( );
    ElementoDpto *pNext;
    ElementoDpto *pPrev;
    void Set_dpto(Departamento* pd);
    Departamento* Get_dpto ( );

    char* Get_nome();
};

#endif