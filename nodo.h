#ifndef NODO_H
#define NODO_H

#include <iostream>
#include <string>
#include <map>

#define INF 999999

using namespace std;

class Nodo
{
private:
    string nodo;
    map<string, int> conexiones;
public:
    Nodo();
    Nodo(const string &nodo);

    const string &getNodo() const;
    void  setNombre(const string &nodo);

    const  int &getCosto(const string &nodo) const;

    void addConexion(const string &nodo, const int &costo);
    void deleteConexion(const string &nodo);
};

#endif // NODO_H
