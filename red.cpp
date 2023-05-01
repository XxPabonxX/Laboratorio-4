#include "red.h"

Red::Red()
{

}



void Red::guardarRuta()
{
    string data;

    for(int i=0; i < len(); ++i){
        data += topologia[i].getNodo() + ":{";
        for(int j=0; j < len(); ++j){
            data += topologia[j].getNodo() + ":";
            if(topologia[i].getCosto(topologia[j].getNodo()) == INF){ data += "- "; }
            else{
                data += to_string(topologia[i].getCosto(topologia[j].getNodo())) + " ";
            }
        }
        data.pop_back();
        data += "}\n";
    }
    data.pop_back();
    write(data);
}

void Red::random(const int &numNodos)
{
    nombre = "Red_aleatoria";

    srand(time(NULL));
    vector<char> caracteres;

    for(int i=65; i<=90; ++i){
        caracteres.push_back(i);
    }

    for(int i=0; i < numNodos; ++i){

        int random = rand()%caracteres.size();
        topologia.push_back(Nodo(string(1, caracteres[random])));
        caracteres.erase(caracteres.begin()+random);
    }

    for(int i=0; i < topologia.size(); ++i){

        for(int j=0; j<topologia.size(); ++j){

            if(j != i){

                if(rand()%3){
                    topologia[i].addConexion(topologia[j].getNodo(), 1+rand()%15);
                }

                else{
                   topologia[i].addConexion(topologia[j].getNodo(), INF);
                }

                topologia[j].addConexion(topologia[i].getNodo(), topologia[i].getCosto(topologia[j].getNodo()));
            }
        }
    }
}

int Red::mejorCamino(const string &rutaInicio, const string &rutaDestino)
{
    vector<Nodo> optimizedTopologia = topologia;
    for(int k=0; k < optimizedTopologia.size(); ++k){

        for(int i=0; i < optimizedTopologia.size(); ++i){

            for(int j=0; j < optimizedTopologia.size(); ++j){

                if(optimizedTopologia[i].getCosto(optimizedTopologia[k].getNodo()) + optimizedTopologia[k].getCosto(optimizedTopologia[j].getNodo()) < optimizedTopologia[i].getCosto(optimizedTopologia[j].getNodo())){

                    optimizedTopologia[i].addConexion(optimizedTopologia[j].getNodo(), optimizedTopologia[i].getCosto(optimizedTopologia[k].getNodo()) + optimizedTopologia[k].getCosto(optimizedTopologia[j].getNodo()));
                }
                optimizedTopologia;
            }
        }
    }

    return optimizedTopologia[buscarRuta(rutaInicio)].getCosto(rutaDestino);
}

void Red::addRuta(const Nodo &nuevoNodo)
{
    for(int i=0; i < topologia.size(); ++i){
        topologia[i].addConexion(nuevoNodo.getNodo(), nuevoNodo.getCosto(topologia[i].getNodo()));
    }
    topologia.push_back(nuevoNodo);
}

void Red::deleteRuta(const string &elimNodo)
{
    for(int i=0; i < topologia.size(); ++i){
        topologia[i].deleteConexion(elimNodo);
    }
    topologia.erase(topologia.begin() + buscarRuta(elimNodo));
}

bool Red::salir(const string &nombre)
{
    for(int i=0; i < topologia.size(); ++i){
        if(topologia[i].getNodo() == nombre){
            return true;
        }
    }
    return false;
}

const vector<string> Red::nombres() const
{
    vector<string> nombres;
    for(int i=0; i < topologia.size(); ++i){
        nombres.push_back(topologia[i].getNodo());
    }
    return nombres;
}

int Red::len() const
{
    return topologia.size();
}

/***/
void Red::write(const string &data)
{


    ofstream file;

    file.open("../networks/" + nombre);
    if (file.is_open()){

        file << data;

        file.close();
    }
    else{
        cout << "Error al crear " << nombre << endl;
        exit(1);
    }
}

int Red::buscarRuta(const string &nombreRuta)
{
    for(int i=0; i < topologia.size(); ++i){
        if(topologia[i].getNodo() == nombreRuta){
            return i;
        }
    }

    return 0;
}

