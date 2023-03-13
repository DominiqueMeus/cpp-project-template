#include <iostream>

#include "libname/hello_world.h"

int main(int argc, char** argp) {
    std::cout << "test\n";
    std::cout << libname::helloWorld() << "\n";
    return 0;
}
