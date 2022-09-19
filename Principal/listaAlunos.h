#ifndef _LISTAALUNOS_H_
#define _LISTAALUNOS_H_

#include "elemento.h"
#include "aluno.h"

class ListaAlunos{
    private:
        int countAlunos;
        int numAlunos;
        char nome[150];

        //template class
        Elemento<Aluno>* elAlunoPrim;
        Elemento<Aluno>* elAlunoAtual;

    public:
        ListaAlunos(int na = -1, char* n = "");
        ~ListaAlunos();
        void Limpa_lista();
        void Inclua_aluno(Aluno* aluno);

        void Listar_alunos();
        void Listar_alunos2();

        void Grave_alunos();
        void Recuperar_alunos();
};

#endif