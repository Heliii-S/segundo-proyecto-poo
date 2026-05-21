//CLASE HIJO DOS: PELÍCULA
#ifndef _PELICULA_
#define _PELICULA_
#include <iostream>
#include <string>
#include "Objeto.h"

class Pelicula: public Objeto{
    private:
        std::string formato;
        std::string productora;
        int duracion_min;
    public:
        std::string get_formato();
        std::string get_productora();
        int get_duracion_min();
        void set_formato(std::string);
        void set_productora(std::string);
        void set_duracion_min(int);
};

std::string Pelicula::get_formato(){
    return formato;
}

std::string Pelicula::get_productora(){
    return productora;
}

int Pelicula::get_duracion_min(){
    return duracion_min;
}

void Pelicula::set_formato(std::string f){
    formato = f;
}

void Pelicula::set_productora(std::string p){
    productora = p;
}

void Pelicula::set_duracion_min(int d){
    duracion_min = d;
}

#endif