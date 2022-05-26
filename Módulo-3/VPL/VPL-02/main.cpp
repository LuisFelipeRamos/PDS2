#include <iostream>
#include <string>
#include "fila_de_prioridade.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
  FilaDePrioridade fila;
  // Lê os dados e insere na fila de prioridade.
  string nome;
  int idade;
  while (cin >> nome >> idade) {
    fila.Inserir(idade, nome);
  }
  

  // Imprime os nomes em ordem de prioridade.
  while (!fila.vazia()) {

    /* fila.imprimirLista(); -> imprime a lista encadeada para visualização
    cout << endl; */

    cout << fila.primeiro() << endl;
    fila.RemoverPrimeiro();
  } 
  return 0;
}

// checar removerprimeiro,provavelmente erro esta la ja que esta imprimindo so o mais velho e acaba

