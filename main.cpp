# include "Server.hpp"

int main ()
{
    Server& network = Server::getNetWork (
        "MendeKK200-0",
        8080,
        "001"
    );

    network.start ();
    network.run ();

    std::cout << "hello\n";
}