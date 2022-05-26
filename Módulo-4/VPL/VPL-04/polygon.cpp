/**
 * Todas as tarefas deste exercicio devem ser feitas sobre esse arquivo.
 * Os metodos e operacoes marcados com a tag "TODO" devem ser editados.
 */

#include <iostream>
#include "polygon.h"
#include <algorithm>

// Essa função irá checar se um ponto está presente em um polígono

bool inPolygon(const Point& p, const Polygon& polygon){
    for (int i = 0; i < std::vector<Point>(polygon).size(); i++){
        if (p.contains(std::vector<Point>(polygon).at(i))){
            return true;
        }
    }
    return false;
}

std::ostream& operator << (std::ostream &out, const Polygon &poly) {
  for (const Point& p: poly.limits) {
    out << " " << p;
  }
  return out;
}

bool operator == (const Polygon &lhs, const Polygon &rhs) {
    std::vector<Point> plhs = std::vector<Point>(lhs);
    std::vector<Point> prhs = std::vector<Point>(rhs);
    if (plhs.size() != prhs.size()){return false;}
    for (int i = 0; i < plhs.size(); i++){
        if (!inPolygon(plhs.at(i), rhs)){
            return false;
        }
    }
    return true;
}

bool Point::contains(const Point& p) const {
  return p.x == this->x && p.y == this->y;
}

std::ostream& operator << (std::ostream &out, const Point &p) {
  out << "(" << p.x << ", " << p.y << ")";
  return out;
}

bool RightRectangle::contains(const Point& p) const {
    if (this->limits.size() == 1){
        return this->limits.at(0).contains(p);
    }
    Point P = this->limits.at(0);
    Point R = this->limits.at(1);
    
     return( (p.x <= std::max(P.x, R.x)) && (p.x >= std::min(P.x, R.x)) &&
            (p.y <= std::max(P.y, R.y)) && (p.y >= std::min(P.y, R.y)) );
}

Point::Point(int xx, int yy): x(xx), y(yy) {
    this->limits.push_back(*this);
}

RightRectangle::RightRectangle(int x0, int y0, int x1, int y1) {
    if (x0 == x1 && y0 == y1){
        this->limits.push_back(Point(x0, y0));
    }
    else{
        this->limits.push_back(Point(x0, y0));
        this->limits.push_back(Point(x1, y1));
        this->limits.push_back(Point(x0, y1));
        this->limits.push_back(Point(x1, y0));
    }
}