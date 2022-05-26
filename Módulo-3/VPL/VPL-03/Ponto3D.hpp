#ifndef PONTO_3D
#define PONTO_3D
#include "Ponto.hpp"
#include <vector>

// Implmenta um ponto tridimensional.
class Ponto3D : public Ponto{
    public:
        Ponto3D(double x, double y, double z);
        int dimensao() const override;
        double posicao(int k) const override;
        double distancia(Ponto* p) const override;
    private:
        std::vector<double> coordenadas;
   

};

#endif