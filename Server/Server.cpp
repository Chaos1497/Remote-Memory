#include <iostream>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <thread>
#include "MemoryList.h"

using namespace std;

Tlista *lista = new Tlista();
Tlista *cache = new Tlista();

int portNum = 1500;
char *elemento;

/*Desencripta las entradas*/
void desencriptarFrase (){
    int i;
    int largo = strlen(elemento);

    for(i=0 ; i<largo ; ++i) {
        if(isalpha(*(elemento + i))) {
            if(*(elemento+i) < 68) {
                *(elemento+i)= *(elemento+i) + 23;
            }
            else {
                *(elemento+i)= *(elemento+i) - 3;
            }
        }
    }
    printf("\n""La frase desencriptada es: %s",elemento);
}

void cliente(){
    /* -------------- INITIALIZING VARIABLES -------------- */
    int client; // socket file descriptors
    int bufsize = 1024; // buffer size
    char buffer[bufsize]; // buffer to transmit
    char ip[] = "127.0.0.1"; // Server IP
    bool isExit = false; // var fo continue infinitly

    /* Structure describing an Internet socket address. */
    struct sockaddr_in server_addr;

    cout << "\n- Starting client..." << endl;

    /* ---------- ESTABLISHING SOCKET CONNECTION ----------*/

    client = socket(AF_INET, SOCK_STREAM, 0);

    if (client < 0) {
        cout << "\n-Error establishing socket..." << endl;
        exit(-1);
    }

    cout << "\n- Socket client has been created..." << endl;

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(portNum);

    inet_pton(AF_INET, ip, &server_addr.sin_addr);

    /* ---------- CONNECTING THE SOCKET ---------- */

    if (connect(client, (struct sockaddr *) &server_addr, sizeof(server_addr))
        < 0)
        cout << "- Connection to the server port number: " << portNum << endl;

    cout << "- Awaiting confirmation from the server..." << endl; //line 40

    // recive the welcome message from server
    recv(client, buffer, bufsize, 0);
    cout << buffer << endl;

    cout << "- Connection confirmed, you are good to go!" << endl;
    cout << "- Enter * to end the message" << endl;
    cout << "- Enter # to end the connection\n" << endl;
    // loop to send messages to server
    do {
        cout << "Message: ";
        do {
            // read from terminal
            cin >> buffer;
            // send to the server
            send(client, buffer, bufsize, 0);
            if (*buffer == '#') {
                // exit from the loop
                *buffer = '*';
                isExit = true;
            }
        } while (*buffer != '*');
        // wait the response from the server
        cout << "Server says: ";
        recv(client, buffer, bufsize, 0);
        // print the server message
        cout << buffer << endl;
    } while (!isExit);

    /* ---------------- CLOSE CALL ------------- */

    cout << "\nConnection terminated.\n";

    close(client);
}

//******************************************************************************************************************
//******************************************************************************************************************
//******************************************************************************************************************
//******************************************************************************************************************
//******************************************************************************************************************

thread conectarCliente() {
    int client, server;
    int portNum = 1500;
    bool isExit = false;
    int bufsize = 1024;
    char buffer[bufsize];

    struct sockaddr_in server_addr;
    socklen_t size;

    /* ---------- ESTABLISHING SOCKET CONNECTION ----------*/
    client = socket(AF_INET, SOCK_STREAM, 0);

    if (client < 0) {
        cout << "\nError establishing socket..." << endl;
        exit(1);
    }

    cout << "\n=> Socket server has been created..." << endl;

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htons(INADDR_ANY);
    server_addr.sin_port = htons(portNum);

    /* ---------- BINDING THE SOCKET ---------- */
    if ((bind(client, (struct sockaddr*)&server_addr,sizeof(server_addr))) < 0){
        cout << "=> Error binding connection, the socket has already been established..." << endl;
        //return -1;
    }

    size = sizeof(server_addr);
    cout << "=> Looking for clients..." << endl;

    /* ------------- LISTENING CALL ------------- */
    listen(client, 1);

    /* ------------- ACCEPTING CLIENTS  ------------- */
    int clientCount = 1;
    server = accept(client,(struct sockaddr *)&server_addr,&size);

    // first check if it is valid or not
    if (server < 0) {
        cout << "=> Error on accepting..." << endl;
    }

    while (server > 0){
        strcpy(buffer, "\nServer conectado\n");
        send(server, buffer, bufsize, 0);

        do{
            recv(server, buffer, bufsize, 0);

            //elemento=buffer;
            //desencriptarFrase();

            string var = buffer;
            //desencriptarFrase();

            string comienzo = var.substr(0,2);
            string llave = var.substr(2,6);

            string value = var.substr(9);
            int valor = stoi(value);

            int tamano = sizeof(valor);

            if(comienzo=="e-"){
                if (lista==NULL){
                    cout << "" <<endl;
                }else {
                    eliminarElemento(*lista, valor, llave, tamano);
                    strcpy(buffer, "Elemento eliminado");
                    send(server, buffer, bufsize, 0);
                    cout << "Elemento eliminado" << endl;
                    reportarLista(*lista);
                }
            }

            if(comienzo=="i-"){
                insertar(*lista,valor,llave,tamano);
                cout << "Key insertada" << endl;
                reportarLista(*lista);
                cout << tamano << endl;
                send(server, buffer, bufsize,0);
            }

            if(comienzo=="b-"){
                buscarElemento(*lista,valor,llave,tamano);
                strcpy(buffer,"Elemento existente, devuelto");
                send(server, buffer, bufsize,0);
            }

        }
        while (*buffer != '*');
        cout << "\nConexión terminada "<<endl;
        close(server);
        exit(1);
    }
}

//******************************************************************************************************************
//******************************************************************************************************************
//******************************************************************************************************************
//******************************************************************************************************************
//******************************************************************************************************************

thread conectarCliente2() {
    int client, server2;
    int portNumHA = 1501;
    bool isExit = false;
    int bufsize = 1024;
    char buffer[bufsize];

    struct sockaddr_in server2_addr;
    socklen_t size;

    /* ---------- ESTABLISHING SOCKET CONNECTION ----------*/
    client = socket(AF_INET, SOCK_STREAM, 0);

    if (client < 0) {
        cout << "\nError establishing socket..." << endl;
        exit(1);
    }

    cout << "\n=> Socket server has been created..." << endl;

    server2_addr.sin_family = AF_INET;
    server2_addr.sin_addr.s_addr = htons(INADDR_ANY);
    server2_addr.sin_port = htons(portNumHA);

    /* ---------- BINDING THE SOCKET ---------- */
    if ((bind(client, (struct sockaddr*)&server2_addr,sizeof(server2_addr))) < -1){
        cout << "=> Error binding connection, the socket has already been established..." << endl;
        //return -1;
    }

    size = sizeof(server2_addr);
    cout << "=> Looking for clients..." << endl;

    /* ------------- LISTENING CALL ------------- */
    listen(client, 1);

    /* ------------- ACCEPTING CLIENTS  ------------- */
    int clientCount = 1;
    server2 = accept(client,(struct sockaddr *)&server2_addr,&size);

    // first check if it is valid or not
    if (server2 < 0) {
        cout << "=> Error on accepting..." << endl;
    }

    while (server2 > 0){
        strcpy(buffer, "\nServer conectado\n");
        send(server2, buffer, bufsize, 0);

        do{
            recv(server2, buffer, bufsize, 0);

            string var = buffer;

            string comienzo = var.substr(0,2);
            string llave = var.substr(2,6);

            string value = var.substr(9,6);
            int valor = stoi(value);

            string size = var.substr(16,6);
            int tamano = stoi(size);

            if(comienzo=="e-"){
                eliminarElemento(*lista,valor,llave,tamano);
                strcpy(buffer,"Elemento eliminado");
                send(server2, buffer, bufsize,0);
                cout << "Elemento eliminado" << endl;

            }

            if(comienzo=="i-"){

                insertar(*lista,valor,llave,tamano);
                cout << "Key insertada" << endl;
                reportarLista(*lista);
                send(server2, buffer, bufsize,0);
            }

            if(comienzo=="b-"){
                buscarElemento(*lista,valor,llave,tamano);
                strcpy(buffer,"Elemento existente, devuelto");
                send(server2, buffer, bufsize,0);
                cout << "Si existe, key devuelta" << endl;
            }

        }
        while (*buffer != '*');
        cout << "\nConexión terminada "<<endl;
        close(server2);
        exit(1);
    }
}

//******************************************************************************************************************
//******************************************************************************************************************
//******************************************************************************************************************
//******************************************************************************************************************
//******************************************************************************************************************

int main(){
    thread s1(conectarCliente());
    thread s2(conectarCliente2());
    int activar_cliente=1;
    int activar_servidor2=1;
    while (true){
        cin>>activar_cliente;
        cin>>activar_servidor2;
        if (activar_cliente==1){
            cin>> portNum;
            thread s3(cliente);
            s3.join();
            activar_cliente=2;
        }
        s1.join();
        s2.join();
        this_thread::sleep_for(chrono::seconds(300));
        garbageCollector(*lista);
    }
}