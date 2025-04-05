#include "ej3.hpp"

using namespace std;

Numero::~Numero() {}

// Constructor de la clase Entero
Entero::Entero(int v) : valor(v) {}

Numero* Entero::suma(Numero* n) {
    Entero* otro = dynamic_cast<Entero*>(n); // Convierto n a Entero, si es posible
    if (otro) {
        return new Entero(valor + otro->valor); // Si la conversión es exitosa, realizo la suma
    }
    return nullptr;
}

Numero* Entero::resta(Numero* n) {
    Entero* otro = dynamic_cast<Entero*>(n);
    if (otro) {
        return new Entero(valor - otro->valor);
    }
    return nullptr;
}

Numero* Entero::multiplicacion(Numero* n) {
    Entero* otro = dynamic_cast<Entero*>(n);
    if (otro) {
        return new Entero(valor * otro->valor);
    }
    return nullptr;
}

string Entero::toString() {
    return to_string(valor); // Convierte el valor entero a string
}
Entero::~Entero() {}

// Constructor de la clase Real
Real::Real(double v) : valor(v) {}

Numero* Real::suma(Numero* n) {
    Real* otro = dynamic_cast<Real*>(n); // Convierto n a Real, si es posible
    if (otro) {
        return new Real(valor + otro->valor); // Si la conversión es exitosa, realizo la suma
    }
    return nullptr;
}

Numero* Real::resta(Numero* n) {
    Real* otro = dynamic_cast<Real*>(n);
    if (otro) {
        return new Real(valor - otro->valor);
    }
    return nullptr;
}

Numero* Real::multiplicacion(Numero* n) {
    Real* otro = dynamic_cast<Real*>(n);
    if (otro) {
        return new Real(valor * otro->valor);
    }
    return nullptr;
}

string Real::toString() {
    return to_string(valor);
}

Real::~Real() {}

// Constructor de la clase Complejo
Complejo::Complejo(double re, double im) : valor(re, im) {}

Numero* Complejo::suma(Numero* n) {
    Complejo* otro = dynamic_cast<Complejo*>(n); // Convierto n a Complejo, si es posible
    if (otro) {
        // Si la conversión es exitosa, realizo la suma
        // Se suman las partes reales e imaginarias por separado
        // y se crea un nuevo objeto Complejo con el resultado
        return new Complejo(valor.real() + otro->valor.real(), valor.imag() + otro->valor.imag()); 
    }
    return nullptr;
}
Numero* Complejo::resta(Numero* n) {
    Complejo* otro = dynamic_cast<Complejo*>(n);
    if (otro){
        return new Complejo(valor.real() - otro->valor.real(), valor.imag() - otro->valor.imag());
    }
    return nullptr;
}
Numero* Complejo::multiplicacion(Numero* n) {
    Complejo* otro = dynamic_cast<Complejo*>(n);
    if (otro) {
        // Se utiliza la fórmula (a + bi)(c + di) = (ac - bd) + (ad + bc)i
        // donde a y b son las partes reales e imaginarias del primer número
        // y c y d son las partes reales e imaginarias del segundo número
        return new Complejo(valor.real() * otro->valor.real() - valor.imag() * otro->valor.imag(),
                            valor.real() * otro->valor.imag() + valor.imag() * otro->valor.real());
    }
    return nullptr;
}
string Complejo::toString() {
    // Convierte el número complejo a string
    // Se utiliza la función to_string para convertir las partes real e imaginaria a string
    // y se concatenan con el símbolo '+' e 'i' para indicar la parte imaginaria.
    return to_string(valor.real()) + " + " + to_string(valor.imag()) + "i";
}
Complejo::~Complejo() {}


