/*
Proyecto: Inventario de una biblioteca, clase Objeto
Tessa Heli Serrato Martínez
A01715004
2/06/2026
ver: 3
Esta clase define objetos de tipo Objeto
Contiene atributos y métodos base que hereda a sus hijos, las clases: Libro y Pelicula
*/

#ifndef _OBJETO_
#define _OBJETO_
#include <iostream>
#include <string>

// Declaración de la clase Objeto
class Objeto{
    // Declaración de los atributos
    protected:
        int id;
        std::string titulo;
        bool estado;
    public:
    // Declaración de los métodos
        Objeto(): id(0),titulo("Sin titulo"),estado(true){};
        Objeto(int i, std::string t, bool e): id(i),titulo(t),estado(e){};
        //  método abstracto de la clase padre Objeto que será sobreescrito por las clases hijas: Libro y Pelicula
        virtual void mostrar_info() = 0; 
        int get_id();
        std::string get_titulo();
        bool get_estado();
        void set_id(int);
        void set_titulo(std::string);
        void set_estado(bool);
};

int Objeto::get_id(){
    return id;
}

std::string Objeto::get_titulo(){
    return titulo;
}

bool Objeto::get_estado(){
    return estado;
}

void Objeto::set_id(int i){
    id = i;
}

void Objeto::set_titulo(std::string t){
    titulo = t;
}

void Objeto::set_estado(bool e){
    estado = e;
}
#endif
