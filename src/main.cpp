//
// Created by stone on 2024-06-25.
//

#include "include/Application.h"

#include <stdexcept>
#include <iostream>

int main() {
    try {
        Application app;
        app.run();
    } catch (std::exception& e) {
        std::cout << "\nException: " << e.what() << std::endl;
    }
}