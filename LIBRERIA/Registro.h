/*
Proyecto: Inventario de una biblioteca, clase Registro
Tessa Heli Serrato Martínez
A01715004
2/06/2026
ver: 3
Esta clase define objetos de tipo Registro
Contiene todas los atributos y el método usado para llevar un registro de las fechas de devolución
*/

#ifndef _REGISTRO_
#define _REGISTRO_
#include <iostream>
#include <string>
#include <sstream>

// Declaración de la clase Registro
class Registro{
    // Declaración de los atributos que tiene el objeto
    private:
        int di;
        int mi;
        int ai;
        int df;
        int mf;
        int af;
        int id_objeto;
        int id_u;
        bool estatus;
    // Declaración de los métodos que tiene el objeto
    public:
        Registro(): di(0),mi(0),ai(0),df(0),mf(0),af(0),id_objeto(0),id_u(0),estatus(false){};
        Registro(int d1, int m1, int a1, int d2, int m2, int a2, int o, int u, bool e): di(d1),mi(m1),ai(a1),df(d2),mf(m2),af(a2),id_objeto(o),id_u(u),estatus(e){};
        int get_di();
        int get_mi();
        int get_ai();
        int get_df();
        int get_mf();
        int get_af();
        int get_id_objeto();
        int get_id_u();
        bool get_estatus();
        void set_di(int);
        void set_mi(int);
        void set_ai(int);
        void set_df(int);
        void set_mf(int);
        void set_af(int);
        void set_id_objeto(int);
        void set_id_u(int);
        void set_estatus(bool);
        std::string calcular_fdev(int, int, int);
};

int Registro::get_di(){
    return di;
}
int Registro::get_mi(){
    return mi;
}
int Registro::get_ai(){
    return ai;
}
int Registro::get_df(){
    return df;
}
int Registro::get_mf(){
    return mf;
}
int Registro::get_af(){
    return af;
}
int Registro::get_id_objeto(){
    return id_objeto;
}
int Registro::get_id_u(){
    return id_u;
}
bool Registro::get_estatus(){
    return estatus;
}
void Registro::set_di(int i){
    di = i;
}
void Registro::set_mi(int i){
    mi = i;
}
void Registro::set_ai(int i){
    ai = i;
}
void Registro::set_df(int i){
    df = i;
}
void Registro::set_mf(int i){
    mf = i;
}
void Registro::set_af(int i){
    af = i;
}
void Registro::set_id_objeto(int i){
    id_objeto = i;
}
void Registro::set_id_u(int i){
    id_u = i;
}
void Registro::set_estatus(bool i){
    estatus = i;
}

/*
calcular_fdev
Esta función calcula la fecha de devolución que corresponde a 5 días después de la fecha brindada
@param int que representa el día, int que representa el mes, int que representa el año
@return string que muestra la fecha de devolución
*/
std::string Registro::calcular_fdev(int d, int m, int a){
    df = d + 5;
    mf = m;
    af = a;
    int diasMaximos = 0;
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12){
        diasMaximos = 31;
    }
    else if (m == 4 || m == 6 || m == 9 || m == 11){
        diasMaximos = 30;
    }
    else if (m == 2) { // checamos que el mes sea febrero
        // Validación de año bisiesto, para ver si febrero tiene que tener 29 o 28
        if ((af % 4 == 0 && af % 100 != 0) || (af % 400 == 0)) {
            diasMaximos = 29; //af representa el año final, si es bisiesto tendrá 29 días el mes
        } else {
            diasMaximos = 28; // sino es bisiesto tiene 28 días
        }
    } 
    else{
        return "Error en el ingreso de datos";
    } 
    if (d < 1 || d > diasMaximos) {
        return "Error en el ingreso de datos";
    }
    if (df > diasMaximos) {
        df = df - diasMaximos;
        mf += 1; 
        // (si pasa al siguiente año)
        if (mf > 12) {
            mf = 1;
            af += 1;
        }
    }
    std::stringstream ss;
    ss << "D: " << df << ", M: " << mf << ", A: " << af;
    return ss.str();
}
#endif