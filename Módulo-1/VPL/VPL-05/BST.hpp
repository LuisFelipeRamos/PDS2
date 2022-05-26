#ifndef BST_H
#define BST_H
#include "Aluno.hpp"
#include <string>

struct BST{
    struct NodeT {
        Aluno aluno;
        NodeT* esq;
        NodeT* dir;
    };
    NodeT* root = nullptr;
    BST();
    void inserir_aluno(Aluno aluno);
    void inorder(NodeT* node);
    void imprimir_arvore();
    void insertStudentHelper(NodeT* node, int matricula, std::string nome);
    NodeT* criar_node(int matricula, std::string nome);
    Aluno* procurar_aluno(int matricula);
    Aluno* searchStudentHelper(NodeT* node, int matricula);
};

#endif