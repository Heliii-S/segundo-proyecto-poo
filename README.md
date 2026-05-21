# segundo-proyecto-poo
Proyecto integrador para POO, 2do parcial
- DESCRIPCIÓN GENERAL -
En este proyecto, busco generar un programa de una biblioteca que lleva el registro de un inventario  de libros y películas, que permita mostrar la cantidad de elementos disponibles en la biblioteca (de 50 que pueden tenerse), su estado (en biblioteca o prestado) y en caso de préstamo que usuario tiene el objeto, la fecha en que realizó el préstamo y cuando debe devolverlo.

- ESTRUCTURA DEL PROGRAMA - 
Se usa la clase de Objeto (que tiene una relación de herencia con las clases: Libro y Pelicula), la clase Biblioteca (donde se puede verificar el inventario; consulta tanto de usuarios como de objetos (libros y películas) e historial de préstamos a través de la clase Registro, la clase Usuario (que guarda el estatus, id y deuda) y la clase Registro (donde se hace uso de la información que Biblioteca recopila, para realizar todos los cálculos referentes a los préstamos).

- CASOS DONDE EL PROGRAMA DEJARÍA DE FUNCIONAR (BORRADOR) -
  Por ahora considero que se podrían tener problemas en los siguientes casos:
  -> Si se llena alguno de los arreglos
  -> Si intentamos devolver o pedir prestado algo que no existe.
  -> Consultar usuarios y objetos inexistentes, y en general dar respuestas no esperadas al programa.
  -> En general debo analizar mejor un poco más de la lógica del programa para poder identificar otros errores y lagunas en él.
