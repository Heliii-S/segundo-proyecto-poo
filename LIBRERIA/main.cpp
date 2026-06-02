/*
Proyecto: Inventario de una biblioteca, main
Tessa Heli Serrato Martínez
A01715004
2/06/2026
ver: 3
Este es un proyecto demo para la clase TC1030 Programación Orientado a
Objetos. Es un programa que captura diferentes tipos de objetos (libros y películas) en una biblioteca con sus
respectivos atributos, y nos permite llevar un control de préstamos e inventario con los distintos usuarios que existen.
 */

 #include <iostream>
#include "Biblioteca.h"
int main(){
    // se crea un objeto de tipo Libro, un objeto de tipo Pelicula, un objeto de tipo Usuario y objeto de tipo Biblioteca
    Libro l1(1,"Cálculo vectorial",true,"Stewart",900);
    Pelicula p1(2,"Cuatro bodas y un funeral", true, "BluRay","Warner",117);
    Usuario u1(1,"Juan",false);
    Biblioteca b1;
    // pongo a prueba los distintos métodos de la biblioteca
    b1.agregar_libro(l1);
    b1.agregar_pelicula(p1);
    b1.agregar_usuario(u1);
    bool r1 = b1.consultar_objeto(1);
    std::cout << "Estado del objeto (1 = disponible): " << r1 << " \n";
    b1.realizar_prestamo(1,1);
    bool r2 = b1.consultar_objeto(1);
    std::cout << "Estado del objeto (1 = disponible): " << r2 << " \n";
    b1.renovar_prestamo(1,1);
    b1.cerrar_prestamo(1,1);
    bool r3 = b1.consultar_objeto(1);
    std::cout << "Estado del objeto (1 = disponible): " << r3 << " \n";
    // se crea un puntero que apunta al objeto
    std::cout << "Uso de punteros: ";
    Objeto* obj;
    // primero hace referencia al objeto l1
    obj = &l1;
    // se llama la función
    std::cout<<"\nObjeto l1: ";
    obj -> mostrar_info();
    // luego se hace referencia al objeto p1
    obj = &p1;
    // y nuevamente se llama la función
    std::cout<<"\nObjeto p1: ";
    obj -> mostrar_info();

    
}