#include "ej4.hpp"

using namespace std;
// Clase Cuenta:
// Constructor
Cuenta::Cuenta(double balance, string titlar) : balance(balance), titular(titlar) {}
// Métodos
void Cuenta::depositar(double cantidad) {
    if (cantidad > 0){
        balance += cantidad;
    }
    else {
        cout << "La cantidad es negativa, no se puede depositar el dinero solicitado." << endl;
    }
}
// getters y setters
double Cuenta::getBalance(){return balance;}
void Cuenta::setBalance(double newCantidad){
    balance = newCantidad;
}


// Clase CajaDeAhorro:
// Constructor
CajaDeAhorro::CajaDeAhorro(double balance_total, string titlar) : Cuenta(balance_total, titlar), contador(0) {}
// Métodos
void CajaDeAhorro::retirar(double cantidad){
    if (cantidad < 0){
        cout << "La cantidad es negativa, no se puede retirar el dinero solicitado." << endl;
        return;
    }
    auto newBalance = balance - cantidad;
    if (newBalance < 0){
        cout << "No se puede retirar el dinero solicitado." << endl;
    } else {
        balance = newBalance;
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

// Clase CuentaCorriente:
// Constructor
CuentaCorriente::CuentaCorriente(double balance_total, string titular, shared_ptr<CajaDeAhorro> caja)
: Cuenta(balance_total, titular), caja(caja) {}

// Métodos
void CuentaCorriente::retirar(double cantidad) {
    if (balance >= cantidad) {
        balance -= cantidad;
        cout << "Retiro exitoso desde la cuenta corriente." << endl;
    } else if (caja->balance >= cantidad) {  // Accedemos directamente gracias a friend
        caja->balance -= cantidad;
        cout << "Retiro exitoso desde la caja de ahorro." << endl;
    } else {
        cout << "Fondos insuficientes en ambas cuentas." << endl;
    }
}
void CuentaCorriente::mostrarInfo(){
    cout << "El tipo de cuenta es: Cuenta Corriente." << endl;
    cout << "El titular de la cuenta es: " << titular << endl;
    cout << "Su balance es: " << balance << endl;
}

