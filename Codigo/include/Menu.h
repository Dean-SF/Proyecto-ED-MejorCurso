//Creado por: Esteban Perez Picado
//Fecha de creacion: 18/10/2021
//Ultima modificacion: 19 q/10/2021
//Modificado por: Deyan Sanabria Fallas
#ifndef MENU_H
#define MENU_H

/*
Crea la funcion del menu que maneja todos los metodos del crontolador
*/
class Menu{
    private:
        Controlador controlador = Controlador();
        bool UltimaVezInt = false;

        /*
        Metodo de entrada que pregunta a el usuario un numero hasta que lo introduzca,
        si este no es un numero pregunta por el de nuevo
        */
        int obtenerInt() {
            int retorno;
            cin >> retorno;
            while (!cin.good()){ // Verifica que la operacion se hizo de forma exitosa
                cout << "ERROR: SOLO SE PERMITEN NUMEROS" << endl;
                cin.clear();                // limpia la bandera de error
                cin.ignore(INT_MAX,'\n');   // limpia de caracteres la entrada
                cin >> retorno;
            }
            UltimaVezInt = true; // Cuando do se usa CIN para un numero y despues
            return retorno;      // para el getline, hay que limpiar con ignore,
        }                        // para ello esta el booleano

        /*
        Metodo de entrada para leer un string del usuario
        */
        string obtenerString(){
            if(UltimaVezInt){ // Si se leyo un numero la ultima vez
                cin.ignore(INT_MAX,'\n'); // se limpia el input buffer
                UltimaVezInt = false; // y se de vuelve el booleano a falso
            }
            string retorno;
            getline(cin,retorno);
            cin.clear();
            return retorno;
        }

    public:
        /*
        Contructores y destructor default
        */
        Menu(){}
        ~Menu(){}

        /*
        Metodo de menu principal donde se ven todas las caracteristicas del programa.
        */
        void menuPrincipal(){
            int menuNumero = -1;
            do{
                cout<<endl<<"--Menu principal--"<<endl;
                cout<<"1 -Estado de las colas."<<endl<<"2 -Solicitar Tiquete."<<endl;
                cout<<"3 -Atender."<<endl<<"4 -Administracion."<<endl;
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

        /*
        Metodo que pide al usuarios los datos para agregar un tiquete.
        */
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
            int tipo = 0;
            do {
                cout<<"Coloque '1' para cliente preferencial o '0' para normal: ";
                tipo = obtenerInt();
            } while (tipo != 0 && tipo != 1);

            bool retorno = controlador.agregarTiquete(tipo, servicios);
            cout<<endl;
            if(retorno){
                cout<<"El tiquete se creo correctamente."<<endl;
            }else{
                cout<<"No existe este servicio."<<endl;
            }
        }

        /*
        Metodo que pide al usuario los datos para atender un tiquete
        */
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

        /*
        Un submenu con las especificaciones para ventana y servicio
        */
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

        /*
        Menu para administrar las ventanas
        */
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

        /*
        Metodo que pide al usuarios los datos para agregar una nueva ventana.
        */
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
            if(cantidad <= 0) {
                cout<<"La ventana no se agrego. \nCantidad invalidad de ventanillas."<<endl;
                return;
            }

            bool retorno = controlador.agregarVentana(codigo,nombre,cantidad);
            cout<<endl;
            if(retorno){
                cout<<"La ventana se agrego correctamente."<<endl;
            }else{
                cout<<"La ventana ya existe."<<endl;
            }
        }

        /*
        Metodo que pide un codigo para eliminar la ventana asociada.
        */
        void eliminarVentanaContrlador(){
            cout<<"--Eliminar ventana--"<<endl;
            string codigo = "";
            cout<<"Digite el codigo de la Ventana: ";
            codigo = obtenerString();
            cout<<endl;
            int retorno = controlador.eliminarVentana(codigo);
            if(retorno == 1) {
                cout<<"La ventana se elimino correctamente."<<endl;
            }else if(retorno == 0) {
                cout<<"No se encontro la ventana."<<endl;
            }else if(retorno == -1) {
                cout<<"La ventana pertenece a un servicio."<<
                "\nHasta que la ventana no sea desocupada no puede eliminarse."<<endl;
            }
        }

        /*
        Menu para le manejo de los metodos para administrar los servicios.
        */
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

        /*
        Metodo que pide los datos para agregar un servicio.
        */
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

        /*
        Metodo que con el codigo del servicio lo elimina.
        */
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

        /*
        Metodo que pide el codigo de un servicio y una posicion para moverlo a esta
        */
        void moverServicioControlador(){
            cout<<"--Mover servicio--"<<endl;
            string codigo = "";
            int pos;
            cout<<"Digite el codigo del servicio: ";
            codigo = obtenerString();
            cout<<"Digite la nueva posicion del servicio: ";
            pos = obtenerInt();
            pos--;
            cout<<endl;
            if(controlador.getCantidadServicios() <= pos || 0 > pos) {
                cout<<"No existe esa posicion."<<endl;
                return;
            }
            bool retorno = controlador.moverServicio(codigo,pos);
            if(retorno){
                cout<<"El servicio se movio correctamente."<<endl;
                controlador.printServicios();
            }else{
                cout<<"No se encontro el servicio."<<endl;
            }
        }

        /*
        Menu para elegir las diferentes opciones de estadisticas del programa.
        */
        void menuEstadisticas(){
            int menuNumero = -1;
            do{
                cout<<endl<<"--Menu estadisticas--"<<endl;
                cout<<"1 -Tiempo promedio de espera."<<endl<<"2 -Tiquetes dispensados por ventanilla."<<endl;
                cout<<"3 -Tiquetes atendidos por ventanilla."<<endl<<"4 -Tiquetes dispensados por servicio."<<endl;
                cout<<"5 -Tiquetes preferenciales."<<endl<<"0 -Regresar."<<endl;
                cout<<endl<<"Digite el numero con la opcion deseada: ";
                menuNumero = obtenerInt();
                cout<< endl;
                switch(menuNumero){
                    case 1:
                        cout<<"--Tiempo promedio--"<<endl;
                        cout<<controlador.tiempoPromedio()<<endl;
                        break;
                    case 2:
                        cout<<"--Dispensados ventana--"<<endl;
                        cout<<controlador.dispensadosVentana()<<endl;
                        break;
                    case 3:
                        cout<<"--Atendidos ventanilla--"<<endl;
                        cout<<controlador.atendidosVentana()<<endl;
                        break;
                    case 4:
                        cout<<"--Dispensados servicios--"<<endl;
                        cout<<controlador.dispensadosServicio()<<endl;
                        break;
                    case 5:
                        cout<<"--Total dispensados preferenciales--"<<endl;
                        cout<<controlador.dispensadosPreferenciales()<<endl;
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
