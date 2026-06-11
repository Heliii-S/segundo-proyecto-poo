/*
Proyecto: Inventario de una biblioteca, clase Biblioteca
Tessa Heli Serrato Martínez
A01715004
2/06/2026
ver: 3
Esta clase define objetos de tipo Biblioteca que contienen las clases:
Objeto y Registro por composición y Usuario por agregación.
Esta clase contiene todas las operaciones usadas para realizar la función
principal del programa como agregar libros, películas o usuarios; consultar
objetos o usuarios; y toda las acciones referentes a préstamos (realizar, renovar y cerrar).
*/

#ifndef _BIBLIOTECA_
#define _BIBLIOTECA_
#include "Objeto.h"
#include "Libro.h"
#include "Pelicula.h"
#include "Registro.h"
#include "Usuario.h"
#include <iostream>
#include <string>

// Declaración de la clase Biblioteca
class Biblioteca{
//Declaración de los arreglos que componen al objeto
private:
    Objeto* inventario[50];
    Usuario usuarios[10];
    Registro registros[50];
    int cant_objetos;
    int cant_usuarios;
    int id_objetos;
    int id_usuarios;
// Declaración de los métodos que tiene el objeto
public:
    // Constructor y destructor de la clase
    Biblioteca();
    ~Biblioteca();
    void agregar_libro();
    void agregar_pelicula();
    void agregar_usuario();
    void mostrar_inventario();
    void consultar_estado_objeto(int);
    void consultar_usuario(int);
    void realizar_prestamo(int,int);
    void renovar_prestamo(int,int);
    void cerrar_prestamo(int,int);
};

/*Constructor de la clase
Inicializa un nuevo objeto Biblioteca con un apuntador nulo 
a cada posición del arreglo inventario[]
@param 
@return
*/
Biblioteca::Biblioteca(){
    cant_objetos = 0;
    cant_usuarios = 0;
    id_objetos = 1;
    id_usuarios = 1;
    for(int i=0;i<50;i++){
        inventario[i] = NULL;
    }
}

/*Destructor de la clase
Borra cada posición del arreglo inventario[]
@param 
@return
*/

Biblioteca::~Biblioteca(){
    for(int i=0;i<cant_objetos;i++){
        delete inventario[i];
    }
}

/*
agregar_libro
Esta función pide los datos necesarios para crear un objeto
de tipo Libro y agregarlo al arreglo inventario[]
@param 
@return
*/
void Biblioteca::agregar_libro(){
    if (cant_objetos >= 50){
        std::cout << "Inventario lleno\n";
        return;
    }
    int pag;
    std::string titulo, autor;
    std::cout << "Ingresa los siguientes datos\n";
    std:: cout << "Titulo: ";
    std::getline(std::cin,titulo);

    std:: cout << "Autor: ";
    std::getline(std::cin,autor);

    std::cout << "Paginas (int): ";
    std::cin >> pag;

    inventario[cant_objetos] = new Libro(id_objetos,titulo,true,autor,pag);
    std::cout << "Libro agregado con ID: " << id_objetos << "\n";
    cant_objetos ++;
    id_objetos ++;
}

/*
agregar_pelicula
Esta función pide los datos necesarios para crear un objeto
de tipo Pelicula y agregarlo al arreglo inventario[]
@param 
@return
*/
void Biblioteca::agregar_pelicula(){
    if (cant_objetos >= 50){
        std::cout << "Inventario lleno\n";
        return;
    }
    int dur;
    std::string titulo, formato,productora;
    std::cout << "Ingresa los siguientes datos\n";
    std:: cout << "Titulo: ";
    std::getline(std::cin,titulo);

    std:: cout << "Formato (DVD O BD): ";
    std::getline(std::cin,formato);

    std::cout << "Productora: ";
    std::getline(std::cin,productora);

    std::cout << "Duracion en min (int): ";
    std::cin >> dur;

    inventario[cant_objetos] = new Pelicula(id_objetos,titulo,true,formato,productora,dur);
    std::cout << "Pelicula agregada con ID: " << id_objetos << "\n";
    cant_objetos ++;
    id_objetos ++;
}

/*
agregar_usuario
Esta función pide los datos necesarios para crear un objeto
de tipo Usuario y agregarlo al arreglo usuarios[]
@param 
@return
*/
void Biblioteca::agregar_usuario(){
    if (cant_usuarios >= 10){
        std::cout << "\nNo es es posible realizar la accion";
        std::cout << "\nMOTIVO: Limite de usuarios alcanzado";
        return;
    }
    std::string nombre;
    std::cout << "Ingresa los siguientes datos\n";
    std:: cout << "Nombre: ";
    std::getline(std::cin,nombre);
    usuarios[cant_usuarios] = Usuario(id_usuarios,nombre,false);
    std::cout << "Usuario agregado con ID: " << id_usuarios << "\n";
    cant_usuarios ++;
    id_usuarios ++;
}

/*
mostrar_inventario
Esta funcion recorre el arreglo inventario[]
y muestra los datos de todos los objetos guardados en el
@param 
@return 
*/
void Biblioteca::mostrar_inventario(){
    for(int i=0;i<cant_objetos;i++){
        inventario[i]->mostrar_info();
    }
}

/*
consultar_estado_objeto
Esta función recorre el arreglo inventario[]
y busca aquel que tenga el id correspondiente
para devolver la información relacionada con el id
@param int que representa el id del objeto
@return 
*/
void Biblioteca::consultar_estado_objeto(int id){
    for(int i=0; i<cant_objetos; i++){
        if(inventario[i]->get_id() == id){
            inventario[i]->mostrar_info();
            return;
        }
    }
    std::cout << "No es es posible realizar la accion\n";
    std::cout << "MOTIVO: Objeto no encontrado.\n";
}

/*
consultar_usuario
Esta función recorre el arreglo usuarios[]
y busca aquel que tenga el id correspondiente
para devolver la información relacionada con el id
@param int que representa el id del usuario
@return
*/
void Biblioteca::consultar_usuario(int id){
    for(int i=0; i<cant_usuarios; i++){
        if(usuarios[i].get_id_usuario() == id){
            std::cout << "\nNombre: "
                      << usuarios[i].get_nombre();
            std::cout << "\nID: "
                      << usuarios[i].get_id_usuario();
            if(usuarios[i].get_prestamo_activo()){
                std::cout << "\nTiene un prestamo activo";
                for(int j=0; j<50; j++){
                    if(registros[j].get_id_u() == id &&
                       registros[j].get_estatus()){
                        std::cout << "\nFecha de devolucion: " << registros[j].get_df() << "/" << registros[j].get_mf() << "/" << registros[j].get_af();
                        break;
                    }
                }
            }
            else{
                std::cout << "\nNo tiene ningun prestamo activo";
            }
            std::cout << std::endl;
            return;
        }
    }
    std::cout << "\nUsuario no encontrado\n";
}

/*
realizar_prestamo
Esta función recorre los arreglos inventario[] y usuarios[]
pide la fecha del préstamo y agrega un registro al arreglo registros[]
@param int que representa el id del usuario, int que representa el id del objeto
@return
*/
void Biblioteca::realizar_prestamo(int id_usuario,
                                   int id_objeto){
    Registro temp;
    int di, mi, ai, pos_usuario;
    std::cout << "Día del préstamo (1-31): ";
    std::cin >> di;
    std::cout << "Mes del préstamo (1-12): ";
    std::cin >> mi;
    std::cout << "Anio del préstamo (ej. 2026): ";
    std::cin >> ai;
    temp.calcular_fdev(di,mi,ai);
    int df = temp.get_df();
    int mf = temp.get_mf();
    int af = temp.get_af();
    bool usuario_encontrado = false;
    for(int i=0; i<10; i++){
        if(usuarios[i].get_id_usuario() == id_usuario){
            usuario_encontrado = true;
            if(usuarios[i].get_prestamo_activo() == true){
                std::cout << "No es posible realizar el prestamo: \n";
                std::cout << "MOTIVO: El usuario tiene un prestamo activo \n";
                return;
            }
            pos_usuario = i;
        }
    }
    if(usuario_encontrado==false){
        std::cout << "No es posible realizar el prestamo: \n";
        std::cout << "MOTIVO: Usuario no encontrado\n";
        return;
    }
    for(int i=0; i<cant_objetos; i++){
        if(inventario[i]->get_id() == id_objeto){
            if(inventario[i]->get_estado() == true){
                inventario[i]->set_estado(false);
                Registro nuevo(di,mi,ai,df,mf,af,id_objeto,id_usuario,true);
                for(int j = 0; j < 50; j++){
                    if(registros[j].get_estatus()==false){
                        registros[j] = nuevo;
                        usuarios[pos_usuario].set_prestamo_activo(true);
                        std::cout << "Prestamo realizado\n";
                        std::cout << "Fecha de devolucion: " << df << "/" << mf << "/" << af << "\n";
                        return;
                    }
                }
                std::cout << "No es posible realizar el prestamo: \n";
                std::cout << "MOTIVO: No hay espacio para registrar prestamos\n";
                return;
            }
            std::cout << "No es posible realizar el prestamo: \n";
            std::cout << "MOTIVO: Objeto no disponible\n";
            return;
        }
    }
    std::cout << "No es posible realizar el prestamo: \n";
    std::cout << "MOTIVO: Objeto no encontrado\n";
}

/*
renovar_prestamo
Esta función recorre el arreglo registros[],
encuentra el registro a modificar y le asigna una nueva fecha
@param int que representa el id del usuario, int que representa el id del objeto
@return
*/
void Biblioteca::renovar_prestamo(int id_usuario,
                                  int id_objeto){
    for(int i=0; i<50; i++){
        if(registros[i].get_id_u() == id_usuario &&
           registros[i].get_id_objeto() == id_objeto &&
           registros[i].get_estatus() == true){
            int di = registros[i].get_df();
            int mi = registros[i].get_mf();
            int ai = registros[i].get_ai();
            registros[i].calcular_fdev(di,mi,ai);
            int df = registros[i].get_df();
            int mf = registros[i].get_mf();
            int af = registros[i].get_af();
            std::cout << "Prestamo renovado por 5 días\n";
            std::cout << "Fecha de devolucion: " << df << "/" << mf << "/" << af << "\n";
            return;
        }
    }
    std::cout << "No es posible realizar la renovacion: \n";
    std::cout << "MOTIVO: Registro no encontrado\n";
}

/*
cerrar_prestamo
Esta función recorre el arreglo registros[],
encuentra el registro a modificar y cambia su estado
@param int que representa el id del usuario, int que representa el id del objeto
@return
*/
void Biblioteca::cerrar_prestamo(int id_usuario,
                                 int id_objeto){
    for(int i=0; i<50; i++){
        if(registros[i].get_id_u() == id_usuario &&
           registros[i].get_id_objeto() == id_objeto &&
           registros[i].get_estatus() == true){
            registros[i].set_estatus(false);
            // Cambiar estado del usuario
            for(int j=0; j < cant_usuarios; j++){
                if(usuarios[j].get_id_usuario() == id_usuario){
                    usuarios[j].set_prestamo_activo(false);
                    break;
                }
            }
            // Registrar que el objeto ya esta disponible
            for(int k=0; k< cant_objetos; k++){
                if(inventario[k]->get_id()==id_objeto){
                    inventario[k]->set_estado(true);
                    std::cout << "Prestamo cerrado\n";
                    return;
                }
            }
        }
    }
    std::cout << "No es posible cerrar el prestamo: \n";
    std::cout << "MOTIVO: Prestamo no encontrado\n";
}
#endif
