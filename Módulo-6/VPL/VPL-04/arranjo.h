#pragma once

#include <vector>
#include <cassert>
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
    std::vector<int> indicesInicializados_; // Índices do arranjo que já foram inicializados.
};

// IMPLEMENTAÇÃO DOS MÉTODOS DA CLASSE.

template <class Tipo> 
Arranjo<Tipo>::Arranjo(int inicio, int fim) : 
    inicio_(inicio), 
    fim_(fim) {
    assert(this->fim_ >= this->inicio_);
  elementos_.resize(fim - inicio + 1);
}

template <class Tipo> 
void Arranjo<Tipo>::atribuir(int i, Tipo valor) {
    assert(i <= this->fim_ && i >= this->inicio_);
    this->indicesInicializados_.push_back(i);
  int j = i - inicio_;
  elementos_[j] = valor;
}

template <class Tipo> 
Tipo Arranjo<Tipo>::valor(int i) const { 
    assert(std::find(this->indicesInicializados_.begin(), this->indicesInicializados_.end(), i) != this->indicesInicializados_.end());
    assert(i <= this->fim_ && i >= this->inicio_);
  int j = i - inicio_;     
  return elementos_[j];
}