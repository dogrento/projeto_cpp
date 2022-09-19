#ifndef _LISTADISC_H_
#define _LISTADISC_H_

#include "elementoDisc.h"
#include "disciplina.h"

class ListaDisc{
    private:
        int count_disc,
            num_disc;
        
        char nomeDisc[150];
        
        ElementoDisc* pElementoDiscPrim;
        ElementoDisc* pElementoDiscAtual;

    public:
        ListaDisc(int nd = 100, char* n="");
        ~ListaDisc();

        void Set_nome(const char* n);
        void Incluir_disc(Disciplina* pd);
        void Listar_disc();
        void Listar_disc2();

};

#endif