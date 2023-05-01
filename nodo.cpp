#include "nodo.h"

Nodo::Nodo()
{

}

Nodo::Nodo(const string &nodo)
{
    this->nodo = nodo;
    conexiones[nodo] = 0;
}

const string &Nodo::getNodo() const
{
    return nodo;
}

void Nodo::setNombre(const string &nodo)
{
    this->nodo = nodo;
    conexiones[nodo] = 0;
}

const int &Nodo::getCosto(const string &nodo) const
{
    return conexiones.find(nodo)->second;
}

void Nodo::addConexion(const string &nodo, const int &costo)
{
    conexiones[nodo] = costo;
}

void Nodo::deleteConexion(const string &nodo)
{
    conexiones.erase(nodo);
}
