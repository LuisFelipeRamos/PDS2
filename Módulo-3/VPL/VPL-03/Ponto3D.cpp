#include "Ponto3D.hpp"
#include <cmath>

Ponto3D::Ponto3D(double x, double y, double z){
    this->coordenadas.push_back(x);
    this->coordenadas.push_back(y);
    this->coordenadas.push_back(z);
}

int Ponto3D::dimensao() const{
    return this->coordenadas.size();
}

double Ponto3D::posicao(int k) const{
    return this->coordenadas.at(k - 1);
}

double Ponto3D::distancia(Ponto* p) const{
    double soma = 0;
    for (int i = 0; i < this->dimensao(); i++){
        soma += pow(this->posicao(i + 1) - p->posicao(i + 1), 2);
    }
    return sqrt(soma);
}