/*
Se tiene una clase abstracta que representa una cuenta de banco genérica. Esta clase 
tiene los siguiente atributos y métodos: 
i. balance: el total de la cuenta (tipo double). 
ii. titularCuenta: nombre del dueño de la cuenta (string). 
iii. depositar(): deposita una cantidad de dinero en la cuenta. 
iv. retirar(): retira una cantidad de dinero de la cuenta (método virtual puro). 
v. mostrarInfo(): muestra la información de la cuenta (método virtual puro) que 
consta del balance, el tipo de cuenta y el nombre del titular. 
De esta clase se derivan dos subclases: 
CajaDeAhorro: 
• El método retirar() impide retirar más dinero del que existe en el balance. 
• Se realizará un descuento de $20 del balance luego de mostrar más de 2 veces 
la información de la cuenta. 
CuentaCorriente: 
• El método retirar() permite retirar dinero de la caja de ahorro si no existen 
suficientes fondos en este tipo de cuenta. 
• En caso de que la caja de ahorro tampoco tenga dinero, se imprimirá un aviso 
de que la cuenta no posee dinero. Utilizar friend para esto. 
Se pide: 
a. Establecer los especificadores de acceso (public, private y private) en los atributos y 
métodos de todas las clases, explicando su elección en función de la seguridad y la la 
flexibilidad para futuros requerimientos de cambio.  
b. Escriba el código para implementar todas clases. 
c. Escriba el código que permita probar los puntos mencionados para CajaDeAhorro y 
CuentaCorriente.

*/
#pragma once
#include <iostream>
#include <string>

using namespace std;

class Cuenta{
    protected:
    double balance;
    string titular;
    
    public:
    Cuenta(double balance, string titlar);
    void depositar(double cantidad);
    virtual void retirar(double cantidad) = 0;
    virtual void mostrarInfo() = 0;

    double getBalance();
    void setBalance(double newCantidad);

};

class CajaDeAhorro : public Cuenta{
    private:
    int contador;
    
    public:
    CajaDeAhorro(double balance_total, string titlar);
    void retirar(double cantidad) override;
    void mostrarInfo() override;
};

class CuentaCorriente : public Cuenta{
    private:
    CajaDeAhorro caja;
    
    public:
    CuentaCorriente(double balance_total, string titular, CajaDeAhorro caja);
    void depositar(double cantidad);
    void retirar(double cantidad) override;
    void mostrarInfo() override;
};

