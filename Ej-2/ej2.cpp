/*
2. Escribir una clase denominada Curso que contiene un vector (std::vector) con
punteros a objetos estudiantes.
a. El objeto estudiante simplemente cuenta con el nombre completo, su legajo
(que es único por alumno), una lista de cursos con su nota final y los métodos
que crea necesarios para obtener los datos del alumno: nombre completo,
legajo y su promedio general. En función de esto, califique todos los atributos
correctamente.
b. Como se mencionó anteriormente, un objeto de la clase Curso contendrá la lista
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
correspondan) para presentar los datos por pantalla.
v. Dado que algunos cursos comparten la mayor parte de los estudiantes, se
desea poder hacer una copia del objeto curso. Justifique su respuesta con
un comentario en el código (esta puede llevar varias líneas), indicando de
que tipo de copia se trata y como la hizo.
c. ¿Qué tipo de relación existe entre los objetos curso y estudiante?
d. Proporcione un menú que permita evaluar lo pedido en este ejercicio

*/

#include <iostream>
#include <vector>
#include <string>

class Estudiante {
    private:
        std::string nombreCompleto;
        int legajo;

        public:
        
};

class Curso {
    private:
        std::vector<Estudiante*> estudiantes;
        int capacidad;
        int cantidadEstudiantes;
    public:



};