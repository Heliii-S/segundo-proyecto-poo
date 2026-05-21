#ifndef _REGISTRO_
#define _REGISTRO_
#include <iostream>
#include <string>
#include <sstream>

class Registro{
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
std::string Registro::calcular_fdev(int d, int m, int a){
    int df = d + 5;
    int mf = m;
    int af = a;
    int diasMaximos = 0;
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12){
        diasMaximos = 31;
    }
    else if (m == 4 || m == 6 || m == 9 || m == 11){
        diasMaximos = 30;
    }
    else if (m == 2) {
        // Validación de año bisiesto
        if ((af % 4 == 0 && af % 100 != 0) || (af % 400 == 0)) {
            diasMaximos = 29;
        } else {
            diasMaximos = 28;
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