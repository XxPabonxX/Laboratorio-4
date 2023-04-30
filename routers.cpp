#include "routers.h"

routers::routers(){

    nombre = 0;

}

routers::routers(char _nombre, char conexion[], int precios[]){//sobrecarga del constructor

    nombre=_nombre;
    char conec;
    int prec;

    for(int i=0;i<7;i++){

        conec=conexion[i];
        prec=precios[i];
        conexiones.insert(pair<char,int>(conec,prec));

    }

}

char routers::GetName(){//devuelve el nombre del objeto

    return nombre;

}

bool routers::empty(){//indica si el mapa que contiene las conexiones esta vacio

    bool vacio = conexiones.empty();
    return vacio;

}

void routers::mapa(char conectados[], int precios[]){//devuelve los elementos del mapa

    int contador=0;

    for (auto itr=conexiones.begin();itr!=conexiones.end();itr++){

        conectados[contador]=itr->first;
        precios[contador]=itr->second;
        contador++;

    }

}

routers::~routers(){ //destructor



}
