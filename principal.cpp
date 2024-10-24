#include "principal.h"
#include <chrono>
#include <ctime>

Principal::Principal(){
    professorInit();
    alunoInit();
    universidadeInit();
    dptoInit();
    setUniDpto();
    setProfUni();
    setProfDpto();
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


    professor0.calcIdade(diaAtual, mesAtual, anoAtual);
    professor1.calcIdade(diaAtual, mesAtual, anoAtual);
    professor2.calcIdade(diaAtual, mesAtual, anoAtual);
    Einstein.calcIdade(diaAtual, mesAtual, anoAtual);
    Newton.calcIdade(diaAtual, mesAtual, anoAtual);

    professor0.informaInfo();
    printf("\n");
    professor1.informaInfo();
    printf("\n");
    professor2.informaInfo();
    printf("\n");
    Einstein.informaInfo();
    printf("\n");
    Newton.informaInfo();
    printf("\n");

    aluno0.informaInfo();
    printf("\n");
    aluno1.informaInfo();
    printf("\n");

    cout << "Departamentos: " << endl;
    utfpr.informaDpto();
    printf("\n");
    princeton.informaDpto();
    printf("\n");
    cambridge.informaDpto();
    printf("\n");
}

void Principal::professorInit(){
    professor0.init(24, 11, 1945, "Professor Zero");
    professor1.init(24, 11, 1946, "Professor Um");
    professor2.init(24, 11, 1947, "Professor Dois");
    Einstein.init(14, 3, 1879, "Albert Einstein");
    Newton.init(4, 1, 1643, "Isaac Newton");
}

void Principal::alunoInit(){
    aluno0.init(24, 11, 1950, "Aluno Zero");
    aluno1.init(24, 11, 1960, "Aluno Um");

    aluno0.setRa("1234567");
    aluno0.setRa("7654321");
}

void Principal::universidadeInit(){
    utfpr.setUni("Universidade Tecnologica Federal do Parana");
    princeton.setUni("Princeton");
    cambridge.setUni("Cambridge");
}

void Principal::dptoInit(){
    daeln.setDpto("DAELN");
    dpto1.setDpto("dpto1");
    dpto2.setDpto("dpto2");
    fisica.setDpto("FISICA");
    mat.setDpto("MATEMATICA");
}

void Principal::setUniDpto(){
    utfpr.setDpto(&daeln, 0);
    utfpr.setDpto(&dpto1, 1);
    utfpr.setDpto(&dpto2, 2);
    princeton.setDpto(&fisica, 0);
    cambridge.setDpto(&mat, 0);
}

void Principal::setProfUni(){
    professor0.setUniversidade(&utfpr);
    professor1.setUniversidade(&utfpr);
    professor2.setUniversidade(&utfpr);
    Einstein.setUniversidade(&princeton);
    Newton.setUniversidade(&cambridge);
}

void Principal::setProfDpto(){
    professor0.setDpto(&daeln);
    professor1.setDpto(&dpto1);
    professor2.setDpto(&dpto2);
    Einstein.setDpto(&fisica);
    Newton.setDpto(&mat);
}