#ifndef _ALUNO_H_
#define _ALUNO_H_

#include "pessoa.h"
#include "departamento.h"

class Aluno: public Pessoa{
    private:
        int id;
        int RA;
        Departamento* dptoFiliado;

    public:
        Aluno(int diaNa, int mesNa, int anoNa, char* nome = "");
        Aluno(int i);
        Aluno();
        ~Aluno();

        void Set_ra(int ra);
        int Get_ra();

        void Set_departamento (Departamento* dpto);
    	Departamento* Get_departamento();

        void Set_id(int i);
        int Get_id();

};

#endif
