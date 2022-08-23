#include "universidade_class.h"
#include <string.h>

//constructor
Universidade::Universidade(const char n[]){
	strcpy(nome, n);
}

//destructor: ela zera alguns elementos do objeto 
Universidade::~Universidade(){

}

void Universidade::setNome(const char n[]){
	strcpy(nome, n);
}

void Universidade::setLocal(const char nome_local[]){
	strcpy(local,nome_local);
}

char* Universidade::getNome(){
	return nome;
}

char* Universidade::getLocal(){
	return local;
}
