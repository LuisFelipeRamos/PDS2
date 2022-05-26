#pragma once

#include <cassert>
#include <vector>
#include <algorithm>

// Define um arranjo de qualquer Tipo cujos índices variam em
// qualquer intervalo, inclusive negativos.
template <class Tipo> 
class Arranjo {
  public:
    // Cria um arranjo cujos índices variam de 'inicio' até 'fim'.
    // PRECONDIÇÃO: fim >= inicio.
    Arranjo(int inicio, int fim);

    // Altera o valor do índice i.
    // PRECONDIÇÃO: i está dentro do intervalo de índices do vetor.
    void atribuir(int i, Tipo valor);

    // Retorna o valor do índice i.
    // PRECONDIÇÕES: 
    // (1) i está dentro do intervalo de índices do vetor.
    // (2) i foi inicializando anteriormente.
    Tipo valor(int i) const; 
  
  private:
    int inicio_;  // Primeiro índice válido do arranjo.
    int fim_;  // Último índice válido do arranjo.
    std::vector<Tipo> elementos_;  // Elementos do arranjo.
    std::vector<Tipo> indiciesInicializados_; // Índices do arranjo que já foram inicializados
};

// DEFINIÇÃO DAS CLASSES DE EXCEÇÃO.

struct ExcecaoIntervaloVazio {
    ExcecaoIntervaloVazio(int inicio, int fim){
        this->inicio = inicio;
        this->fim = fim;
    }
    int inicio;
    int fim;
};

struct ExcecaoIndiceInvalido {
  ExcecaoIndiceInvalido(int inicio, int fim, int indice){
      this->inicio = inicio;
      this->fim = fim;
      this->indice = indice;
  }
  int inicio;
  int fim;
  int indice;
};

struct ExcecaoIndiceNaoInicializado {
  ExcecaoIndiceNaoInicializado(int indice){
      this->indice = indice;
  }
  int indice;
};

// IMPLEMENTAÇÃO DOS MÉTODOS DA CLASSE.

template <class Tipo> 
Arranjo<Tipo>::Arranjo(int inicio, int fim) : 
    inicio_(inicio), 
    fim_(fim) {
    if (this->fim_ < this->inicio_){
        throw ExcecaoIntervaloVazio(this->inicio_, this->fim_);
    }
  elementos_.resize(fim - inicio + 1);
}

template <class Tipo> 
void Arranjo<Tipo>::atribuir(int i, Tipo valor) {
  int j = i - inicio_;
  if (i < this->inicio_ || i > this->fim_){
        throw ExcecaoIndiceInvalido(this->inicio_, this->fim_, i);
    }
  elementos_[j] = valor;
  this->indiciesInicializados_.push_back(i);
}

template <class Tipo> 
Tipo Arranjo<Tipo>::valor(int i) const { 
  int j = i - inicio_;   
  if (i < this->inicio_ || i > this->fim_){
        throw ExcecaoIndiceInvalido(this->inicio_, this->fim_, i);
    }
   if (std::find(this->indiciesInicializados_.begin(), this->indiciesInicializados_.end(), i) == this->indiciesInicializados_.end()){
        throw ExcecaoIndiceNaoInicializado(i);
    }  
  return elementos_[j];
}