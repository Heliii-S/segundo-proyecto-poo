/*
Proyecto: Inventario de una biblioteca, clase Libro
Tessa Heli Serrato Martínez
A01715004
2/06/2026
ver: 3
Esta clase define objetos de tipo Libro que heredan de la clase Objeto
Incluye atributos y métodos propios
*/

#ifndef _LIBRO_
#define _LIBRO_
#include <iostream>
#include <string>
#include "Objeto.h"

// Declaración de la clase hija Libro
class Libro: public Objeto{
    //Declaración de los atributos del objeto
    private:
        std::string autor;
        int cant_pag;
    //Declaración de los métodos que usa el objeto
    public:
        //uso el constructor de la clase padre
        Libro(): Objeto(), autor("Sin autor"),cant_pag(0){};
        Libro(int i, std::string t, bool e, std::string a, int c): Objeto(i,t,e), autor(a), cant_pag(c){};
        // esta función sobreescribe el método abstracto de la clase padre Objeto
        void mostrar_info() override;
        std::string get_autor();
        int get_cant_pag();
        void set_autor(std::string);
        void set_cant_pag(int);
};

/*
mostrar_info
Esta función muestra en pantalla los atributos del objeto
@param 
@return
*/
void Libro::mostrar_info(){
    std::string est;
    if(estado){
        est = "Disponible";
    }
    else{
        est = "No disponible";       
    }
    std::cout << "Titulo: " << titulo << "\nAutor: " << autor << "\nEstado: " << est << "\n# de páginas: " << cant_pag <<std::endl;
}

std::string Libro::get_autor(){
    return autor;
}

int Libro::get_cant_pag(){
    return cant_pag;
}

void Libro::set_autor(std::string a){
    autor = a;
}

void Libro::set_cant_pag(int c){
    cant_pag = c;
}

#endif