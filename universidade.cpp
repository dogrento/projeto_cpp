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

void Universidade::setDpto(Departamento* dpto_pessoa,int ctd){
	//agregação via ponteiros
	dpto_list[ctd] = dpto_pessoa;
}

void Universidade::print_dpto(){
	for(int i=0; i<50; i++){
		if(dpto_list[i]!=NULL)
			cout << dpto_list[i]->getNome() << endl;
	}
}
