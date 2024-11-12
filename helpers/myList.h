#pragma once

#include "../src/dpto.h"

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
        bool isEmpty() const{return pFirstDptoEl == nullptr;};

        void salvarDpto(ofstream& f){
            DptoEl* paux;
            paux = pFirstDptoEl;

            while(paux!=nullptr){
                cout << "Salvando " << paux->getDpto()->getName() << endl;
                paux->getDpto()->salvaDpto(f);
                paux = paux->pNextDpto;
            }
        }

        DptoList* recuperaDpto(ifstream& f){
            Dpto* d;
            DptoList* dl = new DptoList;
            DptoEl* paux;
            paux = pFirstDptoEl;

            while (paux != nullptr)
            {
                d = new Dpto;
                d = paux->getDpto()->recuperaDpto(f);
                dl->insertDpto(d);
                paux = paux->pNextDpto;
            }
            return dl;
        }

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