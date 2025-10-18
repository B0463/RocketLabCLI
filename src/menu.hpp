
namespace menu {
    void mainMenu() {
        std::string input;
        clear();
        std::cout << "==============================\n"
                  << "=        RocketLabCLI        =\n"
                  << "==============================\n"
                  << "= n - New Simulation         =\n"
                  << "= e - Exit                   =\n"
                  << "==============================\n"
                  << ">> ";
        std::getline(std::cin, input);
        std::cout << "\n";

        if(input == "e") return;
        if(input == "n") newMenu();
        else {
            std::cout << "wrong input\n";
        }
    }

    void newMenu() {
        std::string input;
        clear();
        std::cout << "==============================\n"
                  << "=        RocketLabCLI        =\n"
                  << "==============================\n"
                  << "= m - set mass: value        =\n"
                  << "= e - Exit                   =\n"
                  << "==============================\n"
                  << ">> ";
        std::getline(std::cin, input);
        std::cout << "\n";

        if(input == "e") return;
        if(input == "n") newMenu();
        else {
            std::cout << "wrong input\n";
        }
    }

    void clear() {
    std::cout << "\033[2J\033[H"; 
    }
}