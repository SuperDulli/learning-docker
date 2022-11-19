#include <Server.hpp>

int main()
{
    Server server(8080);
    server.loop();
}