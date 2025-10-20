#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
constexpr int X = 0;
constexpr int Y = 1;
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