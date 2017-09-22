#include <iostream>
#include <sys/select.h>
#include <sys/poll.h>
#include "Test.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    fuck::Test *t;

    t->init();
    return 0;
}