#include <iostream>
using namespace std;

#include "../dpto.h"
#include "../universidade.h"
#include "../helpers/myList.h"

int main(){
    Universidade u1, u2, u3;
    Dpto d1, d2, d3, d4, d5, d6;
    MyList::DptoList dlist;

    u1.setName("Universidade federal 1");
    u2.setName("Universidade federal 2");
    u3.setName("Universidade federal 3");

    d1.setName("dpto generico1");
    d2.setName("dpto generico2");
    d3.setName("dpto generico3");
    d4.setName("dpto generico4");
    d5.setName("dpto generico5");
    d6.setName("dpto generico6");

    u1.setDptoList(&d1);
    u1.setDptoList(&d2);
    u1.setDptoList(&d3);

    u2.setDptoList(&d4);
    u2.setDptoList(&d5);
    u2.setDptoList(&d6);

    u1.informaDptoList();
    u2.informaDptoList();
    u3.informaDptoList();

    // dlist.insertDpto(&d1);
    // dlist.insertDpto(&d2);
    // dlist.insertDpto(&d3);

    // dlist.showDptoList();
    return 0;
}