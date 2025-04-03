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

#ifndef EJ3_HPP
#define EJ3_HPP

#include <iostream>
#include <string>
#include <complex>

using namespace std;

class Numero {
public:
    virtual Numero* suma(Numero* n);
    virtual Numero* resta(Numero* n);
    virtual Numero* multiplicacion(Numero* n);
    virtual string toString();
    virtual ~Numero() {}
};

class Entero : public Numero {
    private:
        int valor;
    public:
        Entero(int valor);
        Entero(double realValor);
        Entero(complex<double> complexValor);
        Numero* suma(Numero* n) override;
        Numero* resta(Numero* n) override;
        Numero* multiplicacion(Numero* n) override;
        string toString() override;
        
        int getValor();
        void setValor(int valor);
        ~Entero() {}
};

class Real : public Numero {
    private:
        double valor;
    public:
        Real(double valor);
        Real(int enteroValor);
        Real(complex<double> complexValor);
        Numero* suma(Numero* n) override;
        Numero* resta(Numero* n) override;
        Numero* multiplicacion(Numero* n) override;
        string toString() override;
        
        double getValor();
        void setValor(double valor);
        
        ~Real() {}
};

class Complejo : public Numero {
    private:
        complex<double> valor;
    public:
        Complejo(double real, double imaginario);
        Complejo(int entero, int imaginario);
        Complejo(Entero enteroValor);

        Numero* suma(Numero* n) override;
        Numero* resta(Numero* n) override;
        Numero* multiplicacion(Numero* n) override;
        string toString() override;
        
        complex<double> getValor();
        void setValor(complex<double> valor);

        ~Complejo() {}
};














#endif