#include <iostream>
#include "Biblioteca.h"
int main(){
    // creo un objeto libro y un objeto película
    Libro l1(1,"Cálculo vectorial",true,"Stewart",900);
    Pelicula p1(2,"Cuatro bodas y un funeral", true, "BluRay","Warner",117);
    // se crea un puntero que apunta al objeto
    Objeto* obj;
    // primero hace referencia al objeto l1
    obj = &l1;
    // y llama la función
    obj -> mostrar_info();
    // luego al objeto p1
    obj = &p1;
    // y también llama a la función
    obj -> mostrar_info();
}