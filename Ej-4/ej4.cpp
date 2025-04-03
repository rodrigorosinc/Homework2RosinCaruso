#include "ej4.hpp"

using namespace std;

Cuenta::Cuenta(double balance_total, string titlar) : balance(balance), titular(titlar) {}
void Cuenta::depositar(double cantidad) {
    balance += cantidad;
}
double Cuenta::getBalance(){return balance;}
void Cuenta::setBalance(double newCantidad){
    balance = newCantidad;
}
void Cuenta::mostrarInfo(){
    cout << "El titular de esta cuenta es: " << titular << endl;
    cout << "El balance total es: " << balance << endl;
}

CajaDeAhorro::CajaDeAhorro(double balance_total, string titlar) : Cuenta(balance_total, titlar), contador(0) {}
void CajaDeAhorro::retirar(double cantidad){
    if (cantidad < 0){
        cout << "La cantidad es negativa, no se puede retirar el dinero solicitado." << endl;
        return;
    }
    auto newBalance = balance - cantidad;
    if (newBalance <= 0){
        cout << "No se puede retirar el dinero solicitado." << endl;
    } else {
        setBalance(newBalance);
        cout << "El nuevo balance fue ajustado. El mismo es: " << newBalance << endl;
    }
    return;
}

void CajaDeAhorro::mostrarInfo(){
    if (contador > 2){ 
        cout << "Se descontaron $20 por haber preguntado 2 o más veces." << endl;
        balance - 20;
    }
    cout << "El tipo de cuenta es: Caja de ahorro." << endl;
    cout << "El titular de la cuenta es: " << titular << endl;
    cout << "Su balance es: " << balance << endl;
    contador++;
}

CuentaCorriente::CuentaCorriente(double balance_total, string titular, CajaDeAhorro caja)
    : Cuenta(balance_total, titular), caja(caja) {}

void CuentaCorriente::depositar(double cantidad){
    caja.depositar(cantidad);
    cout << "Se depositó " << cantidad << " en la cuenta de ahorro." << endl;
}
void CuentaCorriente::retirar(double cantidad){
    if (cantidad < 0){
        cout << "La cantidad es negativa, no se puede retirar el dinero solicitado." << endl;
        return;
    }
    auto newBalance = balance - cantidad;

}

