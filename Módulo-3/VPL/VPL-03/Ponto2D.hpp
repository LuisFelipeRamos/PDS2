#ifndef PONTO_2D
#define PONTO_2D
#include "Ponto.hpp"

#include <vector>

// Implmenta um ponto bidimensional.
class Ponto2D : public Ponto{
    public:
        Ponto2D(double x, double y);
        int dimensao() const override;
        double posicao(int k) const override;
        double distancia(Ponto* p) const override;
    private:
        std::vector<double> coordenadas;
};

#endif