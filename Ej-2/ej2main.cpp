#include "ej2.hpp"

using namespace std;

// Función para imprimir los estudiantes
/*Como se mencionó anteriormente, un objeto de la clase Curso contendrá la lista 
de estudiantes del curso (el vector conteniendo objetos tipo estudiante). La 
clase Curso permite: 
i. Inscribir y desinscribir estudiantes al curso. 
ii. Ver si un estudiante se encuentra inscripto o no en el curso buscándolo por 
su legajo. 
iii. Indicar si el curso está completo o no, teniendo en cuenta que el curso tiene 
una capacidad de 20 alumnos. 
iv. Imprimir la lista de estudiantes en orden alfabético. Para ello, utilice el 
algoritmo std::sort() en <algorithm>, el cual requerirá sobreescribir el 
operador “<”, y sobreescriba el operador “<<” (del método y clase que 
correspondan) para presentar los datos por pantalla. */

void printMenu(){
    cout << "1. Inscribir estudiante" << endl;
    cout << "2. Desinscribir estudiante" << endl;
    cout << "3. Ver si un estudiante está inscripto" << endl;
    cout << "4. Ver si el curso está completo" << endl;
    cout << "5. Imprimir lista de estudiantes" << endl;
    cout << "6. Imprimir lista de estudiantes ordenada" << endl;
    cout << "7. Salir" << endl;
    cout << "Ingrese una opción: ";
}

enum MenuOptions {
    INSCRIBIR = 1,
    DESINSCRIBIR = 2,
    VER_INSCRIPCION = 3,
    CURSO_COMPLETO = 4,
    IMPRIMIR_LISTA = 5,
    IMPRIMIR_LISTA_ORDENADA = 6,
    SALIR = 7
};

void removeStudentFromCourse(Curso& curso, string name) {
    auto students = curso.getStudents();
    for (size_t i = 0; i < students.size(); i++) {
        if (students[i]->getName() == name) {
            curso.removeStudent(students[i]);
            cout << "Estudiante desinscripto." << endl;
            break;
        }
    }
}

void printIsInCourseLegajo(Curso& curso, int legajo) {
    if (curso.isInCourse(legajo)) {
        cout << "El estudiante está inscripto en el curso." << endl;
    } else {
        cout << "El estudiante no está inscripto en el curso." << endl;
    }
}

void printIsFull(Curso& curso) {
    if (curso.isFull() == true) {
        cout << "El curso está completo." << endl;
    } else {
        cout << "El curso no está completo." << endl;
    }
}

int main() {
    // Crear estudiantes
    cout << "Bienvenido al sistema de gestión de cursos." << endl;
    
    Curso curso1 = Curso("Gambeta");
    Curso curso2 = Curso("Defensa");
    Curso curso3 = Curso("Ataque");
    Curso curso4 = Curso("Tiros Libres");
    shared_ptr<Estudiante> e1 = make_shared<Estudiante>("Lionel Messi", 123);
    shared_ptr<Estudiante> e2 = make_shared<Estudiante>("Angel Di María", 456);
    shared_ptr<Estudiante> e3 = make_shared<Estudiante>("Cristian Romero", 789);
    shared_ptr<Estudiante> e4 = make_shared<Estudiante>("Emiliano Martinez", 101);
    shared_ptr<Estudiante> e5 = make_shared<Estudiante>("Enzo Fernandez", 102);
    shared_ptr<Estudiante> e6 = make_shared<Estudiante>("Lautaro Martinez", 103);
    shared_ptr<Estudiante> e7 = make_shared<Estudiante>("Rodrigo De Paul", 104);
    shared_ptr<Estudiante> e8 = make_shared<Estudiante>("Nicolás Otamendi", 105);
    shared_ptr<Estudiante> e9 = make_shared<Estudiante>("Gonzalo Montiel", 106);
    shared_ptr<Estudiante> e10 = make_shared<Estudiante>("Alexis Mac Allister", 107);
    curso1.addStudent(e1); curso1.addStudent(e2); curso1.addStudent(e3);
    curso1.addStudent(e4); curso1.addStudent(e5); curso1.addStudent(e6);
    curso2.addStudent(e7); curso2.addStudent(e8); curso2.addStudent(e9);
    curso2.addStudent(e10); curso2.addStudent(e1); curso2.addStudent(e2);
    curso2.addStudent(e3); 
    curso3.addStudent(e4); curso3.addStudent(e6); curso3.addStudent(e9);
    curso3.addStudent(e7); curso3.addStudent(e8);
    curso4.addStudent(e1); curso4.addStudent(e2); curso4.addStudent(e4); 
    cout << endl;
    cout << "Los siguientes cursos fueron creados y están disponibles: " << endl;
    cout << "+ Gambeta" << endl;
    cout << "+ Defensa" << endl;
    cout << "+ Ataque" << endl;
    cout << "+ Tiros Libres" << endl;
    cout << endl;
    
    bool error = true;
    while (error) {
        try {
            if (!error) {
                cout << "Se reinicia el proceso. Por favor ingrese los datos correctamente." <<endl;
            }
            printMenu();
            int option;
            cin >> option;
            if (option == INSCRIBIR) {
                cout << "Ingrese el nombre del estudiante: ";
                string name;
                cin.ignore();
                getline(cin, name);
                cout << "Ingrese el legajo del estudiante: ";
                int legajo;
                cin >> legajo;
                cout << "Ingrese el curso del estudiante a inscribir: ";
                string course;
                cin.ignore();
                getline(cin, course);
                shared_ptr<Estudiante> student = make_shared<Estudiante>(name, legajo);
                if (course == curso1.getName()) {
                    curso1.addStudent(student);
                } else if (course == curso2.getName()) {
                    curso2.addStudent(student);
                } else if (course == curso3.getName()) {
                    curso3.addStudent(student);
                } else if (course == curso4.getName()) {
                    curso4.addStudent(student);
                } else {
                    cout << "Curso no encontrado." << endl;
                    throw invalid_argument("Opción inválida. Intente nuevamente.");
                }
                cout << "Estudiante inscripto." << endl;
                cout << endl;
            } else if (option == DESINSCRIBIR) {
                cout << "Ingrese el curso del estudiante a desinscribir: ";
                string course;
                cin.ignore();
                getline(cin, course);
                cout << "Ingrese el nombre del estudiante a desinscribir: ";
                string name;
                cin.ignore();
                getline(cin, name);
                if (course == curso1.getName()) {
                    removeStudentFromCourse(curso1, name);
                } else if (course == curso2.getName()) {
                    removeStudentFromCourse(curso2, name);
                } else if (course == curso3.getName()) {
                    removeStudentFromCourse(curso3, name);
                } else if (course == curso4.getName()) {
                    removeStudentFromCourse(curso4, name);
                } else {
                    cout << "Curso no encontrado." << endl;
                    throw invalid_argument("Opción inválida. Intente nuevamente.");
                }
                cout << "Estudiante desinscripto." << endl;
                cout << endl;             
            } else if (option == VER_INSCRIPCION) {
                cout << "Ingrese el curso del estudiante a verificar: ";
                string course;
                cin.ignore();
                getline(cin, course);
                cout << "Ingrese el legajo del estudiante a verificar: ";
                int legajo;
                cin >> legajo;
                if (course == curso1.getName()) {
                    printIsInCourseLegajo(curso1, legajo);
                } else if (course == curso2.getName()) {
                    printIsInCourseLegajo(curso2, legajo);
                } else if (course == curso3.getName()) {
                    printIsInCourseLegajo(curso3, legajo);
                } else if (course == curso4.getName()) {
                    printIsInCourseLegajo(curso4, legajo);
                } else {
                    cout << "Curso no encontrado." << endl;
                    throw invalid_argument("Opción inválida. Intente nuevamente.");
                }
                cout << endl;
            } else if (option == CURSO_COMPLETO) {
                cout << "Ingrese el nombre del curso: ";
                string course;
                cin.ignore();
                getline(cin, course);
                if (course == curso1.getName()) {
                    printIsFull(curso1);
                } else if (course == curso2.getName()) {
                    printIsFull(curso2);
                } else if (course == curso3.getName()) {
                    printIsFull(curso3);
                } else if (course == curso4.getName()) {
                    printIsFull(curso4);
                } else {
                    cout << "Curso no encontrado." << endl;
                    throw invalid_argument("Opción inválida. Intente nuevamente.");
                }
                cout << endl;
            } else if (option == IMPRIMIR_LISTA) {
                cout << "Ingrese el nombre del curso: ";
                string course;
                cin.ignore();
                getline(cin, course);
                cout << endl;
                if (course == curso1.getName()) {
                    cout << "Lista de estudiantes: " << endl;
                    curso1.printStudents();
                } else if (course == curso2.getName()) {
                    cout << "Lista de estudiantes: " << endl;
                    curso2.printStudents();
                } else if (course == curso3.getName()) {
                    cout << "Lista de estudiantes: " << endl;
                    curso3.printStudents();
                } else if (course == curso4.getName()) {
                    cout << "Lista de estudiantes: " << endl;
                    curso4.printStudents();
                } else {
                    cout << "Curso no encontrado." << endl;
                    throw invalid_argument("Opción inválida. Intente nuevamente.");
                }
                cout << endl;
            } else if (option == IMPRIMIR_LISTA_ORDENADA) {
                cout << "Ingrese el nombre del curso: ";
                string course;
                cin.ignore();
                getline(cin, course);
                cout << endl;

                if (course == curso1.getName()) {
                    cout << "Lista de estudiantes ordenada: " << endl;
                    curso1.printStudentsOrdered();
                } else if (course == curso2.getName()) {
                    cout << "Lista de estudiantes ordenada: " << endl;
                    curso2.printStudentsOrdered();
                } else if (course == curso3.getName()) {
                    cout << "Lista de estudiantes ordenada: " << endl;
                    curso3.printStudentsOrdered();
                } else if (course == curso4.getName()) {
                    cout << "Lista de estudiantes ordenada: " << endl;
                    curso4.printStudentsOrdered();
                } else {
                    cout << "Curso no encontrado." << endl;
                    throw invalid_argument("Opción inválida. Intente nuevamente.");
                }
                cout << endl;
            } else if (option == SALIR) {
                cout << "Saliendo del programa." << endl;
                return 0;
            } else {
                throw invalid_argument("Opción inválida. Intente nuevamente.");
            }

        } catch (const exception& e) {
            error = true;
            cout << "Error: " << e.what() << endl;
            cout << "Por favor, intente nuevamente." << endl;
        }
    }
    
    
}