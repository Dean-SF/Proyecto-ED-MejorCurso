#include <iostream>
#include "Controlador.h"
#include "Menu.h"

using namespace std;

int main()
{
    Menu menu = Menu();
    menu.menuPrincipal();
    //cout << "MUY BUENAS AL MEJOR CURSO DE ESTE PLANETA!!!" << endl;
    Controlador controlador = Controlador();
    cout<<controlador.eliminarVentana("c1")<<endl;
    cout<<controlador.agregarVentana("C","Consulta",5)<<endl;
    cout<<controlador.agregarVentana("I","Iiiii",5)<<endl;
    cout<<controlador.agregarVentana("O","Horarios",5)<<endl;
    cout<<controlador.estadoColas()<<endl;

    cout<<controlador.agregarServicio("no se", "P", "Pagos", "C")<<endl;
    cout<<controlador.agregarServicio("no se", "A", "alala", "I")<<endl;
    cout<<controlador.agregarServicio("no se", "Z", "zzzz", "O")<<endl;
    cout<<controlador.mostrarServicios()<<endl;

    cout<<controlador.agregarTiquete(false , "P")<<endl;
    cout<<controlador.agregarTiquete(false , "P")<<endl;
    cout<<controlador.agregarTiquete(false , "P")<<endl;
    cout<<controlador.agregarTiquete(false , "P")<<endl;
    cout<<controlador.agregarTiquete(true , "P")<<endl;
    cout<<controlador.agregarTiquete(true , "P")<<endl;

    /*int menuNumero = -1;
    do{
        cout<<endl<<"--Menu principal--"<<endl;
        cout<<"1 -Estado de las colas."<<endl<<"2 -Solicitar Tiquete."<<endl;
        cout<<"3 -Atender."<<endl<<"4 -Andministracion."<<endl;
        cout<<"5 -Estadisticas."<<endl<<"0 -Salir."<<endl;
        cout<<"Digite el numero con la opcion deseada: "<<endl;
        cin>>menuNumero;
        cout<< endl;
        switch(menuNumero){
            case 1:
                cout<<controlador.estadoColas()<<endl;
                break;
            case 2:
                break;
            case 3:
                cout<<controlador.atender("A",1)<<endl;
                //Para ver que almenos funcione :D
                break;
            case 4:
                break;
            case 5:
                break;
            case 0:
                break;
            default:
                cout<<"La opcion no esta dentro de las permitidas"<<endl;
                break;
        }
    }while(menuNumero!=0);
    cout<<"Hasta luego!";*/
    return 0;
}
