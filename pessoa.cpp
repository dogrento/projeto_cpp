#include "pessoa.h"
#include "universidade.h"
#include <iostream>
using std::cout;
using std::endl;

// Construtora
Pessoa::Pessoa(int dia, int mes, int ano, const char nome[], int id){ // C++ exige const char*. Razao: essa variavel é criada apenas durante a chamada da func 
  init(dia, mes, ano, nome, id);
}
Pessoa::Pessoa(){
  init(0,0,0);
}

Pessoa::~Pessoa(){}

// metodo para inicializar o objeto.
void Pessoa::init(int dia, int mes, int ano, const char nome[], int id){
  idadeP = 0;
  diaP = dia;
  mesP = mes;
  anoP = ano;
  // strcpy(nomeP, nome); // jeito certo; jeito errado -> nomeP = nome. Razao: nesse caso, nomeP receberia o ponteiro da variavel temporaria nome. Ao sair da funcao nomeP seria indeterminado.
  setName(nome);
  setID(id);
}

// calcula e informa idade.
void Pessoa::calcIdade(int diaAtual, int mesAtual, int anoAtual){
  idadeP = anoAtual - anoP;

  if(mesAtual < mesP)
    idadeP = idadeP-1;
  else
    if (mesP == mesAtual) {
      if (diaP < diaAtual) {
        idadeP = idadeP-1;
      }
    }
}

void Pessoa::informaInfo(){
  cout << "ID: " << getID() << endl;
  cout << "Nome: " << getName() << endl;
  cout << "Idade: " << getIdade() << endl;
}