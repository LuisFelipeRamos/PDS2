// g++ main.cpp Ponto2D.cpp Ponto3D.cpp Ponto4D.cpp -o main
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

#include "Ponto.hpp"
#include "Ponto2D.hpp"
#include "Ponto3D.hpp"
#include "Ponto4D.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::ios;
using std::string;
using std::vector;

// Converte uma string em um Ponto, e retorna um ponteiro para este ponto.
// OBS: O Ponto é a locado dinamicamente,
// e a responsabilidade da desalocação é de quem chama a função.
// PRECONDIÇÃO: 'line' representa um ponto de 2, 3, ou 4 dimensões.
Ponto* Converter(std::string line) {
  std::istringstream ss(line);
  std::string token;
  std::getline(ss, token, ' ');
  double x = stod(token);
  std::getline(ss, token, ' '); 
  double y = stod(token);
  if (!std::getline(ss, token, ' ')) {
     return new Ponto2D(x, y);
  } else {
    double z = stod(token);
    if (!std::getline(ss, token, ' ')) {
      return new Ponto3D(x, y, z);
    } else {
      double w = stod(token);
	  return new Ponto4D(x, y, z, w);
	}
  }
}

int main() {
  // lê os pontos e armazena-os em um vetor.
  vector<Ponto*> pontos;
  string line;
  while (std::getline(cin, line)) {
    pontos.push_back(Converter(line));
  }
  
  // Imprime as distâncias entre todos os pontos de mesma dimensão.
  cout.precision(2);
  cout.setf(ios::fixed);
  for (auto v1 : pontos) {
    for (auto v2 : pontos) {
	  if(v1->dimensao() == v2->dimensao() && v1 != v2){
	    cout  << std::setprecision(2) << v1->distancia(v2) << " ";
	  }
	}
    cout << endl;
  }

  // Desaloca a memória de cada ponto no vetor 'pontos'.
  for (auto ptr : pontos) {
    delete ptr;
  }
  return 0;
}