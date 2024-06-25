//
// Created by stone on 2024-06-25.
//

#include "Game.h"

#include <stdexcept>
#include <iostream>

int main() {
    try {
        Game game;
        game.run();
    } catch (std::exception& e) {
        std::cout << "\nException: " << e.what() << std::endl;
    }
}