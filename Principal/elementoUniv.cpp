#include "elementoUniv.h"

ElementoUniv::ElementoUniv()
{
	pNext = NULL;
    pPrev = NULL;
}

ElementoUniv::~ElementoUniv()
{
	pNext = NULL;
    pPrev = NULL;
}

void ElementoUniv::Set_univ(Universidade *pu) 
{  
    pUniv = pu; 
}

Universidade* ElementoUniv::Get_univ() 
{   
   return pUniv; 
}

char* ElementoUniv::Get_nome() 
{
    return pUniv->Get_nome(); 
}

