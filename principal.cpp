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

    while(opt != 4){
        system("clear");
        cout << " Selecione uma Opção: " << endl;
        cout << "   1 - Universidade" << endl;
        cout << "   2 - Professor" << endl;
        cout << "   3 - Aluno" << endl;
        cout << "   4 - Sair" << endl;
        cout << "Input -> ";
        // cin >> opt;

         // Leitura segura para evitar erros com cin
        if (!(cin >> opt)) {
            cin.clear();  // Limpa o estado de erro
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignora o resto da linha
            cout << "Entrada inválida. Pressione Enter para continuar...";
            cin.get();  // Pausa esperando o Enter
            continue;  // Volta ao início do loop
        }

        switch(opt){
            case 1: { cout << "opt 1" << endl;
                menuUni();
            }
                break;
            case 2: { cout << "opt 2" << endl;}
                break;
            case 3: { cout << "opt 3" << endl;}
                break;
            default:{
                cout << "Opção inválida. Pressione Enter para continuar...";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignora o '\n' pendente
                cin.get();  // Espera o Enter

            }
        }
    }
}

void Principal::menuUni(){
    int opt = -1;

    while(opt != 5){
        system("clear");
        cout << "Universidades cadastradas: " << countUniCad() << endl;
        if(salvarFlag){
            cout << "Ha modificações para serem salvas." << endl;
        }
        cout << " Menu Universidade: " << endl;
        cout << "   1 - Cadastrar Universidade." << endl;
        cout << "   2 - Selecionar Universidades cadastradas." << endl;
        cout << "   3 - Salvar alterações." << endl;
        cout << "   4 - Recuperar alterações." << endl;
        cout << "   5 - Voltar." << endl;
        cout << "Input -> ";
        // cin >> opt;

        // Leitura segura para evitar erros com cin
        if (!(cin >> opt)) {
            cin.clear();  // Limpa o estado de erro
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignora o resto da linha
            cout << "Entrada inválida. Pressione Enter para continuar...";
            cin.get();  // Pausa esperando o Enter
            continue;  // Volta ao início do loop
        }

        switch(opt){
            case 1: {
                cadUni();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignora o '\n' pendente
                cin.get();  // Espera o Enter
            }
                break;
            case 2: { menuSelectUni();
                // cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignora o '\n' pendente
                // cin.get();  // Espera o Enter
            }
                break;
            case 3: { salvarUni();
                cout << "Pressione Enter para continuar...";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignora o '\n' pendente
                cin.get();  // Espera o Enter
            }break;
            case 4: { recuperarUni();
                cout << "Pressione Enter para continuar...";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignora o '\n' pendente
                cin.get();  // Espera o Enter
            }
                break;
            default:{
                cout << "Opção inválida. Pressione Enter para continuar...";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignora o '\n' pendente
                cin.get();  // Espera o Enter

            }
        }
    }
}

void Principal::menuSelectUni(){
    int opt = -1;
    int optSize = uniVector.size() + 1;

    while(opt != optSize){
        system("clear");
        listUniCad();
        cout << optSize << " - " << "Voltar" << endl;

        // Leitura segura para evitar erros com cin
        if (!(cin >> opt)) {
            cin.clear();  // Limpa o estado de erro
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignora o resto da linha
            cout << "Entrada inválida. Pressione Enter para continuar...";
            // cin.get();  // Pausa esperando o Enter
            continue;  // Volta ao início do loop
        }

        if(opt < optSize){
            uniInterface(uniVector[opt-1]);
            cout << "Pressione Enter para continuar...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignora o '\n' pendente
            cin.get();  // Espera o Enter
        }else{
            cout << "Voltar. Pressione Enter para continuar...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignora o '\n' pendente
            cin.get();  // Espera o Enter
            break;
        }
    }
}

void Principal::uniInterface(Universidade* u){
    cout << "opçao: " << u->getName() << endl;
}

void Principal::cadUni(){
    Universidade* pUni; 
    string uniName;
    string respInput;

    cout << "Informe o nome da Universidade: " << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignora o '\n' pendente
    getline(cin, uniName);
    if(!existeUni(uniName)){
        pUni = new Universidade();
        pUni->setName(uniName);
        cout << "\n" << endl;
        uniVector.push_back(pUni);

        cout << pUni->getName() << " cadastrado com sucesso." << endl;
        salvarFlag = true;
    }else{
        cerr << "Universidade ja cadastrada!" << endl;
        return;
    }
   
    // cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignora o '\n' pendente
    // getchar();

}

void Principal::salvarUni(){
    if(salvarFlag){
        ofstream arq;
        arq.open("data/gp.dat", ios::binary | ios::app);

        // escreve o tamanho do grupo
        // arq.write((char*) &uniVector, sizeof(uniVector));

        // escreve todos os obj Universidade
        for(size_t i = 0; i < uniVector.size(); i++){
            uniVector[i]->salvaUni(arq);
        }
        cout << "Salvamento completo." << endl;
        cout << "Limpando vector de universidades." << endl;
        uniVector.clear();
        salvarFlag = false;
    }else{
        cout << "Nada para salvar." << endl;
        return;
    }
}

void Principal::recuperarUni(){
    if(countUniCad() == 0){
        cout << "Nada para recuperar." << endl;
    }else{
        cout << "Recuperando Universidades." << endl;
        ifstream rUni;

        rUni.open("data/gp.dat", ios::binary | ios::in);
            // Limpar o vetor atual antes de carregar novos dados
        uniVector.clear();

        while (rUni.peek() != EOF) {  // Continuar enquanto houver dados no arquivo
            Universidade uni;
            uniVector.push_back(uni.recuperaUni(rUni));

            cout << "Universidade carregada: " << uni.getName() << 
            " "<< uni.getID() << endl;
        }
        
        rUni.close();
    }
}

bool Principal::existeUni(string un){
    cout << "Procurando Universidades." << endl;
    ifstream rUni;

    rUni.open("data/gp.dat", ios::binary | ios::in);
        // Limpar o vetor atual antes de carregar novos dados
    uniVector.clear();

    while (rUni.peek() != EOF) {  // Continuar enquanto houver dados no arquivo
        int tamanho;
        
        // Ler o tamanho do nome
        cout << "lendo tamanho" << endl;
        rUni.read(reinterpret_cast<char*>(&tamanho), sizeof(tamanho));
        if (!rUni) break;  // Sair do loop caso a leitura falhe
        
        // Ler o nome da universidade com o tamanho específico
        cout << "lendo nome" << endl;
        std::string nome(tamanho, '\0');  // Inicializar a string com o tamanho necessário
        rUni.read(&nome[0], tamanho);
        if (!rUni) break;  // Sair do loop caso a leitura falhe

        cout << "lendo id" << endl;
        int id;  // Inicializar a string com o tamanho necessário
        rUni.read((char*)&id, sizeof(id));
        if (!rUni) break;  // Sair do loop caso a leitura falhe
        
        if(nome == un){
            rUni.close();
            return true;
        }
    }
    
    rUni.close();
    return false;
}

int Principal::countUniCad(){
    ifstream arq("data/gp.dat", ios::binary | ios::in);
    if (!arq) {
        cerr << "Erro ao abrir o arquivo para leitura." << endl;
        return -1;
    }

    int contador = 0;

    while (arq.peek() != EOF) {  // Continuar enquanto houver dados no arquivo
        int tamanho;

        // Ler o tamanho do nome
        arq.read(reinterpret_cast<char*>(&tamanho), sizeof(tamanho));
        if (!arq) break;  // Se a leitura falhar, sair do loop
        
        // Pular a leitura do nome, mas avançar no arquivo
        arq.ignore(tamanho);  // Ignorar `tamanho` bytes no arquivo

        // Incrementar o contador para cada universidade lida
        contador++;
    }

    return contador;
}

// string Principal::parseValue(const string input, const string key){
//     // encontra pos da key
//     size_t posKey = input.find(key + ':');
//     if(posKey == string::npos){
//         return ""; // retorna string vazia se a chave nao for encontrada
//     }

//     //move a pos para depois dos dois de ":"
//     size_t posInicio = posKey + key.length() + 1;

//     // encontra a prox virgula apos a key
//     size_t posFim = input.find(',', posInicio);
//     if(posFim == string::npos){
//         posFim = input.length(); // se nao houver ',', vai ate o final da string
//     }

//     return input.substr(posInicio, posFim - posInicio);
// }

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

    uniVector.push_back(&utfpr);
    uniVector.push_back(&princeton);
    uniVector.push_back(&cambridge);
}

void Principal::listUniCad(){
    int index = 1;
    if(!uniVector.empty()){
        for(const auto uni : uniVector){
            cout << index << " - " << uni->getName() << endl;
            index++;
        }
    }else{
        cout << "Nenhuma Universidade cadastrada.\n" << endl;
    }
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