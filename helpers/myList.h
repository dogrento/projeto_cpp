#pragma once

#include "../dpto.h"

class MyList{
    public:
    class DptoEl{
        /* ATRIBUTOS */
        private:
        Dpto* pDpto;
        
        /* METODOS */
        public:
        DptoEl();
        ~DptoEl();

        DptoEl* pNextDpto;
        DptoEl* pPrevDpto;

        void setDpto(Dpto* pd);
        Dpto* getDpto();
    };

    class DptoList{
        /* ATRIBUTOS */
        private:
        MyList::DptoEl* nextDptoEl;
        MyList::DptoEl* prevDptoEl;
        
        /* METODOS */
    };
};