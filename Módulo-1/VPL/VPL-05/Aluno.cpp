#include <iostream>
#include "Aluno.hpp"
#include <string>

Aluno::Aluno(){}

Aluno::Aluno(int matricula, std::string nome){
    this->matricula = matricula;
    this->nome = nome;
}

int Aluno::get_matricula(){
    return matricula;;
}

std::string Aluno::get_nome(){
    return nome;
}

void Aluno::set_matricula(int matricula){
    this->matricula = matricula;
}

void Aluno::set_nome(std::string nome){
    this->nome = nome;
}

void Aluno::imprimir_dados(){
    std::cout << this->matricula << " " << this->nome << std::endl;
}
