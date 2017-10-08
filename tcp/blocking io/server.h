//
// Created by puyangsky on 17/10/1.
//

#include <unistd.h>
#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>

#ifndef LEARNINGCPP_SERVER_H
#define LEARNINGCPP_SERVER_H

#define MAXSIZE 1024

class server {
private:
    int socket_fd, accept_fd;
    sockaddr_in myserver;
    sockaddr_in remote_addr;

public:
    server(int listen_port);
    int recv_msg();
};

#endif //LEARNINGCPP_SERVER_H
