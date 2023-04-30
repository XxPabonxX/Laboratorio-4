#ifndef ROUTERS_H
#define ROUTERS_H

#include "Librerias.h"

class routers{

public:

    routers();
    routers(char,char[7],int[7]);
    //void datos(); solo hacen en caso de hacer las modificaciones de conexion y precios
    char GetName();
    bool empty();
    void mapa(char[7],int[7]);
    ~routers();

private:

    char nombre;
    map<char,int> conexiones;

};

#endif // ROUTERS_H
