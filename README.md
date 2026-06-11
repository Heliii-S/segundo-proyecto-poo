# Segundo proyecto para Programación Orientada a Objetos
Es es el proyecto integrador para Programación Orientada a Objetos, 2do parcial

## Descripción general
En este proyecto, genero un programa  lleva el registro del inventario y préstamos que hace una biblioteca (libros y películas), el programa permite mostrar la cantidad de elementos disponibles en la biblioteca (de 50 que pueden tenerse), su estado (disponible (1) o no disponible (0)) y en caso de préstamo la fecha en que realizó el préstamo y cuando debe devolverlo. Además, cuando se realiza un préstamo, este solo puede realizarse si el usuario existe y no tiene ningún otro prestamo activo, y si el material existe y está disponible. Todas estas acciones se controlan a través de un menú.

*IMPORTANTE:* Los usuarios solo pueden pedir prestado un artículo a la vez, es decir, si tienen un préstamo activo no pueden iniciar otro hasta cerrar el iniciado.

## Funcionalidad
Se usa:

* La clase de Objeto, que tiene una relación de herencia con las clases: Libro y Pelicula, para crear objetos que se agregan al inventario de la Biblioteca.

* La clase Biblioteca, donde se puede verificar el inventario, consultar usuarios (nombre, id, si tiene un prestamo activo y la fecha de devolucion del prestamo activo en caso de tener uno) y objetos (libros y películas) y gestionar todo lo relacionado a los prestamos (iniciar, renovar y cerrar).

* La clase Usuario; que guarda el estatus, id y si el usuario tiene un prestamo activo de los distintos usuarios creados. 

* La clase Registro, donde se realizan los cálculos relacionados a la fecha de devolución.

## Sobre cómo compilar el programa
Para compilar el programa se debe descargar la carpeta LIBRERIA y abrir una pestaña de terminal en ella.

En el caso de *Mac* se pone el comando: "g++ -o main main.cpp" y luego "./main", se podrá ver el output del programa en la terminal.

En *Windows*, si se usa el compilador GNU, el comando sería: "g++ main.cpp -o main" y para ejecutar: ./programa (o solo programa.exe).

## Casos donde el programa dejaría de funcionar

-> Si damos una respuesta inesperada al momento de ingresar la fecha del préstamo.

-> Si al seleccionar una opción en el menú o cuando se registra un objeto o fecha, el usuario brinda un tipo de dato diferente al que el programa espera, en ese caso se crea un loop infinito.

-> En los siguientes casos el programa dará un mensaje de error al usuario para decir cuál es la razón por la que no se puede completar la acción:

  - Si se llena alguno de los arreglos, indica que el inventario está lleno.

  - Si consultamos un usuario u objeto que no existe.

  - Si intentamos realizar un prestamo a un usuario con un préstamo activo, a un usuario que no existe, si   ya no hay espacio para registrar préstamos o intentamos prestar un objeto no disponible o que no existe.

  - Si no existe un registro e intentamos renovarlo.
  
  - Si no existe un préstamo e intentamos cerrarlo.


    

