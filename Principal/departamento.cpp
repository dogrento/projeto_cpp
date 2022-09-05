#include "departamento.h"

Departamento::Departamento(){
	id = -1;
	strcpy(nome_departamento, "");
}

Departamento::~Departamento(){
}

int Departamento::getId(){
	return id;
}

void Departamento::setNome(const char* dpto_nome){
	strcpy(nome_departamento, dpto_nome);
}

char* Departamento::getNome(){
	return nome_departamento;
}
