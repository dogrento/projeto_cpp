#include "universidade.h"
#include <string.h>

#include <iostream>
using std::cout;
using std::endl;

//constructor
Universidade::Universidade(){
	strcpy(nome_universidade, "");
}

//destructor: ela zera alguns elementos do objeto 
Universidade::~Universidade(){
}

void Universidade::setNome(const char n[]){
	strcpy(nome_universidade, n);
}

void Universidade::setLocal(const char nome_local[]){
	strcpy(local_universidade, nome_local);
}

char* Universidade::getNome(){
	return nome_universidade;
}

char* Universidade::getLocal(){
	return local_universidade;
}

void Universidade::setDpto(Departamento* dpto_pessoa){
	//agregação via ponteiros
	lista_departamento.push_back(dpto_pessoa);
}

void Universidade::print_dpto(){
	int tam = (int)lista_departamento.size();

	for(int i=0; i<tam; i++){
		cout << lista_departamento[i]->getNome() << endl;
	}
}
