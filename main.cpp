/*
   Recopilacion: Un maximo de 7 routers, cada ruter es capaz de conocer los costos de envio hacia
   los otros routers a los que esta conectado, se deben poder actualizar los precios y
   conexiones en tiempo de ejecucion, se deben poder agregar y eliminar routers.
   Debe haber una tabla general de costes de envio para usos internos.
   Se debe poder cargar una topologia desde un archivo de texto.
   Por ultimo se debe ofrecer al usuario el coste de envio desde un origen a un destino
   y ademas indicarle cual es el camino mas corto/eficiente

   Analisis: El programa debe ser extremada mende versatil, que sea capaz de adaptarse a practicamente
   cualquier topologia ingresada por el usuario dentro de las regulaciones del mismo, el uso de objetos
   y librerias sera escencial en muchos trayectos. Saber que tipo de dato usar sera escencial para que
   el programa se ejecute sin problemas.
 */

#include "Librerias.h"

int main(){

    int opcion;
    bool terminar=false;
    cout << "NOTA(S): Una vez cerrado el programa se borrara la red que haya sido creada en el proceso"<<endl<<endl;


    while (terminar==false)
    {
        cout<<"1 - Inicializar un red por medio de un archivo de texto (maximo de 7 enrutadores)"<<endl;
        cout<<"2 - Crear red agregando o eliminando enrutadores o conexiones (maximo de 7 enrutadores)"<<endl;
        cout<<"3 - Salir del programa"<<endl<<endl;
        cout<<"Ingrese la opcion deseada: ";cin>>opcion;
        while ((opcion<1) || (opcion>3)){

            cout<<"Opcion invalida."<<endl;
            cout<<"Ingrese la opcion deseada: ";
            cin>>opcion;

        }

        switch(opcion){
            //------------------------------------------------------------------------------------------------------------------
            case 1: //Inicializar un red por medio de un archivo de texto
            {
                for (int i=0;i<=50;i++){

                    cout<<endl;

                }

                string nom_arch, info;
                cout<<"Ingrese el nombre del archivo en el que se encuentra la topologia(sin extension de archivo): ";cin>>nom_arch;
                nom_arch+=".txt";//Se le agrega la extension
                char name[7]={0,0,0,0,0,0,0}, conexiones[7][7], name_actu, conec, conexiones_actu[7];
                int price[7][7], price_actu[7], precio, limit;
                red topologia= red();
                info = topologia.txt_copy(nom_arch);//se guarda en info los datos que estaban en el txt
                topologia.info_routers(info,name,conexiones,price);//se saca toda la informacion para las instancias
                routers uno,dos,tres,cuatro,cinco,seis,siete;
                limit=topologia.conta_routers(name);

                for(int i=0;i<limit;i++){

                    name_actu=name[i];

                    for(int j=0;j<7;j++){

                        conec=conexiones[i][j];
                        conexiones_actu[j]=conec;

                    }

                    for(int j=0;j<7;j++){

                        precio=price[i][j];
                        price_actu[j]=precio;

                    }

                    if(i==0){

                        uno=routers(name_actu,conexiones_actu,price_actu);

                    }

                    else if(i==1){

                        dos=routers(name_actu,conexiones_actu,price_actu);

                    }

                    else if(i==2){

                        tres=routers(name_actu,conexiones_actu,price_actu);

                    }

                    else if(i==3){

                        cuatro=routers(name_actu,conexiones_actu,price_actu);

                    }

                    else if(i==4){

                        cinco=routers(name_actu,conexiones_actu,price_actu);

                    }

                    else if(i==5){

                        seis=routers(name_actu,conexiones_actu,price_actu);

                    }

                    else{

                        siete=routers(name_actu,conexiones_actu,price_actu);

                    }

                }

                bool preguntar=true;
                if (limit==0){

                    preguntar=false;
                    cout<<"El programa no encontro ningun enrutador."<<endl<<endl;
                    cout<<"Pulse la tecla 'Enter' para continuar"<<endl;
                    cin.get();

                }

                while (preguntar==true){

                    for (int i=0;i<=50;i++){

                        cout<<endl;

                    }

                    int elec;
                    cout<<"A continuacion indique que desea hacer con la red: "<<endl<<endl;
                    cout<<"Ingrese 1 para hacer una consulta sobre rutas y costos."<<endl;
                    cout<<"Ingrese 2 para agregar o eliminar una conexion o enrutador"<<endl;
                    cout<<"Ingrese 3 para volver al menu principal"<<endl<<endl;
                    cout<<"Opcion: ";
                    cin>>elec;

                    while((elec<1) || (elec>3)){

                        cout<<"Opcion invalida."<<endl;
                        cout<<"Ingrese la opcion deseada: ";
                        cin>>elec;

                    }

                    switch (elec){

                        case 1: //consultas
                        {
                            for (int i=0;i<=50;i++){

                                cout<<endl;

                            }

                            char ori, dest;
                            bool funciona;
                            routers all_routers[7]={uno,dos,tres,cuatro,cinco,seis,siete};
                            char conectaos[7][7];
                            int valen[7][7];
                            topologia.conexiones_red(all_routers,conectaos,valen);
                            funciona = topologia.verificar(conectaos); //se verifica la validez de la red a este momento

                            if (funciona==false){

                                cout<<"La red no cumple los requisitos para hacer una consulta, agregue mas routers y conexiones!"<<endl<<endl;
                                cout<<"Pulse la tecla 'Enter' para continuar"<<endl;
                                cin.get();

                            }

                            else{

                                cout<<"Ingrese el enrutador origen: ";cin>>ori;
                                cout<<"Ingrese el enrutador destino: ";cin>>dest;
                                cout<<endl;
                                topologia.ruta_coste(ori,dest,conectaos,valen);

                            }

                        }

                        break;
                        case 2: //modificaciones
                        {
                            for (int i=0;i<=50;i++){

                                cout<<endl;

                            }

                            int opci;
                            cout<<"Ingrese 1 para agregar un enrutador"<<endl;
                            cout<<"Ingrese 2 para eliminar un enrutador"<<endl;
                            cout<<"Ingrese 3 para volver"<<endl;
                            cout<<"Digite su opcion: ";
                            cin>>opci;

                            while((opci<1) || (opci>3)){

                                cout<<"Opcion invalida."<<endl;
                                cout<<"Digite su opcion: ";
                                cin>>opci;

                            }

                            switch (opci){

                                case 1: //Agregar router
                                {

                                    char nom_router, conectad_router[7]={0};
                                    int preci_router[7]={0};
                                    topologia.modificar(&nom_router,conectad_router,preci_router);
                                    int num_nom=topologia.cant_routers_red();

                                    if(num_nom==0){

                                        uno=routers(nom_router,conectad_router,preci_router);

                                    }

                                    else if(num_nom==1){

                                        dos=routers(nom_router,conectad_router,preci_router);

                                    }

                                    else if(num_nom==2){

                                        tres=routers(nom_router,conectad_router,preci_router);

                                    }

                                    else if(num_nom==3){

                                        cuatro=routers(nom_router,conectad_router,preci_router);
                                    }

                                    else if(num_nom==4){

                                        cinco=routers(nom_router,conectad_router,preci_router);

                                    }
                                    else if(num_nom==5)
                                    {
                                        seis=routers(nom_router,conectad_router,preci_router);
                                    }
                                    else{

                                        siete=routers(nom_router,conectad_router,preci_router);

                                    }

                                    cout<<"Pulse la tecla 'Enter' para continuar"<<endl;
                                    cin.get();

                                }

                                break;
                                case 2:  //Eliminar router
                                {
                                    int posi_elim=topologia.modificar(), a_correr=(topologia.cant_routers_red())-posi_elim;

                                    for(int i=posi_elim;i<(posi_elim+a_correr+1);i++){
                                        if(i==0){

                                            uno=dos;

                                        }

                                        else if(i==1){

                                            dos=tres;

                                        }

                                        else if(i==2){

                                            tres=cuatro;

                                        }

                                        else if(i==3){

                                            cuatro=cinco;

                                        }

                                        else if(i==4)
                                        {
                                            cinco=seis;
                                        }
                                        else if(i==5){

                                            seis=siete;

                                        }

                                        else{

                                            siete.~routers();
                                            routers siete;

                                        }

                                    }

                                    cout<<"Pulse la tecla 'Enter' para continuar"<<endl;
                                    cin.get();

                                }

                                break;
                                case 3: //volver
                                {
                                    cout<<"volviendo..."<<endl;
                                }
                                break;

                            }

                        }
                        break;

                        case 3: //menu principal
                        {
                            preguntar=false;
                            for (int i=0;i<=50;i++){

                                cout<<endl;

                            }

                        }

                        break;

                    }

                }

            }

            break;
            //------------------------------------------------------------------------------------------------------------------
            case 2: //Crear red agregando o eliminando enrutadores o conexiones (maximo de 7 enrutadores)
            {

                routers uno,dos,tres,cuatro,cinco,seis,siete;
                red topologia= red();
                bool preguntar=true;

                while (preguntar==true){

                    for (int i=0;i<=50;i++){

                        cout<<endl;

                    }

                    int elec;
                    cout<<"A continuacion indique que desea hacer con la red: "<<endl<<endl;
                    cout<<"Ingrese 1 para hacer una consulta sobre rutas y costos."<<endl;
                    cout<<"Ingrese 2 para agregar o eliminar una conexion o enrutador"<<endl;
                    cout<<"Ingrese 3 para volver al menu principal"<<endl<<endl;
                    cout<<"Opcion: ";
                    cin>>elec;

                    while((elec<1) || (elec>3)){

                        cout<<"Opcion invalida."<<endl;
                        cout<<"Ingrese la opcion deseada: ";
                        cin>>elec;

                    }

                    switch (elec){

                        case 1: //consultas
                        {
                            for (int i=0;i<=50;i++){

                                cout<<endl;

                            }

                            char ori, dest;
                            bool funciona;
                            funciona = true; //topologia.verificar(conexiones); //se verifica la validez de la red a este momento

                            if (funciona==false){

                                cout<<"La red no cumple los requisitos para hacer una consulta, agregue mas routers y conexiones!"<<endl<<endl;
                                cout<<"Pulse la tecla 'Enter' para continuar"<<endl;
                                cin.get();

                            }

                            else{

                                cout<<"Ingrese el enrutador origen: ";cin>>ori;
                                cout<<"Ingrese el enrutador destino: ";cin>>dest;
                                cout<<endl;
                                topologia.ruta_coste(ori,dest);

                            }

                        }

                        break;
                        case 2: //modificaciones
                        {
                            for (int i=0;i<=50;i++){

                                cout<<endl;

                            }

                            int opci;
                            cout<<"Ingrese 1 para agregar un enrutador"<<endl;
                            cout<<"Ingrese 2 para eliminar un enrutador"<<endl;
                            cout<<"Ingrese 3 para volver"<<endl;
                            cout<<"Digite su opcion: ";
                            cin>>opci;

                            while((opci<1) || (opci>3)){

                                cout<<"Opcion invalida."<<endl;
                                cout<<"Digite su opcion: ";
                                cin>>opci;

                            }

                            switch (opci){

                                case 1: //Agregar router
                                {

                                    char nom_router, conectad_router[7]={0};
                                    int preci_router[7]={0};
                                    topologia.modificar(&nom_router,conectad_router,preci_router);
                                    int num_nom=topologia.cant_routers_red();

                                    if(num_nom==0){

                                        uno=routers(nom_router,conectad_router,preci_router);

                                    }

                                    else if(num_nom==1){

                                        dos=routers(nom_router,conectad_router,preci_router);

                                    }

                                    else if(num_nom==2){

                                        tres=routers(nom_router,conectad_router,preci_router);

                                    }

                                    else if(num_nom==3){

                                        cuatro=routers(nom_router,conectad_router,preci_router);

                                    }

                                    else if(num_nom==4){

                                        cinco=routers(nom_router,conectad_router,preci_router);

                                    }

                                    else if(num_nom==5){

                                        seis=routers(nom_router,conectad_router,preci_router);

                                    }

                                    else{

                                        siete=routers(nom_router,conectad_router,preci_router);

                                    }

                                    cout<<"Pulse la tecla 'Enter' para continuar"<<endl;
                                    cin.get();

                                }
                                break;
                                case 2:  //Eliminar router
                                {
                                    int posi_elim=topologia.modificar(), a_correr=(topologia.cant_routers_red())-posi_elim;
                                    for(int i=posi_elim;i<(posi_elim+a_correr+1);i++){

                                        if(i==0){

                                            uno=dos;

                                        }

                                        else if(i==1){

                                            dos=tres;

                                        }

                                        else if(i==2){

                                            tres=cuatro;

                                        }

                                        else if(i==3){

                                            cuatro=cinco;

                                        }

                                        else if(i==4){

                                            cinco=seis;

                                        }

                                        else if(i==5){

                                            seis=siete;

                                        }

                                        else{

                                            siete.~routers();
                                            routers siete;

                                        }

                                    }

                                    cout<<"Pulse la tecla 'Enter' para continuar"<<endl;
                                    cin.get();

                                }
                                break;
                                case 3: //volver
                                {
                                    cout<<"volviendo..."<<endl;

                                }

                                break;

                            }

                        }

                        break;
                        case 3: //menu principal
                        {
                            preguntar=false;
                            for (int i=0;i<=50;i++){

                                cout<<endl;

                            }

                        }

                        break;

                    }

                }

            }

            break;
            //------------------------------------------------------------------------------------------------------------------
            case 3: //Salir del programa
            {
                terminar=true;
            }
            break;

        }

    }

}
