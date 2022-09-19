#include "departamento.h"
#include "universidade.h"
#include "listaDisc.h"

Departamento::Departamento(int i){
	id = i;
	objDisc = new ListaDisc(-1, "");
}

Departamento::~Departamento(){
	if(objDisc){
		delete objDisc;
	}
}

int Departamento::Get_id(){
	return id;
}

void Departamento::Set_nome(const char dpto_nome[]){
	strcpy(nomeDpto, dpto_nome);
	objDisc->Set_nome(dpto_nome);
}

char* Departamento::Get_nome(){
	return nomeDpto;
}

void Departamento::Set_universidade(Universidade* univ){
	univFiliado = univ;
}

Universidade* Departamento::Get_universidade(){
	return univFiliado;
}

void Departamento::Set_disciplina(Disciplina* disc){
	objDisc->Incluir_disc(disc);
}

void Departamento::Listar_disc(){
	objDisc->Listar_disc();
}

void Departamento::Listar_disc2(){
	objDisc->Listar_disc2();
}