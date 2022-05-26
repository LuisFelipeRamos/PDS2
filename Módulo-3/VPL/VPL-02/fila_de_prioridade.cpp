#include "fila_de_prioridade.h"
#include <iostream>
using std::cout;
using std::endl;

//Implementação da struct No

struct No{
    string _nome;
    int _idade;
    No* next;
    No();
    No(int idade, string nome);
};

No::No(){}

No::No(int idade, string nome){
    this->_nome = nome;
    this->_idade = idade;
    this->next = nullptr;
}

// Construtor
FilaDePrioridade::FilaDePrioridade(){
    this->tamanho_ = 0;
    this->primeiro_ = nullptr;
}

//primeiro -> elemento de maior prioridade

string FilaDePrioridade::primeiro() const{
  
        No* aux = this->primeiro_;
        No* max = this->primeiro_;
        while (aux){
            if (aux->_idade > max->_idade){
                max = aux;
            }
            aux = aux->next;
        }
        return max->_nome;

}

//tamanho -> número de elementos na lista

int FilaDePrioridade::tamanho() const{
    return this->tamanho_;
}

// Método auxiliar -> Maior Prioridade -> Retorna o ponteiro para a maior prioridade
No* FilaDePrioridade::MaiorPrioridade(){
    if (!this->vazia()){
        No* aux = this->primeiro_;
        No* max = this->primeiro_;
        while (aux){
            if (aux->_idade > max->_idade){
                max = aux;
            }
            aux = aux->next;
        }
        return max;
    }
    return nullptr;
}

// vazia -> testa se a lista está vazia 

bool FilaDePrioridade::vazia() const{
    if (this->primeiro_ == nullptr){
        return true;
    }
    return false;
}

// RemoverPrimeiro -> remove elemento de maior prioridade 

void FilaDePrioridade::RemoverPrimeiro(){
        No* garbage;
        No* current = this->primeiro_;
        if (this->primeiro_ != this->MaiorPrioridade()){
            while (current->next != this->MaiorPrioridade()){
                current = current->next;
            }
            garbage = current->next;
            current->next = current->next->next;
            delete garbage;
            this->tamanho_--;
            return;
        }
        garbage = this->primeiro_;
        this->primeiro_ =  this->primeiro_->next;
        delete garbage;
        this->tamanho_--;
        return;
}

// inserir -> insere elemento com nome s e prioridade p

void FilaDePrioridade::Inserir(int p, string s){
    No* novoElemento = new No(p, s);
    if (this->vazia()){
        this->primeiro_ = novoElemento;
        this->tamanho_++;
        return;
    }
    No* aux = this->primeiro_;
    while (aux->next){
        aux = aux->next;
    }
    aux->next = novoElemento;
    this->tamanho_++;
}

// limpar -> remove todos os elementos da fila

void FilaDePrioridade::Limpar(){
    No* aux = this->primeiro_;
    No* ref;
    while (aux){
        ref = aux;
        aux = aux->next;
        delete ref;
    }
}

/* void FilaDePrioridade::imprimirLista(){ -> imprime a lista encadeada para visualização
    No* aux = this->primeiro_;
    while (aux){
        cout << aux->_nome << "->";
        aux = aux->next;
    }
} */