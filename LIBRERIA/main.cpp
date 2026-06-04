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
    Biblioteca b;
    int opcion;
    do{
        std::cout << "\n- Bienvenido al programa de inventario - ";
        std::cout << "\n 1. Agregar libro";
        std::cout << "\n 2. Agregar pelicula";
        std::cout << "\n 3. Agregar usuario";
        std::cout << "\n 4. Mostrar inventario";
        std::cout << "\n 5. Consultar estado objeto";
        std::cout << "\n 6. Consultar usuario";
        std::cout << "\n 7. Realizar un prestamo";
        std::cout << "\n 8. Renovar un prestamo";  
        std::cout << "\n 9. Cerrar un prestamo";     
        std::cout << "\n 0. Salir del programa";  
        std::cout << "\n Ingresa la opcion que quieres realizar: ";
        std::cin >> opcion;
        switch(opcion){
            case 1:
                std::cin.ignore();
                b.agregar_libro();
                break;
            case 2:
                std::cin.ignore();           
                b.agregar_pelicula();
                break;
            case 3:
                std::cin.ignore();
                b.agregar_usuario();
                break;
            case 4:
                b.mostrar_inventario();
                break;
            case 5:
                int io;
                std::cout << "\nIngresa el id del objeto: ";
                std::cin >> io;
                b.consultar_estado_objeto(io);
                break;
            case 6:
                int iu;
                std::cout << "\nIngresa el id del usuario: ";
                std::cin >> iu;
                b.consultar_usuario(iu);
                break;
            case 7:
                int iu1,io1;
                std::cout << "\nIngresa el id del usuario: ";
                std::cin >> iu1; 
                std::cout << "\nIngresa el id del objeto: ";
                std::cin >> io1;
                b.realizar_prestamo(iu1,io1);    
                break;
            case 8:
                int iu2,io2;
                std::cout << "\nIngresa el id del usuario: ";
                std::cin >> iu2; 
                std::cout << "\nIngresa el id del objeto: ";
                std::cin >> io2;
                b.renovar_prestamo(iu2,io2);    
                break;
            case 9:
                int iu3,io3;
                std::cout << "\nIngresa el id del usuario: ";
                std::cin >> iu3; 
                std::cout << "\nIngresa el id del objeto: ";
                std::cin >> io3;
                b.cerrar_prestamo(iu3,io3);    
                break;                               
        }
    } while(opcion != 0);
}