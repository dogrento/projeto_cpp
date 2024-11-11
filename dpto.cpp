#include "dpto.h"
#include "disc.h"

Dpto::Dpto(){
setID(-1);
setName("");
}

Dpto::~Dpto(){
}

void Dpto::informaDpto(){
    cout << "Departamento: " << getID() <<' '<< getName() << endl;
}

void Dpto::insertDisc(Disc* pD){
    cout << "Inserindo " <<
    pD->getName() << " a lista de " << this->getName()<<endl;
    discList.push_back(pD);
}

void Dpto::listDisc(){
    cout << "Departamento:  " << getName() << endl;

    for(const auto& disc : discList){ // const indica que var nao sera alterada na iteracao, auto tipagem automatica cpp11 &end elemento e colecao
        cout << "\n    " << disc->getName() << endl;
    }
}

void Dpto::salvaDpto(ofstream& f){
    size_t nameSize = this->getName().size();
    int id = this->getID();
    cout << "Salvando: " << this->getName() << endl;
    f.write((char*) &nameSize, sizeof(nameSize));
    f.write((char*) &this->getName()[0], nameSize);
    f.write((char*) &id, sizeof(id));
}

// void Universidade::salvaUni(ofstream& f){
//     int nameTamanho = this->getName().size();
//     int id = this->getID();
//     cout << "Salvando: " << this->getName() << endl;
//     f.write((char*) &nameTamanho, sizeof(nameTamanho));
//     f.write((char*) &this->getName()[0], nameTamanho);
//     f.write((char*) &id, sizeof(id));
// }

// Universidade* Universidade::recuperaUni(ifstream& f){
//     int tamanho;
//     int id;
    
//     // Ler o tamanho do nome
//     f.read(reinterpret_cast<char*>(&tamanho), sizeof(tamanho));
//     // if (!f) break;  // Sair do loop caso a leitura falhe
    
//     // Ler o nome da universidade com o tamanho específico
//     std::string nome(tamanho, '\0');  // Inicializar a string com o tamanho necessário
//     f.read(&nome[0], tamanho);
//     f.read((char*)&id, sizeof(id));

//     Universidade* novaUni = new Universidade;
//     novaUni->setName(nome);
//     novaUni->setID(id);

//     return novaUni;
    
//     // if (!f) break;  // Sair do loop caso a leitura falhe
// }