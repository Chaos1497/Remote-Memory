
#include <iostream>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <ctype.h>

using namespace std;

char *ip = "192.168.1.2";
char *ipHA = "192.168.1.2";
int client;
int portNum = 1500;
int portNumHA = 1501;
bool server = true;
char elemento[80];

bool conectarServer() {
    int bufsize = 1024;
    char buffer[bufsize];

    struct sockaddr_in server_addr;
    struct sockaddr_in server_addr2;

    client = socket(AF_INET, SOCK_STREAM, 0);

    /* ---------- ESTABLISHING SOCKET CONNECTION ----------*/
    if (client < 0) {
        cout << "\nError establishing socket..." << endl;
        exit(1);
    }

    cout << "\n=> Socket client has been created..." << endl;

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(portNum);

    server_addr2.sin_family = AF_INET;
    server_addr2.sin_port = htons(portNumHA);

    /* ---------- CONNECTING THE SOCKET ---------- */
    if (connect(client, (struct sockaddr *) &server_addr, sizeof(server_addr)) == 0) {
        cout << "=> Connection to the server port number: " << portNum << endl;
        return true;
    } else {
        if (connect(client, (struct sockaddr *) &server_addr2, sizeof(server_addr2)) == 0) {
            cout << "=> Connection to the server port number: " << portNumHA << endl;
            return true;
        } else {
            return false;
        }
    }
}

/*Inicialización de rmlib*/
bool rm_init(int portNum, int portNumHA, char *ip, char *ipHA) {
    server = conectarServer();
    cout << server << endl;
    return server;
}

/*Encripta las entradas*/
void encriptarFrase (){
    int i;
    int largo = strlen(elemento);

    for(i=0 ; i<largo ; ++i){
        //convierte las minuscalas a mayuscula.
        *(elemento+i) = toupper(*(elemento+i));

        //descarta los digitos
        if(isalpha(*(elemento+i))){
            //verifica los casos especiales X-Y-Z
            if(*(elemento+i) > 87){
                *(elemento+i) = *(elemento+i)-23;
            }
            else{
                *(elemento+i) = *(elemento+i)+3;
            }
        }
    } cout<< elemento << endl;
    printf("La frase encriptada es: %s",elemento);
}

/*Envía la llave y el valor a los servidores para ser insertados en la memoria*/
void sendData() {
    string valor;
    string llave;
    string tamano;
    int bufsize = 1024;
    char buffer=NULL;
    *elemento=buffer;
    while (true) {
        char buffer[bufsize];
        string ejecucion = "i-";
        cin >> llave;
        ejecucion += llave;
        ejecucion += "-";
        cin >> valor;
        ejecucion += valor;
        strcpy(buffer, ejecucion.c_str());
        buffer;
        encriptarFrase();
        send(client, buffer, bufsize, 0);
        cout << buffer << endl;
    }
}

/*Envía la llave y el valor a los servidores para ser eliminados en la memoria*/
void deleteData() {
    string valor;
    string llave;
    string tamano;
    int bufsize = 1024;
    char buffer=NULL;
    *elemento=buffer;
    while (true) {
        char buffer[bufsize];
        string ejecucion = "e-";
        cin >> llave;
        ejecucion += llave;
        ejecucion += "-";
        cin >> valor;
        ejecucion += valor;
        strcpy(buffer, ejecucion.c_str());
        buffer;
        encriptarFrase();
        send(client, buffer, bufsize, 0);
        cout << buffer << endl;
    }
}

/*Envía la llave y el valor a los servidores para ser accesados en la memoria*/
void searchData() {
    string valor;
    string llave;
    string tamano;
    int bufsize = 1024;
    char buffer=NULL;
    *elemento=buffer;
    while (true) {
        char buffer[bufsize];
        string ejecucion = "b-";
        cin >> llave;
        ejecucion += llave;
        ejecucion += "-";
        cin >> valor;
        ejecucion += valor;
        strcpy(buffer, ejecucion.c_str());
        buffer;
        encriptarFrase();
        send(client, buffer, bufsize, 0);
        cout << buffer << endl;
    }
}

/*Sobrecarga de los operadores =, ==, !=*/
class sobrecargas{
private:
    char *key;
public:
    sobrecargas(char *llave) {
        this->key = llave;
    }

    int operator=(int var) {
        char dato[500];
        dato[0] = NULL;
        char *buffer = (char *) malloc(1024 * sizeof(char));

        strcat(dato, "b-");
        strcat(dato, key);
        strcpy(buffer, dato);
        send(client, buffer, 1024, 0);
        recv(client, buffer, 1024, 0);
        int num = atoi(buffer);
        free(buffer);
        return num;
    }

    bool operator==(char *llave) {
        char dato[500];
        dato[0] = NULL;
        char *buffer = (char *) malloc(1024 * sizeof(char));

        strcat(dato, "c-");
        strcat(dato, key);
        strcpy(buffer, dato);
        send(client, buffer, 1024, 0);
        recv(client, buffer, 1024, 0);
        if (strcmp(buffer, llave) == 0) {
            free(buffer);
            return true;
        } else{
            free(buffer);
            return false;
        }
    }

    bool operator!=(char *llave){
        char dato[500];
        dato[0] = NULL;
        char *buffer = (char *) malloc(1024 * sizeof(char));

        strcat(dato, "c-");
        strcat(dato, key);
        strcpy(buffer, dato);
        send(client, buffer, 1024, 0);
        recv(client, buffer, 1024, 0);
        if (strcmp(buffer, llave) == 0){
            free(buffer);
            return false;
        } else {
            free(buffer);
            return true;
        }
    }
};

int main(){
    rm_init(portNum, portNumHA, ip, ipHA);
    sendData();
    //searchData();
    //deleteData();
}