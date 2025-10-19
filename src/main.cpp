#include <iostream>
#include <string>
#include <cmath>
#include "simulation.hpp"
#include "menu.hpp"

int main() {
    try {
        menu::mainMenu();
    } catch(std::exception& e) {
        std::cout << "Catched: " << e.what() << "\n";
    }
    return 0;
}