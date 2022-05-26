#include "ContadorDePalavras.hpp"
#include <iostream>

ContadorDePalavras::ContadorDePalavras(){
}

Palavra* ContadorDePalavras::criarPalavra(string s){
    Palavra* aux = new Palavra(s);
    return aux;
}

list<Palavra>::iterator ContadorDePalavras::isInList(string s){
    list<Palavra>::iterator itr;
    for (itr = this->_lista_de_palavras.begin(); itr != this->_lista_de_palavras.end(); itr++){
        if (itr->palavra() == s){
            return itr;
        }
    }
    return itr;
}

void ContadorDePalavras::Adicionar(string s){
    if (this->isInList(s) != this->_lista_de_palavras.end()){
        this->isInList(s)->Incrementar();
        return;
    }
    this->_lista_de_palavras.push_back(*this->criarPalavra(s));
}

void ContadorDePalavras::ImprimirOrdenado(){
    this->_lista_de_palavras.sort();
    for (auto itr = this->_lista_de_palavras.begin(); itr != this->_lista_de_palavras.end(); itr++){
        std::cout << itr->palavra() << " " << itr->ocorrencias() << std::endl;
    }
}