#pragma once

#include <iostream>
#include <string>
#include <cstring> // memset
#include <sys/socket.h>
#include <netinet/in.h> // sockaddr_in
#include <unistd.h> // read, write -> use recv, send instead
#include <cstdlib>
#include <stdexcept>

class Server {
public:
    Server();
    Server(int port);
    ~Server();

    void loop();

private:
    int m_fd;
    int m_socket;
    int m_port;
    struct sockaddr_in m_address;
    socklen_t m_address_len;
    int m_bytes_read;
};