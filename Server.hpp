#ifndef SERVER_HPP
# define SERVER_HPP

# include <iostream>

// inc para usar socket e recursos
# include <unistd.h>
# include <sys/socket.h>
# include <netinet/in.h>

// tipos
typedef std::string t_string;

// definicoes
# define BUF_SIZE 1024
# define MAX_CLIENT 5

class Server final {
    private :

        // conf do servidor
        // conf basica
        std::string _serverName;
        int _port;
        std::string _pswd;

        // conf tecnica
        int serverSocket;
        sockaddr_in serverAddress;

        int _clientSocket;

        char buffer [BUF_SIZE];

        Server (
            const t_string& serverName,
            int port,
            const t_string& pswd
        );
        
        Server () = delete;
        Server (const Server&) = delete;
        Server operator=(const Server&) = delete;

    public :


        static Server& getNetWork (
            const t_string& serverName,
            int port,
            const t_string& pswd
        );

        void start ();
        void run ();
        void handleClient ();

        void infoMsg (
            const t_string& serverName,
            int port,
            const t_string& pswd
        );
};

#endif