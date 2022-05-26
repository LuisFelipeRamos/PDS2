#include "Cotacao.hpp"

Cotacao::Cotacao(){}

Cotacao::Cotacao(std::string data, double valor){
    this->_data = data;
    this->_valor = valor;
}

void Cotacao::set_data(std::string data){
    this->_data = data;
}

std::string Cotacao::get_data(){
    return this->_data;
}

void Cotacao::set_valor(double valor){
    this->_valor = valor;
}

double Cotacao::get_valor(){
    return this->_valor;
}