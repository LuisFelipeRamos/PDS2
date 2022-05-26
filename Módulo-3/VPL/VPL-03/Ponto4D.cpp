#include "Ponto4D.hpp"
#include <cmath>

Ponto4D::Ponto4D(double x, double y, double z, double w){
    this->coordenadas.push_back(x);
    this->coordenadas.push_back(y);
    this->coordenadas.push_back(z);
    this->coordenadas.push_back(w);
}

int Ponto4D::dimensao() const{
    return this->coordenadas.size();
}

double Ponto4D::posicao(int k) const{
    return this->coordenadas.at(k - 1);
}

double Ponto4D::distancia(Ponto* p) const{
    double soma = 0;
    for (int i = 0; i < this->dimensao(); i++){
        soma += pow(this->posicao(i + 1) - p->posicao(i + 1), 2);
    }
    return sqrt(soma);
}