#ifndef MENU_H
#define MENU_H


class Menu{
    private:
        Controlador controlador = Controlador();
        bool UltimaVezInt = false;

        int obtenerInt() {
            int retorno;
            cin >> retorno;
            while (!cin.good()){
                cout << "ERROR VUELVA A INTENTARLO" << endl;
                cin.clear();
                cin.ignore(INT_MAX,'\n');
                cin >> retorno;
            }
            UltimaVezInt = true;
            return retorno;
        }

        string obtenerString(){
            if(UltimaVezInt){
                cin.ignore(INT_MAX,'\n');
                UltimaVezInt = false;
            }
            string retorno;
            getline(cin,retorno);
            cin.clear();
            return retorno;
        }

    public:
        Menu(){}
        ~Menu(){}

        void menuPrincipal(){
            int menuNumero = -1;
            do{
                cout<<endl<<"--Menu principal--"<<endl;
                cout<<"1 -Estado de las colas."<<endl<<"2 -Solicitar Tiquete."<<endl;
                cout<<"3 -Atender."<<endl<<"4 -Andministracion."<<endl;
                cout<<"5 -Estadisticas."<<endl<<"0 -Salir."<<endl;
                cout<<endl<<"Digite el numero con la opcion deseada: ";
                menuNumero = obtenerInt();
                cout<< endl;
                switch(menuNumero){
                    case 1:
                        cout<<controlador.estadoColas()<<endl;
                        break;
                    case 2:
                        agregarTiqueteControlador();
                        break;
                    case 3:
                        controladorAtender();
                        break;
                    case 4:
                        menuAdministracion();
                        break;
                    case 5:
                        menuEstadisticas();
                        break;
                    case 0:
                        break;
                    default:
                        cout<<"La opcion no esta dentro de las permitidas"<<endl;
                        break;
                }
            }while(menuNumero!=0);
            cout<<"Hasta luego!";
        }

        void agregarTiqueteControlador(){
            cout<<"--Agregar  tiquete--"<<endl;
            string servicios = controlador.mostrarServicios();
            if(servicios=="--Lista de servicios-- \n"){
                cout<<"No hay servicios disponibles"<<endl;
                return;
            }
            cout<<servicios<<endl;
            cout<<"Digite el codigo del servicio que va a utilizar: ";
            servicios = obtenerString();
            bool tipo = false;
            cout<<"Coloque '1' para cliente preferencial o '0' para normal: ";
            tipo = obtenerInt();
            bool retorno = controlador.agregarTiquete(tipo, servicios);
            cout<<endl;
            if(retorno){
                cout<<"El tiquete se creo correctamente."<<endl;
            }else{
                cout<<"No existe este servicio."<<endl;
            }
        }

        void controladorAtender(){
            cout<<"--Atender--"<<endl;
            string tipoVentana = "";
            int numVentanilla;
            cout<<"Digite el codigo de la Ventana a atender: ";
            tipoVentana = obtenerString();
            cout<<"Digite el numero de la ventanilla asignada: ";
            numVentanilla = obtenerInt();
            cout<<endl<<controlador.atender(tipoVentana, numVentanilla)<<endl;
        }

        void menuAdministracion(){
            int menuNumero = -1;
            do{
                    cout<<endl<<"--Menu Administracion--"<<endl;
                    cout<<"1 -Ventanas."<<endl<<"2 -Servicios."<<endl<<"0 -Regresar."<<endl;
                    cout<<endl<<"Digite el numero con la opcion deseada: ";
                    menuNumero = obtenerInt();
                    cout<< endl;
                    switch(menuNumero){
                        case 1:
                            menuAdministracionVentanas();
                            break;
                        case 2:
                            menuAdministracionServicios();
                            break;
                        case 0:
                            break;
                        default:
                            cout<<"La opcion no esta dentro de las permitidas"<<endl;
                            break;
                    }
            }while(menuNumero!=0);
        }

        void menuAdministracionVentanas(){
            int menuNumero = -1;
            do{
                cout<<endl<<"--Menu Ventanas--"<<endl;
                    cout<<"1 -Agregar ventana."<<endl<<"2 -Eliminar ventana."<<endl<<"0 -Regresar."<<endl;
                    cout<<endl<<"Digite el numero con la opcion deseada: ";
                    menuNumero = obtenerInt();
                    cout<< endl;
                    switch(menuNumero){
                        case 1:
                            agrearVentanaControlador();
                            break;
                        case 2:
                            eliminarVentanaContrlador();
                            break;
                        case 0:
                            break;
                        default:
                            cout<<"La opcion no esta dentro de las permitidas"<<endl;
                            break;
                    }
            }while(menuNumero!=0);
        }

        void agrearVentanaControlador(){
            cout<<"--Agregar ventana--"<<endl;
            string codigo = "";
            string nombre = "";
            int cantidad;
            cout<<"Digite el codigo de la Ventana: ";
            codigo = obtenerString();
            cout<<"Digite el nombre de la Ventana: ";
            nombre = obtenerString();
            cout<<"Digite la cantidad de ventanillas para la ventana: ";
            cantidad = obtenerInt();
            bool retorno = controlador.agregarVentana(codigo,nombre,cantidad);
            cout<<endl;
            if(retorno){
                cout<<"La ventana se agrego correctamente."<<endl;
            }else{
                cout<<"La ventana ya existe."<<endl;
            }
        }

        void eliminarVentanaContrlador(){
            cout<<"--Eliminar ventana--"<<endl;
            string codigo = "";
            cout<<"Digite el codigo de la Ventana: ";
            codigo = obtenerString();
            cout<<endl;
            bool retorno = controlador.eliminarVentana(codigo);
            if(retorno){
                cout<<"La ventana se elimino correctamente."<<endl;
            }else{
                cout<<"No se encontro la ventana."<<endl;
            }
        }

        void menuAdministracionServicios(){
            int menuNumero = -1;
            do{
                cout<<endl<<"--Menu Servicios--"<<endl;
                    cout<<"1 -Agregar servicio."<<endl<<"2 -Eliminar servicio."<<endl;
                    cout<<"3 -Mover servicio."<<endl<<"0 -Regresar."<<endl;
                    cout<<endl<<"Digite el numero con la opcion deseada: ";
                    menuNumero = obtenerInt();
                    cout<< endl;
                    switch(menuNumero){
                        case 1:
                            agrearServicioControlador();
                            break;
                        case 2:
                            eliminarServicioContrlador();
                            break;
                        case 3:
                            moverServicioControlador();
                            break;
                        case 0:
                            break;
                        default:
                            cout<<"La opcion no esta dentro de las permitidas"<<endl;
                            break;
                    }
            }while(menuNumero!=0);
        }

        void agrearServicioControlador(){
            cout<<"--Agregar servicio--"<<endl;
            string id = "";
            string descripcion = "";
            string nombre = "";
            string codigoVentana;
            cout<<"Digite el id del servicio: ";
            id = obtenerString();
            cout<<"Digite el descripcion del servicio: ";
            descripcion = obtenerString();
            cout<<"Digite el nombre del servicio: ";
            nombre = obtenerString();
            cout<<"Digite el codigo de la Ventana asignada: ";
            codigoVentana = obtenerString();
            bool retorno = controlador.agregarServicio(descripcion,id,nombre,codigoVentana);
            cout<<endl;
            if(retorno){
                cout<<"El servicio se agrego correctamente."<<endl;
            }else{
                cout<<"El servicio ya existe o la ventana no existe."<<endl;
            }
        }

        void eliminarServicioContrlador(){
            cout<<"--Eliminar servicio--"<<endl;
            string codigo = "";
            cout<<"Digite el codigo del servicio: ";
            codigo = obtenerString();
            cout<<endl;
            bool retorno = controlador.eliminarServicio(codigo);
            if(retorno){
                cout<<"El servicio se elimino correctamente."<<endl;
            }else{
                cout<<"No se encontro el servicio."<<endl;
            }
        }

        void moverServicioControlador(){
            cout<<"--Mover servicio--"<<endl;
            string codigo = "";
            int pos;
            cout<<"Digite el codigo del servicio: ";
            codigo = obtenerString();
            cout<<"Digite la nueva posicion del servicio: ";
            pos = obtenerInt();
            cout<<endl;
            bool retorno = controlador.moverServicio(codigo,pos);
            if(retorno){
                cout<<"La ventana se elimino correctamente."<<endl;
            }else{
                cout<<"No se encontro la ventana."<<endl;
            }
        }

        void menuEstadisticas(){
            int menuNumero = -1;
            do{
                cout<<endl<<"--Menu estadisticas--"<<endl;
                cout<<"1 -Tiempo promedio de espera."<<endl<<"2 -Tiquetes dispensados por ventanilla."<<endl;
                cout<<"3 -Tiquetes atendidos por ventanilla."<<endl<<"4 -Tiquetes dispensados por servicio."<<endl;
                cout<<"5 -Tiquetes preferenciales."<<endl<<"0 -Salir."<<endl;
                cout<<endl<<"Digite el numero con la opcion deseada: ";
                menuNumero = obtenerInt();
                cout<< endl;
                switch(menuNumero){
                    case 1:
                        controlador.tiempoPromedio();
                        break;
                    case 2:
                        controlador.dispensadosVentana();
                        break;
                    case 3:
                        controlador.atendidosVentana();
                        break;
                    case 4:
                        controlador.dispensadosServicio();
                        break;
                    case 5:
                        controlador.dispensadosPreferenciales();
                        break;
                    case 0:
                        break;
                    default:
                        cout<<"La opcion no esta dentro de las permitidas"<<endl;
                        break;
                }
            }while(menuNumero!=0);
        }
};

#endif // MENU_H
