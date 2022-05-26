// NÃO ALTERE ESSA LINHA
#include "avaliacao_basica_bst.hpp"
#include <iostream>
#include "BST.hpp"
#include "Aluno.hpp"
#include <string>


int main() {
  
    // NÃO ALTERE ESSA LINHA
    avaliacao_basica();


    //
    // Adicione seu código aqui e faça as demais alterações necessárias
    //

    BST bst;
    int matricula;
    std::string nome;
    while (std::cin >> matricula >> nome){
        bst.inserir_aluno(Aluno(matricula, nome));
    }

    //
    // Ao final faça uma chamada para o método 'imprimir_arvore()'
    //

    bst.imprimir_arvore();

    return 0;
}