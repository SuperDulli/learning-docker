#include <Server.hpp>

Server::Server()
{
    std::cout << "Server Default Constructor" << std::endl;
}

Server::~Server()
{
    std::cout << "Server Destructor" << std::endl;
}

Server::Server(int port) : m_port(port), m_address_len(sizeof(m_address))
{
    std::cout << "Server Constructor" << std::endl;
    m_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (!m_fd)
        throw std::logic_error("socket call failed"); 
    std::memset((char *) &m_address, 0, sizeof(m_address));
    m_address.sin_family = AF_INET;
    m_address.sin_addr.s_addr = htonl(INADDR_ANY);
    m_address.sin_port = htons(m_port);
    if (bind(m_fd, reinterpret_cast<struct sockaddr *>(&m_address), sizeof(m_address)) < 0)
        throw std::logic_error("bind failed");
    if (listen(m_fd, 10) < 0)
        throw std::logic_error("listen failed");

}

void Server::loop()
{
    while (1)
    {
        std::cout << "Wait for incoming connection" << std::endl;
        m_socket = accept(m_fd, reinterpret_cast<struct sockaddr *>(&m_address), &m_address_len);
        if (m_socket < 0)
            throw std::logic_error("accept failed");
        // TODO: replace with recv and send
        char buffer[30000] = {0};
        m_bytes_read = read( m_socket , buffer, 30000);
        std::cout << buffer << std::endl;
        const char *response = "Hello World!";
        write(m_socket, response, std::strlen(response));
        close(m_socket); // close with other function
    }
    
}