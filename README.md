# segundo-proyecto-poo
Proyecto integrador para POO, 2do parcial
- DESCRIPCIÓN GENERAL -
En este proyecto, busco generar un programa de una biblioteca que lleva el registro de un inventario  de libros y películas, que permita mostrar la cantidad de elementos disponibles en la biblioteca (de 50 que pueden tenerse), su estado (en biblioteca o prestado) y en caso de préstamo que usuario tiene el objeto, la fecha en que realizó el préstamo y cuando debe devolverlo.

- ESTRUCTURA DEL PROGRAMA - 
Se usa la clase de Objeto (que tiene una relación de herencia con las clases: Libro y Pelicula), la clase Biblioteca (donde se puede verificar el inventario; consulta tanto de usuarios como de objetos (libros y películas) e historial de préstamos a través de la clase Registro, la clase Usuario (que guarda el estatus, id y deuda) y la clase Registro (donde se hace uso de la información que Biblioteca recopila, para realizar todos los cálculos referentes a los préstamos).

Se incluye POLIMORFISMO en el programa a través de la función: mostrar_info() que se encuentra en la clase padre Objeto y da una respuesta diferente dependiendo de si es llamada por el hijo Libro o por el hijo Película mostrando toda la información relevante sobre el objeto en cuestión (sus atributos).

- CÓMO COMPILAR EL PROGRAMA
  -> Para compilar el programa se debe descargar la carpeta LIBRERIA y abrir una pestaña de terminal en ella, en el caso de Mac se pone el comando: "g++ -o main main.cpp" y luego "./main", se podrá ver el output del programa en la terminal.
  -> En Windows, si se usa el compilador GNU, el comando sería: "g++ main.cpp -o main" y para ejecutar: ./programa (o solo programa.exe).

- CASOS DONDE EL PROGRAMA DEJARÍA DE FUNCIONAR (YA NO SEGUIRÍA CUMPLIENDO SU FUNCIÓN) -
  Por ahora considero que se podrían tener problemas en los siguientes casos:
  -> Si se llena alguno de los arreglos
  -> Si intentamos devolver o pedir prestado algo que no existe.
  -> Si no existe un préstamo e intentamos cerrarlo.
  -> En estos casos el programa dará un mensaje de error al usuario para decir cuál es la razón por la que no se puede completar la acción.

