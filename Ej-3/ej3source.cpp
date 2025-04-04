#include "ej3.hpp"

using namespace std;

Numero::~Numero() {}

// Constructor de la clase Entero
Entero::Entero(int v) : valor(v) {}

Numero* Entero::suma(Numero* n) {
    Entero* otro = dynamic_cast<Entero*>(n);
    if (otro)
        return new Entero(valor + otro->valor);
    return nullptr;
}

Numero* Entero::resta(Numero* n) {
    Entero* otro = dynamic_cast<Entero*>(n);
    if (otro)
        return new Entero(valor - otro->valor);
    return nullptr;
}

Numero* Entero::multiplicacion(Numero* n) {
    Entero* otro = dynamic_cast<Entero*>(n);
    if (otro)
        return new Entero(valor * otro->valor);
    return nullptr;
}

string Entero::toString() {
    return to_string(valor);
}
Entero::~Entero() {}

// Constructor de la clase Real
Real::Real(double v) : valor(v) {}

Numero* Real::suma(Numero* n) {
    Real* otro = dynamic_cast<Real*>(n);
    if (otro)
        return new Real(valor + otro->valor);
    return nullptr;
}

Numero* Real::resta(Numero* n) {
    Real* otro = dynamic_cast<Real*>(n);
    if (otro)
        return new Real(valor - otro->valor);
    return nullptr;
}

Numero* Real::multiplicacion(Numero* n) {
    Real* otro = dynamic_cast<Real*>(n);
    if (otro)
        return new Real(valor * otro->valor);
    return nullptr;
}

string Real::toString() {
    return to_string(valor);
}

Real::~Real() {}

// Constructor de la clase Complejo
Complejo::Complejo(double re, double im) : valor(re, im) {}

Numero* Complejo::suma(Numero* n) {
    Complejo* otro = dynamic_cast<Complejo*>(n);
    if (otro)
        return new Complejo(valor.real() + otro->valor.real(), valor.imag() + otro->valor.imag());
    return nullptr;
}
Numero* Complejo::resta(Numero* n) {
    Complejo* otro = dynamic_cast<Complejo*>(n);
    if (otro)
        return new Complejo(valor.real() - otro->valor.real(), valor.imag() - otro->valor.imag());
    return nullptr;
}
Numero* Complejo::multiplicacion(Numero* n) {
    Complejo* otro = dynamic_cast<Complejo*>(n);
    if (otro)
        return new Complejo(valor.real() * otro->valor.real() - valor.imag() * otro->valor.imag(),
                            valor.real() * otro->valor.imag() + valor.imag() * otro->valor.real());
    return nullptr;
}
string Complejo::toString() {
    return to_string(valor.real()) + " + " + to_string(valor.imag()) + "i";
}
Complejo::~Complejo() {}


