//
// Created by puyangsky on 17/10/1.
//

#include "server.h"
#include <iostream>


int main(int argc, char* argv[]) {
    server s(atoi(argv[1]));
    s.recv_msg();
    return 0;
}