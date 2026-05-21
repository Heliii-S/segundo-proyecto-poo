#include <iostream>
#include "Biblioteca.h"
int main(){
    Biblioteca b;
    Libro l1;
    l1.set_id(1);
    l1.set_titulo("Calculo");
    l1.set_estado(true);
    l1.set_autor("Stewart");
    l1.set_cant_pag(900);
    Usuario u1;
    u1.set_id_usuario(1);
    u1.set_nombre("Juan Perez");
    u1.set_deuda(false);
    b.agregar_libro(l1);
    b.agregar_usuario(u1);
    b.realizar_prestamo(1,1);
    return 0;
}