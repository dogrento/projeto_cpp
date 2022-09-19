#include "elementoDpto.h"

ElementoDpto::ElementoDpto()
{
	pNext = NULL;
    pPrev = NULL;
}

ElementoDpto::~ElementoDpto()
{
	pNext = NULL;
    pPrev = NULL;
}

void ElementoDpto::Set_dpto(Departamento *pd) 
{  
   pDpto = pd; 
}

Departamento* ElementoDpto::Get_dpto() 
{   
   return pDpto; 
}

char* ElementoDpto::Get_nome() 
{
    return pDpto->Get_nome(); 
}

