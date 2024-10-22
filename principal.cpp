#include "principal.h"
#include <chrono>
#include <ctime>

Principal::Principal(){
    fulano0.init(24, 11, 1945, "Fulano Zero");
    fulano1.init(24, 11, 1946, "Fulano Um");
    fulano2.init(24, 11, 1947, "Fulano Dois");
    Einstein.init(14, 3, 1879, "Albert Einstein");
    Newton.init(4, 1, 1643, "Isaac Newton");

    utfpr.setUni("Universidade Tecnologica Federal do Parana");
    princeton.setUni("Princeton");
    cambridge.setUni("Cambridge");

    daeln.setDpto("DAELN");
    dpto1.setDpto("dpto1");
    dpto2.setDpto("dpto2");
    fisica.setDpto("FISICA");
    mat.setDpto("MATEMATICA");

    utfpr.setDpto(&daeln, 0);
    utfpr.setDpto(&dpto1, 1);
    utfpr.setDpto(&dpto2, 2);
    princeton.setDpto(&fisica, 0);
    cambridge.setDpto(&mat, 0);

    fulano0.setUniversidade(&utfpr);
    fulano1.setUniversidade(&utfpr);
    fulano2.setUniversidade(&utfpr);
    Einstein.setUniversidade(&princeton);
    Newton.setUniversidade(&cambridge);

    fulano0.setDpto(&daeln);
    fulano1.setDpto(&dpto1);
    fulano2.setDpto(&dpto2);
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


    fulano0.calcIdade(diaAtual, mesAtual, anoAtual);
    fulano1.calcIdade(diaAtual, mesAtual, anoAtual);
    fulano2.calcIdade(diaAtual, mesAtual, anoAtual);
    Einstein.calcIdade(diaAtual, mesAtual, anoAtual);
    Newton.calcIdade(diaAtual, mesAtual, anoAtual);

    fulano0.informaInfo();
    printf("\n");
    fulano1.informaInfo();
    printf("\n");
    fulano2.informaInfo();
    printf("\n");
    Einstein.informaInfo();
    printf("\n");
    Newton.informaInfo();
    printf("\n");

    cout << "Departamentos: " << endl;
    utfpr.informaDpto();
    printf("\n");
    princeton.informaDpto();
    printf("\n");
    cambridge.informaDpto();
    printf("\n");
}