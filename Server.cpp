# include "Server.hpp"

Server::Server (
    const t_string& serverName,
    int port,
    const t_string& pswd
) : _serverName (serverName), _port (port), _pswd (pswd) {}

void Server::start ()
{
    infoMsg (
        _serverName,
        _port,
        _pswd
    );

    serverSocket = socket (AF_INET, SOCK_STREAM, 0);

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons (_port);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    bind (
        serverSocket,
        (struct sockaddr*)&serverAddress,
        sizeof (serverAddress)
    );

    listen (serverSocket, MAX_CLIENT);
}

void Server::run ()
{
    std::cout << "aguardando conexões..\n";

    while (true)
    {
        _clientSocket = accept (
            serverSocket,
            nullptr,
            nullptr
        );

        if (_clientSocket < 0)
            continue ;
        
        handleClient ();
        close (_clientSocket);
    }

}

void Server::handleClient() {
    int n;
    while ((n = read(_clientSocket, buffer, sizeof(buffer)-1)) > 0) {
        buffer[n] = '\0';
        std::cout << "Mensagem: " << buffer << std::endl;
    }
}

Server& Server::getNetWork (
    const t_string& serverName,
    int port,
    const t_string& pswd
)
{
    static Server NetWork (serverName, port, pswd);
    return NetWork;
}


void Server::infoMsg (
    const t_string& serverName,
    int port,
    const t_string& pswd
)
{
    std::cout << "server name: " << serverName << "\n";
    std::cout << "server port: " <<  port << "\n";
    std::cout << "server pass: " <<  pswd << "\n";
}