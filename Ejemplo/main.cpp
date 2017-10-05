#include <iostream>
#include "/home/esteban/RMlib/rmlib.cpp"

using namespace std;

string llave;
string valor;

void menu(){
    cout<<"\n\t\tAdministrador de datos\n\n";
    cout<<"Aquí puede guardar, eliminar y buscar sus datos"<<endl;
    cout<<" 1. Guardar Dato"<<endl;
    cout<<" 2. Buscar Dato"<<endl;
    cout<<" 3. Eliminar Dato"<<endl;

    cout<<"\n Ingrese una opción: ";
}

void guardar(){
    cout<<"Ingrese la llave a guardar"<<endl;
    cout<<"Maximo 6 caracteres"<<endl;
    cout<<"Si faltan campos llénelos con espacios"<<endl;
    cin>>llave;
    cout<<"Ingrese el dato"<<endl;
    cin>>valor;
    while(true){
        sendData(llave,valor);
        break;
    }
    menu();
}

void buscar(){
    cout<<"Ingrese la llave a buscar"<<endl;
    cout<<"Maximo 6 caracteres"<<endl;
    cout<<"Si faltan campos llénelos con espacios"<<endl;
    cin>>llave;
    cout<<"Ingrese el dato"<<endl;
    cin>>valor;
    while(true){
        searchData(llave,valor);
        break;
    }
    menu();
}

void eliminar(){
    cout<<"Ingrese la llave a eliminar"<<endl;
    cout<<"Maximo 6 caracteres"<<endl;
    cout<<"Si faltan campos llénelos con espacios"<<endl;
    cin>>llave;
    cout<<"Ingrese el dato"<<endl;
    cin>>valor;
    while(true){
        deleteData(llave,valor);
        break;
    }
    menu();
}

int main() {
    rm_init(1500, 1501, "192.168.1.2", "192.168.1.2");
    int opcion;

    do{
        menu();
        cin>> opcion;

        switch(opcion){
            case 1:
                guardar();
                break;

            case 2:
                buscar();
                break;

            case 3:
                eliminar();
                break;
        }
    }while(opcion!=4);

    system("pause");
    return 0;
}
