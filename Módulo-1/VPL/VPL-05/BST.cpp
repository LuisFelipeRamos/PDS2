#include "Aluno.hpp"
#include "BST.hpp"
#include <string>

BST::BST(){
}


BST::NodeT* BST::criar_node(int matricula, std::string nome){
    NodeT* aux = new NodeT;
    aux->aluno.matricula = matricula;
    aux->aluno.nome = nome;
    aux->esq = nullptr;
    aux->dir = nullptr;
    return aux;
}

void BST::insertStudentHelper(NodeT* node, int matricula, std::string nome){
    if (matricula < node->aluno.matricula){
        if (node->esq == nullptr){
            node->esq = criar_node(matricula, nome);
        }
        else{
            insertStudentHelper(node->esq, matricula, nome);
        }
    }
    else if (matricula > node->aluno.matricula){
        if (node->dir == nullptr){
            node->dir = criar_node(matricula, nome);
        }
        else{
            insertStudentHelper(node->dir, matricula, nome);
        }
    }
}

void BST::inserir_aluno(Aluno aluno){ // matricula == chave
    if (this->root != nullptr){
        insertStudentHelper(this->root, aluno.matricula, aluno.nome);
    }
    else{
        this->root = criar_node(aluno.matricula, aluno.nome);
    }
}

Aluno* BST::procurar_aluno(int matricula){
    if (this->root != nullptr){
        if (this->root->aluno.matricula == matricula){
            return &this->root->aluno;
        }
        else{
            return searchStudentHelper(this->root, matricula);
        }
    }
    return nullptr;
}

Aluno* BST::searchStudentHelper(NodeT* node, int matricula){
    if (matricula < node->aluno.matricula){
        if (node->esq == nullptr){
            return nullptr;
        }
        return searchStudentHelper(node->esq, matricula);
    }
    else if (matricula > node->aluno.matricula){
        if (node->dir == nullptr){
            return nullptr;
        }
        return searchStudentHelper(node->dir, matricula);
    }
    return &node->aluno;   
}

void BST::inorder(NodeT* node){
    if (node == nullptr){
        return;
    }
    inorder(node->esq);
    node->aluno.imprimir_dados();
    inorder(node->dir);
}

void BST::imprimir_arvore(){
    inorder(this->root);
}