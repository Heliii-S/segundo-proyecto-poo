# Segundo proyecto para Programación Orientada a Objetos
Es es el proyecto integrador para Programación Orientada a Objetos, 2do parcial

## Descripción general
En este proyecto, genero un programa  lleva el registro del inventario y préstamos que hace una biblioteca (libros y películas), el programa permite mostrar la cantidad de elementos disponibles en la biblioteca (de 50 que pueden tenerse), su estado (disponible (1) o no disponible (0)) y en caso de préstamo la fecha en que realizó el préstamo y cuando debe devolverlo. Además, cuando se realiza un préstamo, este solo puede realizarse si el usuario existe y no tiene deudas, y si el material existe y está disponible.

## Funcionalidad
Se usa:
La clase de Objeto (que tiene una relación de herencia con las clases: Libro y Pelicula) para crear objetos que se agregan al inventario de la Biblioteca.

La clase Biblioteca, donde se puede verificar el inventario y consultar usuarios y objetos (libros y películas).

La clase Usuario; que guarda el estatus, id y deuda de los distintos usuarios creados.

La clase Registro, donde se realizan los cálculos relacionados a la fecha de devolución.

Además, se incluye *POLIMORFISMO* en el programa a través de la función: mostrar_info() que se encuentra en la clase padre *Objeto* y da una respuesta diferente dependiendo de si es llamada por el hijo *Libro* o por el hijo *Película* mostrando todos los atributos del objeto en cuestión.

## Sobre cómo compilar el programa
Para compilar el programa se debe descargar la carpeta LIBRERIA y abrir una pestaña de terminal en ella.

En el caso de *Mac* se pone el comando: "g++ -o main main.cpp" y luego "./main", se podrá ver el output del programa en la terminal.

En *Windows*, si se usa el compilador GNU, el comando sería: "g++ main.cpp -o main" y para ejecutar: ./programa (o solo programa.exe).

## Casos donde el programa dejaría de funcionar
Considero que se podrían tener problemas en los siguientes casos:

Si se llena alguno de los arreglos.

Si damos una respuesta inesperada al momento de ingresar la fecha de inicio del préstamo.

En los siguientes casos el programa dará un mensaje de error al usuario para decir cuál es la razón por la que no se puede completar la acción:

Si intentamos devolver o pedir prestado algo que no existe.

Si no existe un préstamo e intentamos cerrarlo.

Si consultamos un usuario que no existe.


