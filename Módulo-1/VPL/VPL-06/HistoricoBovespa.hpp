#ifndef HISTORICOBOVESPA_H
#define HISTORICOBOVESPA_H
#include "Cotacao.hpp"
#include <map>
#include <vector>

struct HistoricoBovespa{
    std::map<std::string, std::vector<Cotacao>> historico_de_cotacao;
    HistoricoBovespa();
    void inserir_cotacao(std::string sigla, std::string data, double valor);
    double calcular_valor_medio_acao(std::string sigla);
    Cotacao* recuperar_cotacao_maxima_acao(std::string sigla);
    Cotacao* recuperar_cotacao_minima_acao(std::string sigla);
    void imprimir_estatisticas_completas();
};


#endif