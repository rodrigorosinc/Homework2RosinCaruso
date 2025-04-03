#include "ej4.hpp"

using namespace std;

Cuenta::Cuenta(double balance, string titlar) : balance(balance), titular(titlar) {}

void Cuenta::depositar(double cantidad) {
    if (cantidad > 0){
        balance += cantidad;
    }
    else {
        cout << "La cantidad es negativa, no se puede depositar el dinero solicitado." << endl;
    }
}

double Cuenta::getBalance(){return balance;}
void Cuenta::setBalance(double newCantidad){
    balance = newCantidad;
}



CajaDeAhorro::CajaDeAhorro(double balance_total, string titlar) : Cuenta(balance_total, titlar), contador(0) {}

void CajaDeAhorro::retirar(double cantidad){
    if (cantidad < 0){
        cout << "La cantidad es negativa, no se puede retirar el dinero solicitado." << endl;
        return;
    }
    auto newBalance = getBalance() - cantidad;
    if (newBalance < 0){
        cout << "No se puede retirar el dinero solicitado." << endl;
    } else {
        setBalance(newBalance);
    }
    return;
}

void CajaDeAhorro::mostrarInfo(){
    cout << "El tipo de cuenta es: Caja de ahorro." << endl;
    cout << "El titular de la cuenta es: " << titular << endl;
    contador++;
    if (contador > 2){ 
        cout << "Se descontaron $20 por haber preguntado 2 o más veces." << endl;
        balance -= 20;
    }
    cout << "Su balance es: " << balance << endl;
}


CuentaCorriente::CuentaCorriente(double balance_total, string titular, shared_ptr<CajaDeAhorro> caja)
    : Cuenta(balance_total, titular), caja(caja) {}


void CuentaCorriente::retirar(double cantidad){
    if (balance >= cantidad) {
        balance -= cantidad;
    } else if (caja && caja->getBalance() >= cantidad) {
        caja->retirar(cantidad);
        cout << "Se retiró " << cantidad << " de la cuenta de ahorro. Nuevo balance de la caja de ahorro: " << caja->getBalance() << endl;
    } else {
        cout << "No se puede retirar el dinero solicitado. No hay fondos suficientes." << endl;
    }
    
}

void CuentaCorriente::mostrarInfo(){
    cout << "El tipo de cuenta es: Cuenta Corriente." << endl;
    cout << "El titular de la cuenta es: " << titular << endl;
    cout << "Su balance es: " << balance << endl;
}

