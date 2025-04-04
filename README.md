# README

## Ejercicio 1:
En este ejercicio se define una clase Time, que permite expresar un momento en el tiempo.

### Compilación
Para compilar, usar la siguiente línea:
g++ <ej1.cpp> -Wall -g -o <ej1.exe>
Ejecutar con:
/.<ej1.exe>

### Funcionalidades
Se permite inicializar de las siguientes formas: 
- Sin parámetros: 00h, 00m, 00s a.m.
- Solo hora: HHh, 00m, 00s a.m.
- Hora y minutos: HHh, MMm, 00s a.m.
- Hora, minutos y segundos: HHh, MMm, SSs a.m.
- Hora, minutos, segundos y período (a.m. / p.m.)

Y se validan las siguientes cosas a la hora de ser inicializada:
- La hora debe estar entre 0 y 12
- Los minutos y segundos entre 0 y 59
- El período solo puede ser "a.m." o "p.m."

Las horas se pueden imprimir por terminal con formato 24hrs o con formato "am/pm".

### Ejecución
Al ejecutar el programa, se pedirá al usuario que:

1) Elija el tipo de constructor.
2) Ingrese los datos necesarios.
3) Visualice el resultado en ambos formatos.
4) Opcionalmente, modifique la hora ingresada.

Si no se ingresan bien los datos, se pide al usuario ingresarlos bien.


## Ejercicio 2:
En este ejercicio se define una clase Curso y una clase Estudiante. La idea del programa es
poder gestionar distintos cursos con las siguientes acciones, mediante un menú interactivo
por consola.

### Archivos
- `ej2main.cpp`: archivo principal con el menú y lógica del programa.
- `ej2source.cpp`: implementación de las clases Curso y Estudiante.
- `ej2.hpp`: definiciones de clases.

### Compilación
Para compilar todos los archivos en una sola línea, hay que ejecutar:
g++ <ej2main.cpp> <ej2source.cpp> -std=c++17 -o <ejecutableEj2.exe>
Y se corre con:
./<ejecutableEj2.exe>

### Funcionalidades

Al iniciar, se crean automáticamente 4 cursos y 10 estudiantes (hardcodeados). 
Luego se presenta un menú con las siguientes opciones:

    Menú de opciones
    ==========================================
    1. Inscribir estudiante
    2. Desinscribir estudiante
    3. Ver si un estudiante está inscripto
    4. Ver si el curso está completo
    5. Imprimir lista de estudiantes
    6. Imprimir lista de estudiantes ordenada
    7. Agregar curso
    8. Ver cursos
    9. Copiar curso
    10. Salir
    ==========================================

#### Descripción de opciones

1) Inscribe un nuevo estudiante a un curso disponible.
2) Elimina un estudiante por su nombre de un curso.
3) Verifica si un estudiante (por legajo) está inscripto en un curso.
4) Consulta si un curso alcanzó su capacidad máxima.
5) Muestra la lista de estudiantes inscriptos en un curso.
6) Muestra la lista de estudiantes ordenada alfabeticamente.
7) Permite agregar un nuevo curso vacío.
8) Muestra todos los cursos disponibles.
9) Copia un curso existente con todos sus estudiantes (con un nuevo nombre).
10) Sale del sistema.

#### Elección de tipo de copia y relación entre objetos.

Para el 9 (la copia), decidí usar un deep copy ya que hay que alocar la memoria del nuevo 
vector de estudiantes. Un Deep Copy se usa cuando hay que asignar memoria dinámicamente. 
Si yo tengo un curso nuevo, copiado de otro (con los mismos alumnos), quiero poder agregarle
o sacarle estudiantes independientemente del curso al que se le hizo la copia. Por consiguiente, 
necesito un nuevo vector de estudiantes.

El tipo de relacion que tienen los objetos entre sí es de agregación. Esto se debe a que un Curso
tiene estudiantes pero no es dueño de ellos. Además, los estudiantes están gestionados por shared_ptr, 
lo que indica que pueden pertenecer a más de un curso al mismo tiempo, y si se elimina un Curso, 
los alumnos no desaparecen (podrían seguir existiendo en otros cursos).


## Ejercicio 3:

