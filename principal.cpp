#include "principal.h"
#include <chrono>
#include <ctime>

Principal::Principal(){

    menu();
    profInit();
    alunoInit();
    universidadeInit();
    dptoInit();
    discInit();

    setUniDpto();
    setProfUni();
    setProfDpto();
    setDptoDisc();
    setAlunoDisc();
    exec();
}

Principal::~Principal(){}

void Principal::menu(){
    int opt = -1;
    system("clear");
    cout << " opt 1" << endl;
    cout << " opt 2" << endl;
    cout << " opt 3" << endl;
    cout << " opt 4" << endl;
    cout << " opt 5" << endl;
    cin >> opt;

    switch(opt){
        case 1: { cout << "opt 1" << endl;}
        case 2: { cout << "opt 2" << endl;}
        case 3: { cout << "opt 3" << endl;}
        case 4: { cout << "opt 4" << endl;}
        case 5: { cout << "opt 5" << endl;}
    }
}

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
    utfpr.informaDptoList();
    printf("\n");
    princeton.informaDptoList();
    printf("\n");
    cambridge.informaDptoList();
    printf("\n");

    cout << "Listando Disciplinas dos Departamentos: " << endl;
    daeln.listDisc();
    dpto1.listDisc();
    dpto2.listDisc();
    fisica.listDisc();
    mat.listDisc();

    cout << "Listando alunos matriculados de disciplinas:" << endl;
    daelDisc0.listAlunos();
    daelDisc1.listAlunos();
}

void Principal::profInit(){
    cout << "Inicializando Objetos: Professor"<< endl;
    prof0.init(24, 11, 1945, "Professor Zero");
    prof1.init(24, 11, 1946, "Professor Um");
    prof2.init(24, 11, 1947, "Professor Dois");
    einstein.init(14, 3, 1879, "Albert einstein");
    newton.init(4, 1, 1643, "Isaac newton");
}

void Principal::alunoInit(){
    cout << "Inicializando Objetos: Aluno"<< endl;
    aluno0.init(24, 11, 1950, "Aluno Zero");
    aluno1.init(24, 11, 1960, "Aluno Um");

    aluno0.setRa("1234567");
    aluno1.setRa("7654321");
}

void Principal::universidadeInit(){
    cout << "Inicializando Objetos: Universidade"<< endl;
    utfpr.setName("Universidade Tecnologica Federal do Parana");
    princeton.setName("Princeton");
    cambridge.setName("Cambridge");
}

void Principal::dptoInit(){
    cout << "Inicializando Objetos: Dpto"<< endl;
    daeln.setName("DAELN");
    dpto1.setName("dpto1");
    dpto2.setName("dpto2");
    fisica.setName("FISICA");
    mat.setName("MATEMATICA");
}

void Principal::discInit(){
    cout << "Inicializando Objetos: Disc"<< endl;
    daelDisc0.setName("Disc0_Gen_daeln0"); 
    daelDisc1.setName("Disc1_Gen_daeln1"); 
    dpto1Disc0.setName("Disc0_Gen_dpto1");
    dpto1Disc1.setName("Disc1_Gen_dpto1");
    dpto2Disc0.setName("Disc0_Gen_dpto2");
    dpto2Disc1.setName("Disc1_Gen_dpto2");
    fisDisc.setName("Fisica_Gen_dptoFisica");
    matDisc.setName("Matematica_Gen_dptoMatematica");
}

void Principal::setUniDpto(){
    cout << "Associando Dpto a Universidades."<< endl;
    utfpr.setDptoList(&daeln, 0);
    utfpr.setDptoList(&dpto1, 1);
    utfpr.setDptoList(&dpto2, 2);
    princeton.setDptoList(&fisica, 0);
    cambridge.setDptoList(&mat, 0);
}

void Principal::setProfUni(){
    cout << "Asssociando Professores a Universidades."<< endl;
    prof0.setUni(&utfpr);
    prof1.setUni(&utfpr);
    prof2.setUni(&utfpr);
    einstein.setUni(&princeton);
    newton.setUni(&cambridge);
}

void Principal::setProfDpto(){
    cout << "Associando departamento a Professor"<< endl;
    prof0.setDpto(&daeln);
    prof1.setDpto(&dpto1);
    prof2.setDpto(&dpto2);
    einstein.setDpto(&fisica);
    newton.setDpto(&mat);
}

void Principal::setDptoDisc(){
    cout << "Adicioanndo Disciplinas a Departamentos." << endl;
    daelDisc0.setDpto(&daeln);
    daelDisc1.setDpto(&daeln);

    dpto1Disc0.setDpto(&dpto1);
    dpto1Disc1.setDpto(&dpto1);

    dpto2Disc0.setDpto(&dpto2);
    dpto2Disc1.setDpto(&dpto2);

    fisDisc.setDpto(&fisica);
    matDisc.setDpto(&mat);
}

void Principal::setAlunoDisc(){
    daelDisc0.insertAluno(&aluno0);
    daelDisc0.insertAluno(&aluno1);
}