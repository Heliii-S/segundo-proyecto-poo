/*
Proyecto: Inventario de una biblioteca, clase Usuario
Tessa Heli Serrato Martínez
A01715004
2/06/2026
ver: 3
Esta clase define objetos de tipo Usuario
Incluye atributos y métodos
*/

#ifndef _USUARIO_
#define _USUARIO_
#include <iostream>
#include <string>

// Declaración de la clase Usuario
class Usuario{
    //Declaración de los atributos del objeto
    private:
        int id_usuario;
        std::string nombre;
        bool prestamo_activo;
    //Declaración de los métodos que usa el objeto
    public:
        Usuario(): id_usuario(0),nombre("Sin nombre"),prestamo_activo(false){};
        Usuario(int i, std::string n, bool p): id_usuario(i),nombre(n),prestamo_activo(p){};
        int get_id_usuario();
        std::string get_nombre();
        bool get_prestamo_activo();
        void set_id_usuario(int);
        void set_nombre(std::string);
        void set_prestamo_activo(bool);
};

/*
get_id_usuario
@param 
@return int que representa el id del usuario
*/
int Usuario::get_id_usuario(){
    return id_usuario;
}

/*
get_nombre
@param 
@return string que representa el nombre
*/
std::string Usuario::get_nombre(){
    return nombre;
}

/*
get_prestamo_activo
@param 
@return bool que representa si el prestamo está activo o no
*/
bool Usuario::get_prestamo_activo(){
    return prestamo_activo;
}

/*
set_id_usuario
@param int que representa el id del usuario
@return 
*/
void Usuario::set_id_usuario(int u){
    id_usuario = u;
}

/*
set_nombre
@param string que representa el nombre
@return 
*/
void Usuario::set_nombre(std::string n){
    nombre = n;
}

/*
set_prestamo_activo
@param bool que representa si el prestamo está activo o no
@return 
*/
void Usuario::set_prestamo_activo(bool p){
    prestamo_activo = p;
}
#endif