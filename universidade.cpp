#include "universidade.h"

Universidade::Universidade():
ID(-1),
uniName("")
{
    // for(int i = 0; i < 50; i++){
    //     dptoP[i] = nullptr;
    // }
}

Universidade::~Universidade(){}

void Universidade::informaDptoList(){
    // for(int i = 0; i < 50; i++){
    //     if(dptoP[i] != nullptr){
    //         dptoP[i]->informaDpto();
    //     }
    // }
    if(!dptoList.isEmpty()){
        dptoList.showDptoList();
    }else{
        cerr << "Lista de departamento esta vazia!" << endl;
    }
}

void Universidade::salvaUni(ofstream& f){
    int nameTamanho = this->getName().size();
    int id = this->getID();
    cout << "Salvando: " << this->getName() << endl;
    f.write((char*) &nameTamanho, sizeof(nameTamanho));
    f.write((char*) &this->getName()[0], nameTamanho);
    f.write((char*) &id, sizeof(id));
}

Universidade* Universidade::recuperaUni(ifstream& f){
    int tamanho;
    int id;
    
    // Ler o tamanho do nome
    f.read(reinterpret_cast<char*>(&tamanho), sizeof(tamanho));
    // if (!f) break;  // Sair do loop caso a leitura falhe
    
    // Ler o nome da universidade com o tamanho específico
    std::string nome(tamanho, '\0');  // Inicializar a string com o tamanho necessário
    f.read(&nome[0], tamanho);
    f.read((char*)&id, sizeof(id));

    Universidade* novaUni = new Universidade;
    novaUni->setName(nome);
    novaUni->setID(id);

    return novaUni;
    
    // if (!f) break;  // Sair do loop caso a leitura falhe
}