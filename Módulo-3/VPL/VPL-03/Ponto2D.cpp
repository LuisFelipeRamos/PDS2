#include "Ponto2D.hpp"
#include <cmath>

Ponto2D::Ponto2D(double x, double y){
    this->coordenadas.push_back(x);
    this->coordenadas.push_back(y);
}

int Ponto2D::dimensao() const{
    return this->coordenadas.size();
}

double Ponto2D::posicao(int k) const{
    return this->coordenadas.at(k - 1);
}

double Ponto2D::distancia(Ponto* p) const{
    double soma = 0;
    for (int i = 0; i < this->dimensao(); i++){
        soma += pow(this->posicao(i + 1) - p->posicao(i + 1), 2);
    }
    return sqrt(soma);
}
