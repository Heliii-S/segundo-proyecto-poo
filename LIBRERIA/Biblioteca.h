#ifndef _BIBLIOTECA_
#define _BIBLIOTECA_

#include "Libro.h"
#include "Pelicula.h"
#include "Registro.h"
#include "Usuario.h"

class Biblioteca{
private:
    Libro libros[25];
    Pelicula peliculas[25];
    Usuario usuarios[10];
    Registro registros[50];
public:
    void agregar_libro(Libro);
    void agregar_pelicula(Pelicula);
    void agregar_usuario(Usuario);
    int verificar_inventario();
    bool consultar_objeto(int);
    std::string consultar_usuario(int);
    void realizar_prestamo(int,int);
    void renovar_prestamo(int,int);
    void cerrar_prestamo(int,int);
};

void Biblioteca::agregar_libro(Libro l){
    for(int i=0; i<25; i++){
        if(libros[i].get_id() == 0){
            libros[i] = l;
            std::cout << "Libro agregado\n";
            return;
        }
    }
    std::cout << "Inventario lleno\n";
}

void Biblioteca::agregar_pelicula(Pelicula p){
    for(int i=0; i<25; i++){
        if(peliculas[i].get_id() == 0){
            peliculas[i] = p;
            std::cout << "Pelicula agregada\n";
            return;
        }
    }
    std::cout << "Inventario lleno\n";
}

void Biblioteca::agregar_usuario(Usuario u){
    for(int i=0; i<10; i++){
        if(usuarios[i].get_id_usuario() == 0){
            usuarios[i] = u;
            std::cout << "Usuario agregado\n";
            return;
        }
    }
    std::cout << "Limite de usuarios alcanzado\n";
}

int Biblioteca::verificar_inventario(){
    int disponibles = 0;
    for (int i=0; i<25;i++){
        if (libros[i].get_estado() == true){
            disponibles++;
        }
        if(peliculas[i].get_estado()==true){
            disponibles++;
        }
    }
    return disponibles;
}

bool Biblioteca::consultar_objeto(int id){

    for(int i=0; i<25; i++){
        if(libros[i].get_id() == id){
            return libros[i].get_estado();
        }
        if(peliculas[i].get_id() == id){
            return peliculas[i].get_estado();
        }
    }
    return false;
}

std::string Biblioteca::consultar_usuario(int id){

    for(int i=0; i<10; i++){
        if(usuarios[i].get_id_usuario() == id){
            return usuarios[i].get_nombre();
        }
    }
    return "Usuario no encontrado";
}

void Biblioteca::realizar_prestamo(int id_usuario,
                                   int id_objeto){
    for(int i=0; i<10; i++){
        if(usuarios[i].get_id_usuario() == id_usuario){
            if(usuarios[i].get_deuda() == true){
                std::cout << "Usuario con deuda\n";
                return;
            }
        }
    }
    for(int i=0; i<25; i++){
        if(libros[i].get_id() == id_objeto){
            if(libros[i].get_estado() == true){
                libros[i].set_estado(false);
                std::cout << "Prestamo realizado\n";
                return;
            }
        }
    }
    std::cout << "Objeto no disponible\n";
}

void Biblioteca::renovar_prestamo(int id_usuario,
                                  int id_objeto){
    for(int i=0; i<50; i++){
        if(registros[i].get_id_u() == id_usuario &&
           registros[i].get_id_objeto() == id_objeto &&
           registros[i].get_estatus() == true){
            int nuevo_dia;
            nuevo_dia = registros[i].get_df() + 5;
            registros[i].set_df(nuevo_dia);
            std::cout << "Prestamo renovado por 5 días\n";
            return;
        }
    }
    std::cout << "Registro no encontrado\n";
}

void Biblioteca::cerrar_prestamo(int id_usuario,
                                 int id_objeto){
    for(int i=0; i<50; i++){
        if(registros[i].get_id_u() == id_usuario &&
           registros[i].get_id_objeto() == id_objeto &&
           registros[i].get_estatus() == true){
            registros[i].set_estatus(false);
            for(int j=0; j<25; j++){
                if(libros[j].get_id() == id_objeto){
                    libros[j].set_estado(true);
                }
                if(peliculas[j].get_id() == id_objeto){
                    peliculas[j].set_estado(true);
                }
            }
            std::cout << "Prestamo cerrado\n";
            return;
        }
    }
    std::cout << "Prestamo no encontrado\n";
}
#endif