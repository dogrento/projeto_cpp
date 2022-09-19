#ifndef _ELEMENTO_H_
#define _ELEMENTO_H_

/*os metodos se encontram no mesmo arquiv
    do .h e template se define inteiramente no.h
*/

template<class type>
class Elemento{
    private:
        Elemento<type>* pNext;
        Elemento<type>* pPrev;
        type* pInfo;
        char nome[150];

    public:
        Elemento();
        ~Elemento();

    void Set_next(Elemento<type>* next);
    Elemento<type>* Get_next();

    void Set_prev(Elemento<type>* prev);
    Elemento<type>* Get_prev();

    void Set_info(type* pInfo);
    type* Get_info();

    void Set_nome(char* n);
    char* Get_nome();

};

template<class type>
Elemento<type>::Elemento(){
    pNext = NULL;
    pPrev = NULL;
    pInfo = NULL;
}

template<class type>
Elemento<type>::Elemento(){
    pNext = NULL;
    pPrev = NULL;
    pInfo = NULL;
}

template<class type>
void Elemento<type>::Set_next(Elemento<type>* next){
    pNext = next;
}

template<class type>
Elemento<type>* Elemento<type>::Get_next(){
    return pNext;
}

template<class type>
void Elemento<type>::Set_prev(Elemento<type>* prev){
    pPrev = prev;
}

template<class type>
Elemento<type>* Elemento<type>::Get_prev(){
    return pPrev;
}

template<class type>
void Elemento<type>::Set_info(type* info){
    pInfo = info;
}

template<class type>
type* Elemento<type>::Get_info(){
    return pInfo;
}

template<class type>
void Elemento<type>::Set_nome(char* n){
    strcpy(nome,n)
}

template<class type>
char* Elemento<type>::Get_nome(){
    return nome;
}

#endif