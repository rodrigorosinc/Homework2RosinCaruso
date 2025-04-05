# README

## Ejercicio 1:

### Implementacion de un "reloj" con clases

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
Al ejecutar el programa, sucede lo siguiente:

1) Se pide al usuario que elija el tipo de constructor.
2) Se pide al usuario que ingrese los datos.
3) Luego, se imprime la hora en ambos formatos.
4) Se da la opcion al usuario de cambiar la hora.

Si no se ingresan bien los datos, nuevamente, se pregunta por los mismos.


## Ejercicio 2:

### Interacción entre clases

En este ejercicio se define una clase Curso y una clase Estudiante. La idea del programa es
poder gestionar distintos cursos con las siguientes acciones, mediante un menú interactivo
por consola.

### Archivos
- `ej2.hpp`: definiciones de clases.
- `ej2source.cpp`: implementación de las clases Curso y Estudiante.
- `ej2main.cpp`: archivo principal con el menú y lógica del programa.

### Compilación
Para compilar todos los archivos en una sola línea, hay que ejecutar:
g++ <ej2main.cpp> <ej2source.cpp> -Wall -g -o <ejecutableEj2.exe>
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

#### Descripción de las opciones

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

#### Relación entre objetos.

El tipo de relacion que tienen los objetos entre sí es de agregación. Esto se debe a que un Curso
tiene estudiantes pero no es dueño de ellos. Además, los estudiantes están gestionados por shared_ptr, 
lo que indica que pueden pertenecer a más de un curso al mismo tiempo, y si se elimina un Curso, 
los alumnos no desaparecen (podrían seguir existiendo en otros cursos).

**Nota**: La explicación de por qué uso deep copy está en el archivo ej2source.cpp

## Ejercicio 3:

### Operaciones Numéricas con Polimorfismo en C++

Este ejercicio implementa ciertas clases para representar y operar con distintos tipos de números:
**Enteros**, **Reales** y **Complejos**. Se utiliza **herencia** y **polimorfismo** para definir una interfaz 
común (`Numero`) que permite realizar operaciones como suma, resta y multiplicación entre objetos del mismo tipo.

### Archivos

- `ej3.hpp`: Define la interfaz `Numero` y las clases derivadas `Entero`, `Real` y `Complejo`, 
cada una con su propia implementación de las operaciones.
- `ej3source.cpp`: Contiene la implementación de las operaciones definidas en las clases.
- `3j3main.cpp`: Prueba el funcionamiento de las clases realizando operaciones entre objetos de cada tipo, 
imprimiendo los resultados por consola.

### Compilación

Para compilar el programa usar:
g++ <ej3main.cpp> <ej3source.cpp> -Wall -g -o <ejecutableEj3.exe>
Para ejecutalo, correr:
./<ejecutableEj3.exe>

### Funcionalidades

Cada clase derivada implementa los siguientes métodos:

- `Numero* suma(Numero* n)`
- `Numero* resta(Numero* n)`
- `Numero* multiplicacion(Numero* n)`
- `std::string toString()`

**Nota:** Las operaciones están definidas solamente entre objetos del mismo tipo. Si se intenta operar con otro tipo de número, se retorna `nullptr`. Por ejemplo, no se puede sumar un Real a un Entero. 

## Ejercicio 4:

###  Simulación de una Cuenta Bancaria. Herencia múltiple.

En este ejercicio, se define una clase CuentaCorriente que simula el comportamiento de una cuenta bancaria. El usuario puede realizar depósitos, retiros y consultar el estado de su cuenta a través de un menú interactivo por consola.

### Archivos
- `ej4.hpp`: Contiene la definición de la clases.
- `ej4source.cpp`: Implementación de los métodos de la clase.
- `ej4main.cpp`: Programa principal que permite interactuar con una cuenta a través de un menú.

### Compilación
Para compilar el programa completo, ejecutar:
g++ <ej4main.cpp> <ej4source.cpp> -Wall -g -o <ejecutableEj4.exe>
Y para correrlo:
./<ejecutableEj4.exe>

### Funcionalidades
Al ejecutar el programa, se pide al usuario crear una caja de ahorro o una cuenta corriente. Sujeto a esto,
se presenta un menú que permite realizar las siguientes acciones:

========= MENÚ =========
1. Consultar saldo
2. Depositar dinero
3. Extraer dinero
4. Salir

========================

### Descripción de las opciones

1) Muestra el saldo actual de la cuenta.
2) Permite ingresar un monto positivo a depositar.
3) Permite retirar dinero, siempre que haya fondos suficientes. Si no hay fondos, se informa al usuario.
4) Finaliza el programa.

### Validaciones
+ No se permite depositar ni extraer montos negativos o cero.
+ No se puede extraer más dinero del que hay en la cuenta.

### Uso de especificadores de acceso

- En la clase Cuenta, los atributos *balance* y *titular* son *protected*. Elegí esto para que las clases derivadas puedan acceder a ellos sin exponerlos. Los métodos como `depositar()`, `getBalance()` y los virtuales `retirar()` y `mostrarInfo()` son public ya que forman parte de la interfaz pública.

- En CajaDeAhorro, *contador* es *private* porque solo lo usa la clase para controlar el número de visualizaciones. Se declara *friend* a `CuentaCorriente` para permitir el acceso directo al balance, si fuera necesario.

- En CuentaCorriente, la referencia a `CajaDeAhorro` es private ya que representa un detalle interno de implementación. Sus métodos también son public para permitir su uso desde afuera.
