#include <iostream>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
//#include <allegro.h>
//#include <allegro_native_dialog.h>

using namespace std;

char *ip = "192.168.1.2";
char *ipHA = "192.168.1.2";
int client;
int portNum = 1500;
int portNumHA = 1501;
bool server = true;

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

bool rm_init(int portNum, int portNumHA, char *ip, char *ipHA) {
    server = conectarServer();
    cout << server << endl;
    return server;
}

void sendData() {
    string valor;
    string llave;
    string tamano;
    string ejecucion = "i-";
    int bufsize = 1024;
    char buffer[bufsize];
    while (true) {
        cin >> llave;
        ejecucion += llave;
        ejecucion += "-";
        cin >> valor;
        ejecucion += valor;
        ejecucion += "-";
        cin >> tamano;
        ejecucion += tamano;
        strcpy(buffer, ejecucion.c_str());
        send(client, buffer, bufsize, 0);
        cout << buffer << endl;
    }
}

void deleteData() {
    string valor;
    string llave;
    string tamano;
    string ejecucion = "e-";
    int bufsize = 1024;
    char buffer[bufsize];
    while (true) {
        cin >> llave;
        ejecucion += llave;
        ejecucion += "-";
        cin >> valor;
        ejecucion += valor;
        ejecucion += "-";
        cin >> tamano;
        ejecucion += tamano;
        strcpy(buffer, ejecucion.c_str());
        send(client, buffer, bufsize, 0);
        cout << buffer << endl;
    }
}

void searchData() {
    string valor;
    string llave;
    string tamano;
    string ejecucion = "b-";
    int bufsize = 1024;
    char buffer[bufsize];
    while (true) {
        cin >> llave;
        ejecucion += llave;
        ejecucion += "-";
        cin >> valor;
        ejecucion += valor;
        ejecucion += "-";
        cin >> tamano;
        ejecucion += tamano;
        strcpy(buffer, ejecucion.c_str());
        send(client, buffer, bufsize, 0);
        cout << buffer << endl;
    }
}

struct rmRef_h {
    int referencias;
    int dato;
    int bytes;
    string key;
    struct rmRef_h *siguiente;
};

class operadores {
private:
    char *key;
public:
    operadores(char *llave) {
        this->key = llave;
    }

    int operator=(int var) {
        char dato_concat[500];
        dato_concat[0] = NULL;
        char *buffer = (char *) malloc(1024 * sizeof(char));

        strcat(dato_concat, "b");
        strcat(dato_concat, "-");
        strcat(dato_concat, key);

        strcpy(buffer, dato_concat);

        send(client, buffer, 1024, 0);

        recv(client, buffer, 1024, 0);
        int num = atoi(buffer);
        free(buffer);
        return num;
    }

    bool operator==(char *llave) {
        char dato_concat[500];
        dato_concat[0] = NULL;
        char *buffer = (char *) malloc(1024 * sizeof(char));

        strcat(dato_concat, "c");
        strcat(dato_concat, "-");
        strcat(dato_concat, key);

        strcpy(buffer, dato_concat);

        send(client, buffer, 1024, 0);

        recv(client, buffer, 1024, 0);

        if (strcmp(buffer, llave) == 0) {
            free(buffer);
            return true;
        } else {
            free(buffer);
            return false;
        }
    }

    bool operator!=(char *llave) {
        char dato_concat[500];
        dato_concat[0] = NULL;
        char *buffer = (char *) malloc(1024 * sizeof(char));

        strcat(dato_concat, "c");
        strcat(dato_concat, "-");
        strcat(dato_concat, key);

        strcpy(buffer, dato_concat);

        send(client, buffer, 1024, 0);

        recv(client, buffer, 1024, 0);

        if (strcmp(buffer, llave) == 0) {
            free(buffer);
            return false;
        } else {
            free(buffer);
            return true;
        }
    }
};

int main() {
    rm_init(portNum, portNumHA, ip, ipHA);
    //sendData();
    searchData();
    //deleteData();
}
