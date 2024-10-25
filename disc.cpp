#include "disc.h"

Disc::Disc(int id, int n, const char ac[]){
    ID = id;
    strcpy(areaConhecimento, ac);
};

Disc::~Disc(){};