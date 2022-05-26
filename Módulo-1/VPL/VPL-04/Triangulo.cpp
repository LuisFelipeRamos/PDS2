#include "Triangulo.hpp"
#include "Ponto2D.hpp"
#include <cmath>

Triangulo::Triangulo(Ponto2D p1, Ponto2D p2, Ponto2D p3){
    this->p1 = p1;
    this->p2 = p2;
    this->p3 = p3;
}

double Triangulo::calcular_perimetro(){
    return p1.calcular_distancia(&p2) + p1.calcular_distancia(&p3) + p2.calcular_distancia(&p3);
}


double Triangulo::calcular_area(){ // Fórmula de Herão
    double s = calcular_perimetro() / 2; // semiperímetro
    double a = p1.calcular_distancia(&p2);
    double b = p1.calcular_distancia(&p3);
    double c = p2.calcular_distancia(&p3);
    return sqrt(s*(s - a)*(s - b)*(s - c));
}

int Triangulo::comparar_area(Triangulo *triangulo){
    if (calcular_area() < triangulo->calcular_area()){
        return -1;
    }
    else if (calcular_area() == triangulo->calcular_area()){
        return 0;
    }
    return 1;
}