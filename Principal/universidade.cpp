#include "universidade.h"
#include <string.h>

#include <iostream>
using std::cout;
using std::endl;

Universidade::Universidade():
objLDptos(-1, "")
{
}

Universidade::~Universidade()
{
}

char* Universidade::Get_nome()
{
   return nome_universidade;
}

void Universidade::Set_nome(const char* n)
{
   strcpy(nome_universidade, n);
   objLDptos.Set_nome(n);
}

void Universidade::Incluir_dpto (Departamento* pd)
{
    objLDptos.Inclua_dpto(pd);
}

void Universidade::Listar_dpto()
{
    objLDptos.Listar_dptos();
}

void Universidade::Listar_dpto2()
{
    objLDptos.Listar_dptos2();
}

//constructor
// Universidade::Universidade(){
// 	strcpy(nome_universidade, "");
// }

// //destructor: ela zera alguns elementos do objeto 
// Universidade::~Universidade(){
// }

// void Universidade::Set_nome(const char n[]){
// 	strcpy(nome_universidade, n);
// }

// void Universidade::setLocal(const char nome_local[]){
// 	strcpy(local_universidade, nome_local);
// }

// char* Universidade::Get_nome(){
// 	return nome_universidade;
//nome_universidade }

// char* Universidade::getLocal(){
// 	return local_universidade;
// }

// void Universidade::setDpto(Departamento* dpto_pessoa){
// 	//agregação via ponteiros
// 	lista_departamento.push_back(dpto_pessoa);
// }

// void Universidade::print_dpto(){
// 	int tam = (int)lista_departamento.size();

// 	for(int i=0; i<tam; i++){
// 		cout << lista_departamento[i]->Get_nome() << endl;
// 	}
//nome_universidade }
