#ifndef ROUTERS_H
#define ROUTERS_H

#include "Librerias.h"

class routers{

public:

    routers();
    routers(char,char[],int[]);
    //void datos(); solo hacen en caso de hacer las modificaciones de conexion y precios
    char GetName();
    bool empty();
    void mapa(char[],int[]);
    ~routers();

private:

    char nombre;
    map<char,int> conexiones;

};

#endif // ROUTERS_H
