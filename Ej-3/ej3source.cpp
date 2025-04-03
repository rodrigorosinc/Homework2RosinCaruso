#include "ej3.hpp"

using namespace std;

// Costructores
Entero::Entero(int valor) : valor(valor) {}
Entero::Entero(double realValor) : valor(static_cast<int>(realValor)) {}
Entero::Entero(complex<double> complexValor) : valor(static_cast<int>(complexValor.real())) {}

void Entero::setValor(int valor) {this->valor = valor;}
int Entero::getValor() {return valor;}

Real::Real(double valor) : valor(valor) {}
Real::Real(int enteroValor) : valor(static_cast<double>(enteroValor)) {}
Real::Real(complex<double> complexValor) : valor(static_cast<double>(complexValor.real())) {}

Complejo::Complejo(double real, double imaginario) : valor(real, imaginario) {}
Complejo::Complejo(int entero, int imaginario) : valor(static_cast<double>(entero), static_cast<double>(imaginario)) {}
Complejo::Complejo(Entero enteroValor) : valor(static_cast<double>(enteroValor.getValor()), 0) {}

