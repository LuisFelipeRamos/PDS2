#ifndef PONTO_4D
#define PONTO_4D
#include "Ponto.hpp"
#include <vector>

// Implmenta um ponto quadridimensional.
class Ponto4D : public Ponto{
    public:
        Ponto4D(double x, double y, double z, double w);
        int dimensao() const override;
        double posicao(int k) const override;
        double distancia(Ponto* p) const override;
    private:
        std::vector<double> coordenadas;

};

#endif