#ifndef _USUARIO_
#define _USUARIO_
#include <iostream>
#include <string>

class Usuario{
    private:
        int id_usuario;
        std::string nombre;
        bool deuda;
    public:
        Usuario(): id_usuario(0),nombre("Sin nombre"),deuda(false){};
        Usuario(int i, std::string n, bool d): id_usuario(i),nombre(n),deuda(d){};
        int get_id_usuario();
        std::string get_nombre();
        bool get_deuda();
        void set_id_usuario(int);
        void set_nombre(std::string);
        void set_deuda(bool);
};

int Usuario::get_id_usuario(){
    return id_usuario;
}

std::string Usuario::get_nombre(){
    return nombre;
}

bool Usuario::get_deuda(){
    return deuda;
}

void Usuario::set_id_usuario(int u){
    id_usuario = u;
}

void Usuario::set_nombre(std::string n){
    nombre = n;
}

void Usuario::set_deuda(bool d){
    deuda = d;
}
#endif