//CLASE PADRE: OBJETO
#ifndef _OBJETO_
#define _OBJETO_
#include <iostream>
#include <string>

class Objeto{
    protected:
        int id;
        std::string titulo;
        bool estado;
    public:
        Objeto(): id(0),titulo("Sin titulo"),estado(true){};
        Objeto(int i, std::string t, bool e): id(i),titulo(t),estado(e){};
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