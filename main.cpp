#include <stdio.h>
#include "pessoa.h"

int main(){
  Pessoa Douglas(13, 02, 1993, "Douglas Oshiro");
  Pessoa Einstein(14, 3, 1879, "Albert Einstein");
  Pessoa Newton(4, 1, 1643, "Isaac Newton");

  Douglas.calcIdade(10, 10, 2024);
  Einstein.calcIdade(10, 10, 2024);
  Newton.calcIdade(10, 10, 2024);

  return 0;
}
