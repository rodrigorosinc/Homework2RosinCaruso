#include "ej4.hpp"

using namespace std;

int main() {
    cout << "Bienvenido al sistema de cuentas bancarias." << endl;
    cout << "Cree una cuenta de ahorro o una cuenta corriente." << endl;
    cout << "1. Crear cuenta de ahorro" << endl;
    cout << "2. Crear cuenta corriente" << endl;
    int option;
    cout << "Seleccione una opción: ";
    cin >> option;
    cout << endl;
    while (option < 1 || option > 2) {
        cout << endl;
        cout << "Opción inválida. Seleccione una opción válida: ";
        cin >> option;
        cout << endl;
    }
    if (option == 1) {
        // Crear una cuenta de ahorro
        double balance;
        string titular;
        cout << "Ingrese el nombre del titular de la cuenta: ";
        cin >> titular;
        cout << endl;
        cout << "Ingrese el balance inicial de la cuenta: ";
        cin >> balance;
        cout << endl;
        // Validar el balance
        while (balance < 0) {
            cout << "El balance inicial no puede ser negativo. Ingrese un balance válido: ";
            cout << endl;
            cin >> balance;
        }

        shared_ptr<CajaDeAhorro> cuenta = make_shared<CajaDeAhorro>(balance, titular); // Creo una cuenta de ahorro

        bool exit = false;
        while (!exit) {
            // Mostrar el menú de opciones
            cout << "Seleccione una opción:" << endl;
            cout << "1. Depositar dinero" << endl;
            cout << "2. Retirar dinero" << endl;
            cout << "3. Mostrar información de la cuenta" << endl;
            cout << "4. Salir" << endl;
            int action;
            cout << "Opción: ";
            cin >> action;
            cout << endl;
            switch (action) {
                case 1: {
                    double cantidad;
                    cout << "Ingrese la cantidad a depositar: ";
                    cin >> cantidad;
                    cuenta->depositar(cantidad);
                    cout << endl;   
                    break;
                }
                case 2: {
                    double cantidad;
                    cout << "Ingrese la cantidad a retirar: ";
                    cin >> cantidad;
                    cuenta->retirar(cantidad);
                    cout << endl;
                    break;
                }
                case 3:
                    cuenta->CajaDeAhorro::mostrarInfo();
                    cout << endl;
                    break;
                case 4:
                    exit = true;
                    break;
                default:
                    cout << "Opción inválida." << endl;
                    cout << endl;
            }
        }
    } else if (option == 2) {
        // Crear una cuenta corriente
        double balance, balanceAhorro;
        string titular;
        cout << "Ingrese el nombre del titular de la cuenta: ";
        cin >> titular;
        cout << endl;
        cout << "Ingrese el balance inicial de la cuenta: ";
        cin >> balance;
        cout << endl;
        // Validar el balance
        while (balance < 0) {
            cout << "El balance inicial no puede ser negativo. Ingrese un balance válido: ";
            cout << endl;
            cin >> balance;
        }
        cout << "Ingrese el balance inicial de la cuenta de ahorro: ";
        cin >> balanceAhorro;
        cout << endl;
        // Validar el balance de la cuenta de ahorro
        while (balanceAhorro < 0) {
            cout << "El balance inicial no puede ser negativo. Ingrese un balance válido: ";
            cin >> balanceAhorro;
            cout << endl;
        }
        // Crear la cuenta de ahorro y la cuenta corriente
        shared_ptr<CajaDeAhorro> cuentaAhorro = make_shared<CajaDeAhorro>(balanceAhorro, titular);
        shared_ptr<CuentaCorriente> cuentaCorriente = make_shared<CuentaCorriente>(balance, titular, cuentaAhorro);
        bool exit = false;
        while (!exit) {
            cout << "Seleccione una opción:" << endl;
            cout << "1. Depositar dinero" << endl;
            cout << "2. Retirar dinero" << endl;
            cout << "3. Mostrar información de la cuenta" << endl;
            cout << "4. Salir" << endl;
            int action;
            cout << "Opción: ";
            cin >> action;
            cout << endl;
            switch (action) {
                case 1: {
                    double cantidad;
                    cout << "Ingrese la cantidad a depositar: ";
                    cin >> cantidad;
                    cuentaCorriente->depositar(cantidad);
                    cout << endl;   
                    break;
                }
                case 2: {
                    double cantidad;
                    cout << "Ingrese la cantidad a retirar: ";
                    cin >> cantidad;
                    cuentaCorriente->retirar(cantidad);
                    cout << endl;
                    break;
                }
                case 3:
                    cuentaCorriente->mostrarInfo();
                    cout << endl;
                    break;
                case 4:
                    exit = true;
                    break;
                default:
                    cout << "Opción inválida." << endl;
                    cout << endl;
            }
        }
        
    }
    cout << "Gracias por usar el sistema de cuentas bancarias." << endl;
    return 0;
}