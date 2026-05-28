//CLASE HIJO UNO: LIBRO
#ifndef _LIBRO_
#define _LIBRO_
#include <iostream>
#include <string>
#include "Objeto.h"

class Libro: public Objeto{
    private:
        std::string autor;
        int cant_pag;
    public:
        //usando el constructor de la clase padre
        Libro(): Objeto(), autor("Sin autor"),cant_pag(0){};
        Libro(int i, std::string t, bool e, std::string a, int c): Objeto(i,t,e), autor(a), cant_pag(c){};
        void mostrar_info();
        std::string get_autor();
        int get_cant_pag();
        void set_autor(std::string);
        void set_cant_pag(int);
};

void Libro::mostrar_info(){
    std::cout << "Titulo: " << titulo << "\nAutor: " << autor << "\nEstado: " << estado << "\n# de páginas: " << cant_pag <<std::endl;
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