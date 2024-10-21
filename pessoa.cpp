#include "pessoa.h"
#include "universidade.h"
#include <iostream>
using std::cout;
using std::endl;

// Construtora
Pessoa::Pessoa(int dia, int mes, int ano, const char nome[]){ // C++ exige const char*. Razao: essa variavel é criada apenas durante a chamada da func 
  init(dia, mes, ano, nome);
}
Pessoa::Pessoa(){
  init(0,0,0);
}

// metodo para inicializar o objeto.
void Pessoa::init(int dia, int mes, int ano, const char nome[]){
  idadeP = 0;
  diaP = dia;
  mesP = mes;
  anoP = ano;
  strcpy(nomeP, nome); // jeito certo; jeito errado -> nomeP = nome. Razao: nesse caso, nomeP receberia o ponteiro da variavel temporaria nome. Ao sair da funcao nomeP seria indeterminado.
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

// retorna idadeP do objeto.
int Pessoa::getIdade(){
  return idadeP;
}

void Pessoa::setUniversidade(Universidade* uni){
  uniP = uni;
}

void Pessoa::setDpto(Dpto* d){
  dptoP = d;
}

void Pessoa::informaUni(){
  cout << uniP << endl;
}

void Pessoa::informaInfo(){
  cout << nomeP << ": tem/teria " << idadeP << " anos de idade." << endl;
  cout << "Estuda/trabalha em: " << uniP->getUni() << endl; 
  // cout << "Dpto: " << dptoP->getDpto() << endl; 
  dptoP->informaDpto();
}