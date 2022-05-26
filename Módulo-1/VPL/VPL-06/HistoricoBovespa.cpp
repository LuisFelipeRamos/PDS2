#include "HistoricoBovespa.hpp"
#include <vector>
#include <map>
#include <iostream>

HistoricoBovespa::HistoricoBovespa(){}

void HistoricoBovespa::inserir_cotacao(std::string sigla, std::string data, double valor){
    if (this->historico_de_cotacao.count(sigla) == 0){
        this->historico_de_cotacao.insert(std::pair<std::string, std::vector<Cotacao>>(sigla, {Cotacao(data,valor)}));
        return;
    }
    this->historico_de_cotacao.find(sigla)->second.push_back(Cotacao(data,valor));
}

double HistoricoBovespa::calcular_valor_medio_acao(std::string sigla){
    auto itr = this->historico_de_cotacao.find(sigla);
    double soma_valor = 0;
    int contador = 0;
    for (unsigned int i = 0; i < itr->second.size(); i++){
        soma_valor += itr->second.at(i).get_valor();
        contador++;
    }
    
    return soma_valor / contador;
}

Cotacao* HistoricoBovespa::recuperar_cotacao_maxima_acao(std::string sigla){
    if (this->historico_de_cotacao.count(sigla) == 0){
        return nullptr;
    }
    auto itr = this->historico_de_cotacao.find(sigla);
    Cotacao* max = &itr->second.at(0);
    for (unsigned int i = 1; i < itr->second.size(); i++){
        if (itr->second.at(i).get_valor() > max->get_valor()){
            max = &itr->second.at(i);
        }
    }
    return max;
}

Cotacao* HistoricoBovespa::recuperar_cotacao_minima_acao(std::string sigla){
    if (this->historico_de_cotacao.count(sigla) == 0){
        return nullptr;
    }
    auto itr = this->historico_de_cotacao.find(sigla);
    Cotacao* min = &itr->second.at(0);
    for (unsigned int i = 1; i < itr->second.size(); i++){
        if (itr->second.at(i).get_valor() < min->get_valor()){
            min = &itr->second.at(i);
        }
    }
    return min;
}

void HistoricoBovespa::imprimir_estatisticas_completas(){
    auto itr = this->historico_de_cotacao.begin();
    while (itr != this->historico_de_cotacao.end()){
        std::cout << itr->first << " ";
        for (unsigned int i = 0; i < itr->second.size(); i++){
            std::cout << itr->second.at(i).get_valor()<< " ";
        }
        std::cout << "|" << " ";
        std::cout << this->recuperar_cotacao_minima_acao(itr->first)->get_valor() << " ";
        std::cout << this->recuperar_cotacao_maxima_acao(itr->first)->get_valor() << " ";
        std::cout << this->calcular_valor_medio_acao(itr->first);
        itr++;
        std::cout << "\n";
    }
}