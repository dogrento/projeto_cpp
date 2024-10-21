#include "principal.h"
#include <chrono>
#include <ctime>

Principal::Principal(){
    fulano.init(24, 11, 1945, "fulano cicrano");
    Einstein.init(14, 3, 1879, "Albert Einstein");
    Newton.init(4, 1, 1643, "Isaac Newton");

    utfpr.setUni("Universidade Tecnologica Federal do Parana");
    princeton.setUni("Princeton");
    cambridge.setUni("Cambridge");

    daeln.setDpto("DAELN");
    fisica.setDpto("FISICA");
    mat.setDpto("MATEMATICA");

    fulano.setUniversidade(&utfpr);
    Einstein.setUniversidade(&princeton);
    Newton.setUniversidade(&cambridge);

    fulano.setDpto(&daeln);
    Einstein.setDpto(&fisica);
    Newton.setDpto(&mat);
    exec();
}

Principal::~Principal(){}

void Principal::exec(){
    // Obter a data e hora atual
    auto now = std::chrono::system_clock::now();  
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

    // Converter para uma estrutura tm
    std::tm* localTime = std::localtime(&currentTime);

    // Extrair o dia, mês e ano
    int diaAtual = localTime->tm_mday;
    int mesAtual = localTime->tm_mon + 1; // Janeiro é 0, então somamos 1
    int anoAtual = localTime->tm_year + 1900; // Ano é contado desde 1900


    fulano.calcIdade(diaAtual, mesAtual, anoAtual);
    Einstein.calcIdade(diaAtual, mesAtual, anoAtual);
    Newton.calcIdade(diaAtual, mesAtual, anoAtual);

    fulano.informaInfo();
    Einstein.informaInfo();
    Newton.informaInfo();
}