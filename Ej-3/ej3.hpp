/*
Escriba una interfaz llamada “Numero” que indique la implementación de las 
operaciones suma, resta y multiplicación de números (si desea, puede también agregar 
la división), así como también un método denominado “toString” que muestra el 
número en formato string.  
a. De esta interfaz, se deben implementar las siguientes tres clases: 
• Clase “Entero”, 
• Clase “Real”, 
• Clase “Complejo” 
b. Verifique el funcionamiento de cada uno de estas clases mediante la 
implementación de cada una de las operaciones con los números que desee e 
imprima el resultado utilizando el método “toString”.  
*/

#pragma once
#include <iostream>
#include <string>
#include <complex>
#include <vector>

using namespace std;   

class Numero {
public:
    virtual Numero* suma(Numero* n) = 0;
    virtual Numero* resta(Numero* n) = 0;
    virtual Numero* multiplicacion(Numero* n) = 0;
    virtual string toString() = 0;
    virtual ~Numero() = 0;
};
// Clase Entero
class Entero : public Numero {
    private:
        int valor;
    public:
        Entero(int v);
        Numero* suma(Numero* n) override;
        Numero* resta(Numero* n) override;
        Numero* multiplicacion(Numero* n) override;
        string toString() override;
        ~Entero();
};

// Clase Real
class Real : public Numero {
    private:
        double valor;
    public:
        Real(double v);
        Numero* suma(Numero* n) override;
        Numero* resta(Numero* n) override;
        Numero* multiplicacion(Numero* n) override;
        string toString() override;
        ~Real();
};
// Clase Complejo
class Complejo : public Numero {
    private:
        complex<double> valor;
    public:
        Complejo(double re, double im);
        Numero* suma(Numero* n) override;
        Numero* resta(Numero* n) override;
        Numero* multiplicacion(Numero* n) override;
        string toString() override;
        ~Complejo();
};