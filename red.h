#ifndef RED_H
#define RED_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "nodo.h"

using namespace std;

class Red
{

private:

    string nombre;
    vector<Nodo> topologia;

    string read();
    void write(const string &data);
    int buscarRuta(const string &nombreRuta);

public:
    Red();


    void cargarRed(const string &nombre);
    void guardarRuta();

    void random(const int &numRutas);
    int mejorCamino(const string &rutaInicio, const string &rutaDestino);

    void addRuta(const Nodo &nuevoNodo);
    void deleteRuta(const string &elimNodo);

    bool salir(const string &nombre);
    const vector<string> nombres() const;
    int len() const;

    friend ostream& operator<<(ostream &out, const Red &Red){

        if(!Red.topologia.size()){
            out << "La red esta vacia." << endl;
            return out;
        }

        int ancho = 7;
        string line(1, char(196));

        out << left;
        for(int i=0; i < (Red.len()+1)*ancho; ++i){ line += char(196); }
        out << line << endl;
                            //"********" "|||||||"
        out << setw(ancho) << "*******";
        for(int i=0; i < Red.topologia.size(); ++i){
            out << setw(ancho) << "| " +  Red.topologia[i].getNodo();
        }out << "|" << endl << line << endl;

        for(int i=0; i < Red.topologia.size(); ++i){
            out << setw(ancho) << "| " + Red.topologia[i].getNodo();
            for(int j=0; j < Red.topologia.size(); ++j){
                if(!(Red.topologia[i].getCosto(Red.topologia[j].getNodo()) == INF)){
                    out << setw(ancho) << "| " + to_string(Red.topologia[i].getCosto(Red.topologia[j].getNodo()));
                }else{ out << setw(ancho) << "| ~"; }
            }out << "|" << endl << line << endl;
        }
        return out;
    }
};




#endif // RED_H
