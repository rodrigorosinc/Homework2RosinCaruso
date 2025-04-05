#include "ej2.hpp"

using namespace std;

void printMenu(){
    cout << "           Menú de opciones" << endl;
    cout << "============================================" << endl;
    cout << "1. Inscribir estudiante" << endl;
    cout << "2. Desinscribir estudiante" << endl;
    cout << "3. Ver si un estudiante está inscripto" << endl;
    cout << "4. Ver si el curso está completo" << endl;
    cout << "5. Imprimir lista de estudiantes" << endl;
    cout << "6. Imprimir lista de estudiantes ordenada" << endl;
    cout << "7. Agregar curso" << endl;
    cout << "8. Ver cursos" << endl;
    cout << "9. Copiar curso" << endl;
    cout << "10. Salir" << endl;
    cout << "- Ingrese una opción: ";
}

enum MenuOptions {
    INSCRIBIR = 1,
    DESINSCRIBIR = 2,
    VER_INSCRIPCION = 3,
    CURSO_COMPLETO = 4,
    IMPRIMIR_LISTA = 5,
    IMPRIMIR_LISTA_ORDENADA = 6,
    AGREGAR_CURSO = 7,
    VER_CURSOS = 8,
    COPIAR_CURSO = 9,
    SALIR = 10
};

void removeStudentFromCourse(Curso& curso, string name) { // Funcion para desinscribir un estudiante
    auto students = curso.getStudents(); 
    if (students.empty()) {
        cout << "No hay estudiantes en el curso." << endl;
        return;
    }
    bool found = false;
    for (size_t i = 0; i < students.size(); i++) {
        if (students[i]->getName() == name) { // Busco el estudiante por nombre
            curso.removeStudent(students[i]); 
            cout << "Estudiante desinscripto." << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Estudiante no encontrado." << endl;
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
    cout << "===========================================" << endl;
    cout << "Bienvenido al sistema de gestión de cursos." << endl;
    cout << "===========================================" << endl;
    // Crear cursos
    vector<shared_ptr<Curso>> cursos;
    auto curso1 = make_shared<Curso>("Gambeta"); cursos.push_back(curso1);
    auto curso2 = make_shared<Curso>("Defensa"); cursos.push_back(curso2);
    auto curso3 = make_shared<Curso>("Ataque"); cursos.push_back(curso3);
    auto curso4 = make_shared<Curso>("Tiros Libres"); cursos.push_back(curso4);

    cout << "Los siguientes cursos fueron creados y están disponibles: " << endl;
    cout << "+" << curso1->getName() << endl;
    cout << "+" << curso2->getName() << endl;
    cout << "+" << curso3->getName() << endl;
    cout << "+" << curso4->getName() << endl;
    // Crear estudiantes
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
    // Agrego estudiantes a cada curso
    curso1->addStudent(e1); curso1->addStudent(e2); curso1->addStudent(e3);
    curso1->addStudent(e4); curso1->addStudent(e5); curso1->addStudent(e6);

    curso2->addStudent(e7); curso2->addStudent(e8); curso2->addStudent(e9);
    curso2->addStudent(e10); curso2->addStudent(e1); curso2->addStudent(e2);
    curso2->addStudent(e3);

    curso3->addStudent(e4); curso3->addStudent(e6); curso3->addStudent(e9);
    curso3->addStudent(e7); curso3->addStudent(e8);

    curso4->addStudent(e1); curso4->addStudent(e2); curso4->addStudent(e4);
    cout << endl;
    
    bool error = true;
    while (error) {
        try {
            if (!error) {
                cout << "Se reinicia el proceso. Por favor ingrese los datos correctamente." <<endl;
            }

            cout << "============================================" << endl;
            printMenu();
            int option;
            cin >> option;
            cout << "=============================================" << endl;
            
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
                bool found = false;
                for (size_t i = 0; i < cursos.size(); i++) { // Itero sobre los cursos
                    if (cursos[i]->getName() == course && !cursos[i]->isFull()) {
                        // Busco si el estudiante ya existe
                        for (size_t j = 0; j < cursos[i]->getStudents().size(); j++) { // Itero sobre los estudiantes
                            if (cursos[i]->getStudents()[j]->getLegajo() == legajo) {  // Si el estudiante ya existe, no lo inscribo
                                cout << "El estudiante ya está inscripto en el curso." << endl;
                                found = true;
                                break;
                            }
                        }
                        if (!found) { // Si el estudiante no existe, lo inscribo
                            cursos[i]->addStudent(student);
                            cout << "Estudiante inscripto." << endl;
                            found = true;
                        }
                        break;
                    }
                }
                cout << endl;
            } else if (option == DESINSCRIBIR) { 
                cout << "Ingrese el curso del estudiante a desinscribir: ";
                string course;
                cin.ignore();
                getline(cin, course);
                cout << "Ingrese el nombre del estudiante a desinscribir: ";
                string name;    
                getline(cin, name);
                removeStudentFromCourse(*cursos[0], name);         
            } else if (option == VER_INSCRIPCION) {
                cout << "Ingrese el curso del estudiante a verificar: ";
                string course;
                cin.ignore();
                getline(cin, course);
                cout << "Ingrese el legajo del estudiante a verificar: ";
                int legajo;
                cin >> legajo;
                bool isInCourse = false;
                for (size_t i = 0; i < cursos.size(); i++) { // Itero sobre los cursos
                    if (cursos[i]->getName() == course) { // Busco el curso
                        printIsInCourseLegajo(*cursos[i], legajo); // Verifico si el estudiante está inscripto
                        isInCourse = true;
                        break;
                    }
                }
                if (!isInCourse){
                    cout << "El estudiante no está inscripto en el curso." << endl;
                }
                cout << endl;
            } else if (option == CURSO_COMPLETO) { 
                cout << "Ingrese el nombre del curso: ";
                string course;
                cin.ignore();
                getline(cin, course);
                bool isFull = false;
                for (size_t i = 0; i < cursos.size(); i++) {
                    if (cursos[i]->getName() == course) {
                        printIsFull(*cursos[i]);
                        isFull = true;
                        break;
                    }
                }
                if (!isFull) {
                    cout << "Curso no encontrado." << endl;
                }
                cout << endl;
            } else if (option == IMPRIMIR_LISTA) {
                cout << "Ingrese el nombre del curso: ";
                string course;
                cin.ignore();
                getline(cin, course);
                cout << endl;
                bool found = false;
                for (size_t i = 0; i < cursos.size(); i++) {
                    if (cursos[i]->getName() == course) { // Busco el curso
                        (*cursos[i]).printStudents(); // Imprimo la lista de estudiantes
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Curso no encontrado." << endl;
                }
                cout << endl;
            } else if (option == IMPRIMIR_LISTA_ORDENADA) {
                cout << "Ingrese el nombre del curso: ";
                string course;
                cin.ignore();
                getline(cin, course);
                cout << endl;
                bool found = false;
                for (size_t i = 0; i < cursos.size(); i++) {
                    if (cursos[i]->getName() == course) {
                        cursos[i]->printStudentsOrdered();
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Curso no encontrado." << endl;
                }
                cout << endl;
            } else if (option == AGREGAR_CURSO) {
                cout << "Ingrese el nombre del nuevo curso: ";
                string newCourse;
                cin.ignore();
                getline(cin, newCourse);
                Curso newCurso(newCourse);
                cursos.push_back(make_shared<Curso>(newCurso));
                cout << "Curso agregado." << endl;
            } else if (option == VER_CURSOS) {
                cout << "Cursos disponibles: " << endl;
                for (size_t i = 0; i < cursos.size(); i++) {
                    cout << cursos[i]->getName() << endl;
                }
            } else if (option == COPIAR_CURSO){
                cout << "Ingrese el nombre del curso a copiar: ";
                string course;
                cin.ignore();
                getline(cin, course);
                cout << "Ingrese el nombre del nuevo curso: ";
                string newCourse;
                getline(cin, newCourse);
                bool found = false;
                for (size_t i = 0; i < cursos.size(); i++) {
                    if (cursos[i]->getName() == course) {
                        Curso newCurso(newCourse); // Crear un nuevo curso con el nombre proporcionado
                        newCurso.deepCopy(cursos[i]->getStudents()); // Copiar los estudiantes del curso original
                        cursos.push_back(make_shared<Curso>(newCurso)); // Agregar el nuevo curso a la lista de cursos
                        cout << "Curso copiado." << endl;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Curso no encontrado." << endl;
                }
                cout << endl;

            } else if (option == SALIR) {
                cout << "Saliendo del programa." << endl;
                break;
            } else {
                throw invalid_argument("Opción inválida. Intente nuevamente.");
            }
        } catch (const exception& e) {
            error = true;
            cout << "Error: " << e.what() << endl;
            cout << "Por favor, intente nuevamente." << endl;
        }
    }
    cout << "============================================" << endl;
    cout << "Gracias por usar el sistema de gestión de cursos." << endl;
    return 0;
}