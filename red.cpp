#include "red.h"

//Macro para la ruta de los archivos
#define PATH "../practica4/archivotxt/"

string filename=PATH;

red::red()//constructor
{

}

string red::txt_copy(string nombre) //Sacar el txt como string
{
    ifstream archivo;
    string texto, textofin;
    archivo.open(filename+nombre, ios::in);//archivo en modo lectura
    if(archivo.fail())
    {
        cout<<"El archivo no se pudo abrir"<<endl;
        exit(1);
    }

    while(!archivo.eof())//Mientras no llegue a en End Of File
    {
        getline(archivo,texto);
        textofin+=texto+"\n";
    }
    archivo.close();
    int len=textofin.length()-1;
    textofin.erase(len);
    return textofin;
}

bool red::exis_router(char nombre) //verifica si el router existe en la lista de la red
{
    bool existe=false;
    char caracter;
    for(int i=0;i<7;i++)
    {
        caracter=enrutadores[i];
        if(caracter==nombre)
        {
            existe=true;
        }
    }
    return existe;
}

int red::pos_router(char name, char nombres[7]) //entrega la posicion de un char en un arreglo
{
    int pos=0;
    char caracter;
    for(int i=0;i<7;i++)
    {
        caracter=nombres[i];
        if(caracter==name)
        {
            pos=i;
            return pos;
        }
    }
    return pos;
}

void red::info_routers(string texto, char nombres[7], char conectados[7][7], int costos[7][7]) //entrega toda la informacion para crear las instancias de routers
{
    vector<string> lineas;
    int longi=texto.length(), posi, posi2, precio;
    string caracter, linea, linea2,precio_string;
    char carac,carac2;
    for (int i=0;i<=longi;i++)//se separa por lineas
    {
        caracter = texto[i];
        if(caracter != "\n" and i!=longi)
        {
            linea+=caracter;
        }
        else if(i==longi)
        {
            lineas.push_back(linea);
            linea.clear();
        }
        else
        {
            lineas.push_back(linea);
            linea.clear();
        }
    }
    bool existe;
    int contador=-1;
    for(auto i=lineas.begin();i != lineas.end(); i++)//se sacan los datos
    {
        linea=*i;
        carac=linea[0];
        existe=exis_router(carac);
        if(existe==false)
        {
            contador++;
            nombres[contador]=carac;
            enrutadores[contador]=carac;
        }
        carac2=linea[1];
        existe=exis_router(carac2);
        if(existe==false)
        {
            contador++;
            nombres[contador]=carac2;
            enrutadores[contador]=carac2;
        }
        posi=pos_router(carac,nombres);
        posi2=pos_router(carac2,nombres);
        conectados[posi][posi2]=carac2;
        longi=linea.length();
        for(int k=3;k<longi;k++)
        {
            precio_string+=linea[k];
        }
        precio=atoi(precio_string.c_str());
        precio_string.clear();
        costos[posi][posi2]=precio;
    }
}

int red::conta_routers(char routers[7])//cuenta la cantidad de elementos usados en un arreglo
{
    char caracter;
    int contador=0;
    for(int i=0;i<7;i++)
    {
        caracter=routers[i];
        if(caracter!=0)
        {
            contador++;
        }
        else
        {
            return contador;
        }
    }
    return contador;
}

void red::conexiones_red(routers enrutadores_insta[7], char conexiones[7][7], int precios[7][7])//Recive la lista de instancias y devulve los arreglos de conexiones y precios
{
    char caracter;
    int pos;
    for (int i=0;i<7;i++)
    {
        routers actu=enrutadores_insta[i];
        if(actu.GetName()!=0)
        {
            if(actu.empty()==false)
            {
                char conectados[7]={0,0,0,0,0,0,0};
                int price[7]={0,0,0,0,0,0,0};
                actu.mapa(conectados,price);
                caracter=actu.GetName();
                pos=pos_router(caracter,enrutadores);
                for(int j=0;j<7;j++)
                {
                    conexiones[pos][j]=conectados[j];
                    precios[pos][j]=price[j];
                }
            }
        }
    }
}

void red::ruta_coste(char origen, char destino, char conectados[7][7], int precios[7][7])//SN Devuelve el costo y la ruta mas efectiva
{
    //se recibe el origen y el destino, teniendo en cuenta la informacion de las clases se imprime el costo minimo ademas de la ruta mas eficiente
    bool exis_ori=exis_router(origen), exis_dest=exis_router(destino);
    if (exis_dest==true and exis_ori==true)
    {
        //Algoritmo para hallar costos y rutas
        string ruta_fin;
        int costo_fin;

    }
    else if (exis_dest==false and exis_ori==true)
    {
        cout<<"El destino ingresado no existe"<<endl<<endl;
    }
    else if (exis_dest==true and exis_ori==false)
    {
        cout<<"El origen ingresado no existe"<<endl<<endl;
    }
    else
    {
        cout<<"No existe ninguno de los 2 enrutadores ingresados"<<endl<<endl;
    }
}

bool red::verificar(char conectados[7][7]) //verifica que haya almenos 2 routers y por lo menos alguna conexion
{
    bool funciona=false;
    int num_router=conta_routers(enrutadores);
    if(num_router<2)
    {
        funciona=false;
        return funciona;
    }
    char caracter;
    for(int i=0;i<7;i++)
    {
        for(int j=0;j<7;j++)
        {
            caracter=conectados[i][j];
            if(caracter!=0)
            {
                funciona=true;
                return funciona;
            }
        }
    }
    return funciona;
}

void red::modificar(char *nombre, char conected[7], int costos[7])//agregar routers
{
    int num_routers=conta_routers(enrutadores);
    if(num_routers==7)
    {
        cout<<"Se ha alcanzado el numero maximo de enrutadores en la red (7 enrutadores), para agregar otro debe eliminar alguno de los existentes"<<endl;
    }
    else
    {
        char neim, siono;
        int cost_now;
        cout<<"Ingrese el nombre del nuevo enrutador: ";cin>>neim;
        cout<<endl;
        *nombre=neim;
        if(num_routers>0)
        {
            cout<<"A continuacion ingrese s/n para indicar si esta conectado al router correspondiente y luego ingrese el respectivo costo de envio en caso de existir dicha conexion."<<endl;
            for(int i=0;i<num_routers;i++)
            {
                cout<<"El enrutador en creacion esta conectado con el enrutador "<<enrutadores[i]<<"? ";cin>>siono;
                while(siono != 's' or siono != 'S' or siono != 'n' or siono != 'N')
                {
                    cout<<"Caracter invalido."<<endl;
                    cout<<"El enrutador en creacion esta conectado con el enrutador "<<enrutadores[i]<<"? ";cin>>siono;
                }
                if(siono=='s' or siono=='S')
                {
                    conected[i]=enrutadores[i];
                    cout<<"Cual es el costo de envio hacia el enrutador "<<enrutadores[i]<<"? ";cin>>cost_now;
                    while(cost_now<0)
                    {
                        cout<<"El costo de envio debe ser mayor a 0."<<endl;
                        cout<<"Cual es el costo de envio hacia el enrutador "<<enrutadores[i]<<"? ";cin>>cost_now;
                    }
                    costos[i]=cost_now;
                    cout<<endl;
                }
            }
            enrutadores[num_routers]=neim;
            cout<<"El router ha sido creado con exito"<<endl<<endl;
        }
    }

}

int red::modificar()//eliminar routers
{
    int num_routers=conta_routers(enrutadores);
    if(num_routers==0)
    {
        cout<<"Actualmente no existe ningun enrutador por lo que es imposible realizar esta accion."<<endl;
    }
    else
    {
        char nombre;
        int posi;
        cout<<"Ingrese el nombre del enrutador a eliminar: ";cin>>nombre;
        bool existe=exis_router(nombre);
        if(existe==false)
        {
            cout<<"No existe ningun router con ese nombre registrado en la red."<<endl;
        }
        else
        {
            posi=pos_router(nombre,enrutadores);
            int a_correr=(conta_routers(enrutadores)-1)-posi;
            for(int i=posi;i<(posi+a_correr+1);i++)
            {
                enrutadores[posi]=enrutadores[posi+1];
            }
            return posi;
        }
    }
}

int red::cant_routers_red()//devuelve la cantidad de routers actualmente en la red
{
    int canti=conta_routers(enrutadores);
    return canti;
}

red::~red()//destructor
{

}
