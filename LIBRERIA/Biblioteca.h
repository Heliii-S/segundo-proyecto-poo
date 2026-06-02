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
#include "Libro.h"
#include "Pelicula.h"
#include "Registro.h"
#include "Usuario.h"

// Declaración de la clase Biblioteca
class Biblioteca{
//Declaración de los arreglos que componen al objeto
private:
    Libro libros[25];
    Pelicula peliculas[25];
    Usuario usuarios[10];
    Registro registros[50];
// Declaración de los métodos que tiene el objeto
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

/*
agregar_libro
Esta función agrega objetos de tipo Libro al arreglo libros[]
@param objeto de tipo libro 
@return
*/
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

/*
agregar_pelicula
Esta función agrega objetos de tipo Pelicula al arreglo peliculas[]
@param objeto de tipo Pelicula
@return
*/
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

/*
agregar_usuario
Esta función agrega objetos de tipo Usuario al arreglo usuarios[]
@param objeto de tipo Usuario
@return
*/
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

/*
verificar_inventario
Esta función recorre los arreglos libros[] y peliculas[]
y busca aquellos que estén disponbiles
@param 
@return int con la suma de los objetos que cumplen con la condición
*/
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

/*
consultar_objeto
Esta función recorre los arreglos libros[] y peliculas[]
y busca aquel que tenga el id correspondiente
@param int que representa el id del objeto
@return bool que representa el estado del objeto (disponible o no)
*/
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

/*
consultar_usuario
Esta función recorre el arreglo usuarios[]
y busca aquel que tenga el id correspondiente
@param int que representa el id del usuario
@return string que es el nombre del usuario
*/
std::string Biblioteca::consultar_usuario(int id){

    for(int i=0; i<10; i++){
        if(usuarios[i].get_id_usuario() == id){
            return usuarios[i].get_nombre();
        }
    }
    return "Usuario no encontrado";
}

/*
realizar_prestamo
Esta función recorre los arreglos libros[], peliculas[] y usuarios[]
pide la fecha del préstamo y agrega un registro al arreglo registros[]
@param int que representa el id del usuario, int que representa el id del objeto
@return
*/
void Biblioteca::realizar_prestamo(int id_usuario,
                                   int id_objeto){
    Registro temp;
    int di, mi, ai;
    std::cout << "Día del préstamo: ";
    std::cin >> di;
    std::cout << "Mes del préstamo: ";
    std::cin >> mi;
    std::cout << "Anio del préstamo: ";
    std::cin >> ai;
    temp.calcular_fdev(di,mi,ai);
    int df = temp.get_df();
    int mf = temp.get_mf();
    int af = temp.get_af();
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
                int ido = id_objeto;
                Registro nuevo(di,mi,ai,df,mf,af,ido,id_usuario,true);
                for(int j = 0; j < 50; j++){
                    if(registros[j].get_estatus()==false){
                        registros[j] = nuevo;
                        std::cout << "Prestamo realizado\n";
                        std::cout << "Fecha de devolucion: " << df << "/" << mf << "/" << af << "\n";
                        return;
                }
            }
            }
        }
    for(int i=0; i<25; i++){
        if(peliculas[i].get_id() == id_objeto){
            if(peliculas[i].get_estado() == true){
                peliculas[i].set_estado(false);
                int ido = id_objeto;
                Registro nuevo(di,mi,ai,df,mf,af,ido,id_usuario,true);
                for(int j = 0; j < 50; j++){
                    if(registros[j].get_estatus()==false){
                        registros[j] = nuevo;
                        std::cout << "Prestamo realizado\n";
                        std::cout << "Fecha de devolucion: " << df << "/" << mf << "/" << af << "\n";
                        return;
                }
            }
            }
        }
    }
    std::cout << "Objeto no disponible\n";
}
                                   }

/*
renovar_prestamo
Esta función recorre el arreglo registros[]
y mediante distintas condiciones encuentra el registro a modificar y le asigna una nueva fecha
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
    std::cout << "Registro no encontrado\n";
}

/*
cerrar_prestamo
Esta función recorre el arreglo registros[]
y mediante distintas condiciones encuentra el registro a modificar y cambia su estado
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