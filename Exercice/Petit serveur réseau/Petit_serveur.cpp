#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <thread>
#include <map>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

using namespace std;

class Client {
private:
    int socketFD;
    string pseudo;
    bool connected;

public:
    // Constructor
    Client(int fd, const string& name, bool isConnected = true)
        : socketFD(fd), pseudo(name), connected(isConnected) {}

    // Getter for socketFD
    int getSocketFD() const {
        return socketFD;
    }

    // Getter for pseudo
    string getPseudo() const {
        return pseudo;
    }

    // Getter for connected status
    bool isConnected() const {
        return connected;
    }
    
    // Setter for connected status
    void setConnected(bool status) {
        connected = status;
    }

    void envoyerMessage(const string& msg)
    {
        try {
            if (send(socketFD, msg.c_str(), msg.size(), 0) <= 0) {
                throw runtime_error("Impossible d'envoyer un message");
            }
        }
        catch (...) {
            connected = false;
        }
    }

    string recevoirMessage()
    {
        char buffer[1024];
        int bytes = recv(socketFD, buffer, sizeof(buffer) - 1, 0);

        if (bytes <= 0) {
            return "";
        }

        buffer[bytes] = '\0';
        return string(buffer);
    }

    void fermerConnexion()
    {
        connected = false;
        cout << pseudo << " has disconnected." << endl;
    }
};

class Serveur {
private:
    int socketServer;
    map<int, shared_ptr<Client>> clients;
    int port;

public:
    // Constructor
    Serveur(int p) : port(p), socketServer(-1) {};

    const map<int, shared_ptr<Client>>& getClients() const {
        return clients;
    }

    void demarrer()
    {
        socketServer = socket(AF_INET, SOCK_STREAM, 0);
        if (socketServer < 0) {
            perror("Erreur socket()");
            return;
        }
        
        sockaddr_in setupAddress{};
        setupAddress.sin_family = AF_INET;
        setupAddress.sin_addr.s_addr = INADDR_ANY;
        setupAddress.sin_port = htons(port);
        
        if(bind(socketServer, (struct sockaddr*)&setupAddress, sizeof(setupAddress)) < 0) {
            perror("Erreur bind()");
            close(socketServer);
            return;
        }
        if(listen(socketServer, 5) < 0) {
            perror("Erreur listen()");
            close(socketServer);
            return;
        }
        
        cout << "Server started on port " << port << "." << endl;
}


    void accepterClient()
    {
        sockaddr_in clientAddress{};
        socklen_t clientLen = sizeof(clientAddress);
        int clientFD = accept(socketServer, (struct sockaddr*)&clientAddress, &clientLen);

         if (clientFD < 0) {
            perror("Erreur accept()");
            return;
        }
        
        string pseudo = "Client" + to_string(clientFD);
        
        auto client = make_shared<Client>(clientFD, pseudo, true);
        clients[clientFD] = client;

        thread t (&Serveur::handleClient, this, clientFD);
        t.detach();
    }


    void broadcast(const string& msg, int senderFD)
    {
        cout << "[SERVER BROADCAST] " << msg << endl;

        for (const auto& [fd, client] : clients) {
            if (fd != senderFD && client->isConnected()) {
                client->envoyerMessage(msg);
            }
        }
    }

    void handleClient(int clientFD)
    {
        auto client = clients[clientFD];
        try {
            while (client->isConnected()) 
            {
                string msg = client->recevoirMessage();

                if (msg.empty()) {
                    cout << client->getPseudo() << " s'est déconnecté." << endl;
                    client->setConnected(false);
                    retirerClient(clientFD);
                    return;
                }
                
                cout << "[" << client->getPseudo() << "] " << msg << endl;
                
                broadcast(msg, clientFD);
            }
        }
        catch (const exception& e) {
            cout << "[ERREUR] Exception dans le thread client : " << e.what() << endl;
            retirerClient(clientFD);
        }
    }


    void retirerClient(int clientFD)
    {
        if (clients.count(clientFD)) {
            cout << "[X] Suppression du client : " << clients[clientFD]->getPseudo() << endl;
            close(clientFD);
            clients.erase(clientFD);
        }
    }



    void arreter()
    {
        cout << "Server stopped." << endl;

        for (auto& [fd, client] : clients) {
            if (client->isConnected()) {
                client->fermerConnexion();
            }
        }
    }
};

int main()
{
    // Création et démarrage du serveur
    Serveur serveur(8080);
    serveur.demarrer();

    cout << "Serveur en attente de clients..." << endl;

    // Boucle principale pour accepter les clients
    while (true) 
    {
        // Accepte un nouveau client
        serveur.accepterClient();
        // Chaque client sera géré dans son propre thread détaché
        // Pas besoin de join() ici car le thread s'auto-gère
    }

    // Arrêt du serveur (jamais atteint ici sauf si tu ajoutes une condition)
    serveur.arreter();

    return 0;
}
