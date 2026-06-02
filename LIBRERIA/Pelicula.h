/*
Proyecto: Inventario de una biblioteca, clase Pelicula
Tessa Heli Serrato Martínez
A01715004
2/06/2026
ver: 3
Esta clase define objetos de tipo Pelicula que heredan de la clase Objeto
Incluye atributos y métodos propios
*/

#ifndef _PELICULA_
#define _PELICULA_
#include <iostream>
#include <string>
#include "Objeto.h"

// Declaración de la clase hija Pelicula
class Pelicula: public Objeto{
    //Declaración de los atributos del objeto
    private:
        std::string formato;
        std::string productora;
        int duracion_min;
    //Declaración de los métodos que usa el objeto
    public:
        //uso el constructor de la clase padre
        Pelicula(): Objeto(), formato("Sin formato"), productora("Sin formato"), duracion_min(0){};
        Pelicula(int i, std::string t, bool e, std::string f, std::string p, int d): Objeto(i,t,e), formato(f), productora(p), duracion_min(d){};
        // esta función sobreescribe el método abstracto de la clase padre Objeto
        void mostrar_info();
        std::string get_formato();
        std::string get_productora();
        int get_duracion_min();
        void set_formato(std::string);
        void set_productora(std::string);
        void set_duracion_min(int);
};

/*
mostrar_info
Esta función muestra en pantalla los atributos del objeto
@param 
@return
*/
void Pelicula::mostrar_info(){
    std::cout << "Titulo: " << titulo << "\nProductora: " << productora << "\nEstado: " << estado << "\nDuración: " << duracion_min << "\nFormato: " << formato <<std::endl;
}

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