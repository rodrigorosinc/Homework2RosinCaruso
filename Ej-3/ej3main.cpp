#include "ej3.hpp"

using namespace std;


int main(){
    // Crear objetos de cada clase
    Entero e1(5), e2(3), e3(10), e4(2);
    Real r1(2.5), r2(1.5), r3(4.19238), r4(1.1233);
    Complejo c1(1.0, 2.0), c2(3.2, 4.0), c3(5.213, 6.0), c4(7.2, 8.63);
    // Realizar operaciones a Enteros
    Numero* resultado1 = e1.suma(&e2);
    Numero* resultado2 = e3.suma(&e4);
    Numero* resultado3 = e1.multiplicacion(&e2);
    Numero* resultado4 = e3.multiplicacion(&e4);
    Numero* resultado5 = e1.resta(&e2);
    Numero* resultado6 = e3.resta(&e4);
    if (resultado1 == nullptr || resultado2 == nullptr ||
        resultado3 == nullptr || resultado4 == nullptr ||
        resultado5 == nullptr || resultado6 == nullptr) {
        cout << "Error en alguna operación" << endl;
        return 1;
    }
    // Imprimir resultados
    cout << e1.toString() << " + " << e2.toString() << " = " << resultado1->toString() << endl;
    cout << e3.toString() << " + " << e4.toString() << " = " << resultado2->toString() << endl;
    cout << e1.toString() << " * " << e2.toString() << " = " << resultado3->toString() << endl;
    cout << e3.toString() << " * " << e4.toString() << " = " << resultado4->toString() << endl;
    cout << e1.toString() << " - " << e2.toString() << " = " << resultado5->toString() << endl;
    cout << e3.toString() << " - " << e4.toString() << " = " << resultado6->toString() << endl;
    cout << endl;
    // Liberar memoria
    delete resultado1;
    delete resultado2;
    delete resultado3;
    delete resultado4;
    delete resultado5;
    delete resultado6;
    // Realizar operaciones a Reales
    Numero* resultado7 = r1.suma(&r2);
    Numero* resultado8 = r3.suma(&r4);
    Numero* resultado9 = r1.multiplicacion(&r2);
    Numero* resultado10 = r3.multiplicacion(&r4);
    Numero* resultado11 = r1.resta(&r2);
    Numero* resultado12 = r3.resta(&r4);
    if (resultado7 == nullptr || resultado8 == nullptr ||
        resultado9 == nullptr || resultado10 == nullptr ||
        resultado11 == nullptr || resultado12 == nullptr) {
        cout << "Error en alguna operación" << endl;
        return 1;
    }
    // Imprimir resultados
    cout << r1.toString() << " + " << r2.toString() << " = " << resultado7->toString() << endl;
    cout << r3.toString() << " + " << r4.toString() << " = " << resultado8->toString() << endl;
    cout << r1.toString() << " * " << r2.toString() << " = " << resultado9->toString() << endl;
    cout << r3.toString() << " * " << r4.toString() << " = " << resultado10->toString() << endl;
    cout << r1.toString() << " - " << r2.toString() << " = " << resultado11->toString() << endl;
    cout << r3.toString() << " - " << r4.toString() << " = " << resultado12->toString() << endl;
    cout << endl;
    // Liberar memoria
    delete resultado7;
    delete resultado8;
    delete resultado9;
    delete resultado10;
    delete resultado11;
    delete resultado12;
    // Realizar operaciones a Complejos
    Numero* resultado13 = c1.suma(&c2);
    Numero* resultado14 = c3.suma(&c4);
    Numero* resultado15 = c1.multiplicacion(&c2);
    Numero* resultado16 = c3.multiplicacion(&c4);
    Numero* resultado17 = c1.resta(&c2);
    Numero* resultado18 = c3.resta(&c4);
    if (resultado13 == nullptr || resultado14 == nullptr ||
        resultado15 == nullptr || resultado16 == nullptr ||
        resultado17 == nullptr || resultado18 == nullptr) {
        cout << "Error en alguna operación" << endl;
        return 1;
    }
    // Imprimir resultados
    cout << c1.toString() << "  +  " << c2.toString() << " = " << resultado13->toString() << endl;
    cout << c3.toString() << "  +  " << c4.toString() << " = " << resultado14->toString() << endl;
    cout << c1.toString() << "  *  " << c2.toString() << " = " << resultado15->toString() << endl;
    cout << c3.toString() << "  *  " << c4.toString() << " = " << resultado16->toString() << endl;
    cout << c1.toString() << "  -  " << c2.toString() << " = " << resultado17->toString() << endl;
    cout << c3.toString() << "  -  " << c4.toString() << " = " << resultado18->toString() << endl;
    cout << endl;
    // Liberar memoria
    delete resultado13;
    delete resultado14;
    delete resultado15;
    delete resultado16;
    delete resultado17;
    delete resultado18;

    return 0;
}