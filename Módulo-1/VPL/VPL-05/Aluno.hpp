#ifndef ALUNO_H
#define ALUNO_H
#include <string>

struct Aluno{
    int matricula;
    std::string nome;
    Aluno();
    Aluno(int matricula, std::string nome);
    int get_matricula();
    std::string get_nome();
    void set_matricula(int matricula);
    void set_nome(std::string nome);
    void imprimir_dados();
};

#endif