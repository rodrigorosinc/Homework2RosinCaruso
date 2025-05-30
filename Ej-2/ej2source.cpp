#include "ej2.hpp"

using namespace std;
// Clase Estudiante:
    // Constructor
Estudiante::Estudiante(string nombreCompleto, int legajo) : nombreCompleto(nombreCompleto), legajo(legajo) {}
   
    // getters
string Estudiante::getName(){return nombreCompleto;};
int Estudiante::getLegajo(){return legajo;};
float Estudiante::getAverage(){
    if (cursos.empty()) {return 0.0f;}
    float sum = 0;
    for (size_t i = 0; i < cursos.size(); i++){
        sum += get<1>(cursos[i]); // el get<1> obtiene la nota del curso
    }
    return sum / cursos.size();
}

    // sobrecarga de operadores
bool Estudiante::operator< (const Estudiante& other) { 
    if (this->nombreCompleto < other.nombreCompleto) return true; // Comparar por nombre, orden alfabético
    return false;
}
ostream& operator<< (ostream& os, const Estudiante& estudiante) { // Sobrecarga de operador de salida
    os << "Nombre: " << estudiante.nombreCompleto << ", Legajo: " << estudiante.legajo; // Imprimir nombre y legajo
    return os;
}

    // Métodos
void Estudiante::addCourse(string course, float grade) {
    cursos.push_back(make_tuple(course, grade));
}

void Estudiante::removeCourse(string course) {
    for (size_t i = 0; i < cursos.size(); i++) {
        if (get<0>(cursos[i]) == course) { // el get<0> obtiene el nombre del curso
            cursos.erase(cursos.begin() + i);
            return;
        }
    }
    cout << "Curso no encontrado." << endl;
}

// Clase Curso:
    // Constructor
Curso::Curso(string cname) {max_capacity = 20; size = 0; name = cname;}
    
    // getters
vector<shared_ptr<Estudiante>> Curso::getStudents() {return estudiantes;}
int Curso::getSize() {return size;}
int Curso::getMaxCapacity() {return max_capacity;}
string Curso::getName() {return name;}

    // setters
void Curso::setStudents(vector<shared_ptr<Estudiante>> estudiantes) {this->estudiantes = estudiantes;}
void Curso::setSize(int size) {this->size = size;}
void Curso::setMaxCapacity(int max_capacity) {this->max_capacity = max_capacity;}

    // Métodos
void Curso::addStudent(shared_ptr<Estudiante> estudiante) {
    if (size < max_capacity) {
        estudiantes.push_back(estudiante);
        size++;
    } else {
        cout << "Curso completo" << endl;
    }
} 
void Curso::removeStudent(shared_ptr<Estudiante> estudiante){
    string name = estudiante->getName();
    for (size_t i = 0; i<size; i++){
        if (name == estudiantes[i]->getName()){
            estudiantes.erase(estudiantes.begin() + i);
            size--;
            return;
        }
    }   
}
bool Curso::isInCourse(int legajo){
    for (size_t i = 0; i<size; i++){
        if (estudiantes[i]->getLegajo() == legajo){
            return true;
        }
    }
    return false;
}
bool Curso::isFull(){
    if (size == 20) {return true;}
    return false;
}
void Curso::printStudents(){
    if (estudiantes.empty()){
        cout << "No hay estudiantes en el curso." << endl;
        return;
    }
    cout << "Lista de estudiantes: " << endl;
    for (size_t i = 0; i < estudiantes.size(); i++){
        cout << *estudiantes[i] << endl;
    }
}
void Curso::printStudentsOrdered(){
    if (estudiantes.empty()){
        cout << "No hay estudiantes en el curso." << endl;
        return;
    }
    cout << "Lista de estudiantes ordenada: " << endl;
    sort(estudiantes.begin(), estudiantes.end(), [](shared_ptr<Estudiante> a, shared_ptr<Estudiante> b) {
        return *a < *b;
    });
    for (size_t i = 0; i < estudiantes.size(); i++){
        cout << *estudiantes[i] << endl;
    }
}
/*
Para la copia, decidí usar un deep copy ya que hay que alocar la memoria del nuevo 
vector de estudiantes. Un Deep Copy se usa cuando hay que asignar memoria dinámicamente. 
Si yo tengo un curso nuevo, copiado de otro (con los mismos alumnos), quiero poder agregarle
o sacarle estudiantes independientemente del curso al que se le hizo la copia. Por consiguiente, 
necesito un nuevo vector de estudiantes.
*/
void Curso::deepCopy(vector<shared_ptr<Estudiante>> estudiantes) {
    vector<shared_ptr<Estudiante>> new_students; // Crear un nuevo vector para almacenar los estudiantes copiados
    // Iterar sobre el vector original y crear copias profundas de los estudiantes
    for (size_t i = 0; i < estudiantes.size(); i++) {
        shared_ptr<Estudiante> student = make_shared<Estudiante>(*estudiantes[i]); // Crear una copia profunda del estudiante
        // Agregar la copia al nuevo vector
        new_students.push_back(student);
    }
    this->estudiantes = new_students;
}