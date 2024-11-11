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
        int countDpto;
        int maxDpto; 
        
        MyList::DptoEl* pFirstDptoEl;
        MyList::DptoEl* pAtDptoEl;
        
        /* METODOS */
        public:
        DptoList(int cd, int md);
        DptoList();
        ~DptoList();

        void insertDpto(Dpto* d);

        void showDptoList(){
            DptoEl* paux;
            paux = pFirstDptoEl;

            while(paux != nullptr){
                cout << "Departamento: " << paux->getDpto()->getName() << endl;
                paux = paux->pNextDpto;
            }
        };
    };
};