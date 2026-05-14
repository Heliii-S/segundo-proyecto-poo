# segundo-proyecto-poo
Proyecto integrador para POO, 2do parcial
- DESCRIPCIÓN GENERAL -
En este proyecto, busco generar un programa de una biblioteca que lleva el registro de un inventario  de libros y películas, que permita mostrar la cantidad de elementos, su estado (en biblioteca, préstamo, extraviado) y en caso de préstamo que usuario tiene el objeto, la fecha en que realizó el préstamo y cuando debe devolverlo (libros y películas tienen un tiempo diferente de devolución).

- ESTRUCTURA DEL PROGRAMA - 
Se usa la clase de Objeto (que tiene una relación de herencia con las clases: Libro y Pelicula), la clase Biblioteca (donde se puede verificar el inventario; historial y estado tanto de usuarios como de libros, a través de la clase Prestamo), la clase Fecha (para llevar un registro de cuando deben realizarse las devoluciones y si deben crearse multas), la clase Usuario (que guarda el estatus, id, deuda y nombre de hasta 10 usuarios de la biblioteca) y la clase Prestamo (donde se hace uso de los objetos creados por las clases: Objeto y  Usuario, para usar los objetos creados por la clase Flecha para así realizar todos los cálculos referentes a los préstamos).

- CASOS DONDE EL PROGRAMA DEJARÍA DE FUNCIONAR (BORRADOR) -
  Por ahora considero que se podrían tener problemas en los siguientes casos:
  -> Si se llena alguno de los arreglos
  -> Si intentamos devolver algo que no existe, pedir prestado algo que ya está prestado (o que no existe), consultar usuarios inexistentes, y en general dar respuestas no esperadas al programa.
  -> En general debo analizar mejor un poco más de la lógica del programa para poder identificar otros errores y lagunas en él.
