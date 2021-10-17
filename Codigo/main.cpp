#include <iostream>
#include "Controlador.h"

using namespace std;

int main()
{
    //cout << "MUY BUENAS AL MEJOR CURSO DE ESTE PLANETA!!!" << endl;
    Controlador controlador = Controlador();
    int menuNumero = -1;
    do{
        cout<<endl<<"--Menu principal--"<<endl;
        cout<<"1 -Estado de las colas."<<endl<<"2 -Solicitar Tiquete."<<endl;
        cout<<"3 -Atender."<<endl<<"4 -Andministracion."<<endl;
        cout<<"5 -Estadisticas."<<endl<<"0 -Salir."<<endl;
        cout<<"Digite el numero con la opcion deseada: "<<endl;
        cin>>menuNumero;
        switch(menuNumero){
            case 1:
                cout<<controlador.estadoColas()<<endl;
                break;
            case 2:
                break;
            case 3:
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
    cout<<"Hasta luego!";
    return 0;
}
