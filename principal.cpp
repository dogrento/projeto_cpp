#include "principal.h"
#include <chrono>
#include <ctime>

Principal::Principal(){
    profInit();
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


    prof0.calcIdade(diaAtual, mesAtual, anoAtual);
    prof1.calcIdade(diaAtual, mesAtual, anoAtual);
    prof2.calcIdade(diaAtual, mesAtual, anoAtual);
    einstein.calcIdade(diaAtual, mesAtual, anoAtual);
    newton.calcIdade(diaAtual, mesAtual, anoAtual);

    prof0.informaInfo();
    printf("\n");
    prof1.informaInfo();
    printf("\n");
    prof2.informaInfo();
    printf("\n");
    einstein.informaInfo();
    printf("\n");
    newton.informaInfo();
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

void Principal::profInit(){
    prof0.init(24, 11, 1945, "Professor Zero");
    prof1.init(24, 11, 1946, "Professor Um");
    prof2.init(24, 11, 1947, "Professor Dois");
    einstein.init(14, 3, 1879, "Albert einstein");
    newton.init(4, 1, 1643, "Isaac newton");
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
    prof0.setUniversidade(&utfpr);
    prof1.setUniversidade(&utfpr);
    prof2.setUniversidade(&utfpr);
    einstein.setUniversidade(&princeton);
    newton.setUniversidade(&cambridge);
}

void Principal::setProfDpto(){
    prof0.setDpto(&daeln);
    prof1.setDpto(&dpto1);
    prof2.setDpto(&dpto2);
    einstein.setDpto(&fisica);
    newton.setDpto(&mat);
}