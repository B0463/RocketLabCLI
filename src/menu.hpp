namespace menu {
    void mainMenu();
    void newSimulation();
    double massMenu();
    double engineThrustMenu();
    double gravityAccelerationMenu();
    double thrustTimeMenu();
    double angleOfAttackMenu();
    void resultMenu(
        double gravityAcceleration, double mass, double engineThrust, double thrustTime, double angleOfAttack,
        double accelerationTime, double inertiaTime, double fallTime, double totalTime, double maxHeight, double maxSpeed
    );
    void saveMenu(
        double gravityAcceleration, double mass, double engineThrust, double thrustTime, double angleOfAttack,
        double accelerationTime, double inertiaTime, double fallTime, double totalTime, double maxHeight, double maxSpeed
    );
    void clear();
    void printRow(const std::string& label, const std::string& value);
    void secureExit();
}

namespace menu {
    void mainMenu() {
        while(true) {
            std::string input;
            clear();
            std::cout << "\033[0;36m┌────────────────────────────┐\033[0m\n"
                      << "\033[0;36m│\033[0m        \033[1;31mRocketLabCLI\033[0m        \033[0;36m│\033[0m\n"
                      << "\033[0;36m├────────────────────────────┤\033[0m\n"
                      << "\033[0;36m│\033[0m \033[0;32mn\033[0m - New Simulation         \033[0;36m│\033[0m\n"
                      << "\033[0;36m│\033[0m                            \033[0;36m│\033[0m\n"
                      << "\033[0;36m│\033[0m \033[0;31me\033[0m - Exit                   \033[0;36m│\033[0m\n"
                      << "\033[0;36m└────────────────────────────┘\033[0m\n"
                      << "\033[1;32m ❯ \033[0m\033[0;37m";
            std::getline(std::cin, input);
            std::cout << "\033[0m\n";

            if(input == "e") {
                menu::secureExit();
            }
            else if(input == "n") {
                menu::newSimulation();
            }
            else {
                std::cout << "Error: wrong input \"" << input << "\"\n";
                std::cout << "Press enter...";
                std::cin.get();
                continue;
            }
        }
    }

    void newSimulation() {
        double gravityAcceleration = menu::gravityAccelerationMenu();
        double mass = menu::massMenu();
        double engineThrust = menu::engineThrustMenu();
        double thrustTime = menu::thrustTimeMenu();
        double angleOfAttack = menu::angleOfAttackMenu();
        
        double accelerationTime, inertiaTime, fallTime, totalTime;
        double maxHeight, maxSpeed;

        simulation::simulate(mass, engineThrust, gravityAcceleration, thrustTime, angleOfAttack,
            &accelerationTime, &inertiaTime, &fallTime, &totalTime, &maxHeight, &maxSpeed);

        menu::resultMenu(gravityAcceleration, mass, engineThrust, thrustTime, angleOfAttack,
            accelerationTime, inertiaTime, fallTime, totalTime, maxHeight, maxSpeed);

        return;
    }

    double massMenu() {
        double mass;
        while(true) {
            std::string input;
            clear();
            std::cout << "\033[0;36m┌────────────────────────────┐\033[0m\n"
                      << "\033[0;36m│\033[0m        \033[1;31mRocketLabCLI\033[0m        \033[0;36m│\033[0m\n"
                      << "\033[0;36m├────────────────────────────┤\033[0m\n"
                      << "\033[0;36m│\033[0m Enter the mass (g)         \033[0;36m│\033[0m\n"
                      << "\033[0;36m│\033[0m                            \033[0;36m│\033[0m\n"
                      << "\033[0;36m│\033[0m \033[0;31me\033[0m - Exit                   \033[0;36m│\033[0m\n"
                      << "\033[0;36m└────────────────────────────┘\033[0m\n"
                      << "\033[1;32m ❯ \033[0m\033[0;37m";
            std::getline(std::cin, input);
            std::cout << "\033[0m\n";

            if(input == "e") {
                menu::secureExit();
            }

            try {
                mass = std::stod(input) /1000; // convert g to Kg
            } catch(const std::exception& e) {
                std::cerr << "Error: " << e.what() << "\n";
                std::cout << "Press enter...";
                std::cin.get();
                continue;
            }
            break;
        }
        return mass;
    }

    double engineThrustMenu() {
        double engineThrust;
        while(true) {
            std::string input;
            clear();
            std::cout << "\033[0;36m┌──────────────────────────────┐\033[0m\n"
                      << "\033[0;36m│\033[0m         \033[1;31mRocketLabCLI\033[0m         \033[0;36m│\033[0m\n"
                      << "\033[0;36m├──────────────────────────────┤\033[0m\n"
                      << "\033[0;36m│\033[0m Enter the engine thrust (N)  \033[0;36m│\033[0m\n"
                      << "\033[0;36m│\033[0m                              \033[0;36m│\033[0m\n"
                      << "\033[0;36m│\033[0m \033[0;31me\033[0m - Exit                     \033[0;36m│\033[0m\n"
                      << "\033[0;36m└──────────────────────────────┘\033[0m\n"
                      << "\033[1;32m ❯ \033[0m\033[0;37m";
            std::getline(std::cin, input);
            std::cout << "\033[0m\n";

            if(input == "e") {
                menu::secureExit();
            }

            try {
                engineThrust = std::stod(input);
            } catch(const std::exception& e) {
                std::cerr << "Error: " << e.what() << "\n";
                std::cout << "Press enter...";
                std::cin.get();
                continue;
            }
            break;
        }
        return engineThrust;
    }

    double gravityAccelerationMenu() {
        double gravityAcceleration;
        while(true) {
            std::string input;
            clear();
            std::cout << "\033[0;36m┌────────────────────────────────────────┐\033[0m\n"
                      << "\033[0;36m│\033[0m              \033[1;31mRocketLabCLI\033[0m              \033[0;36m│\033[0m\n"
                      << "\033[0;36m├────────────────────────────────────────┤\033[0m\n"
                      << "\033[0;36m│\033[0m Enter the gravity acceleration (m/s²)  \033[0;36m│\033[0m\n"
                      << "\033[0;36m│\033[0m                                        \033[0;36m│\033[0m\n"
                      << "\033[0;36m│\033[0m \033[0;31me\033[0m - Exit                               \033[0;36m│\033[0m\n"
                      << "\033[0;36m└────────────────────────────────────────┘\033[0m\n"
                      << "\033[1;32m ❯ \033[0m\033[0;37m";
            std::getline(std::cin, input);
            std::cout << "\033[0m\n";

            if(input == "e") {
                menu::secureExit();
            }

            try {
                gravityAcceleration = std::stod(input);
            } catch(const std::exception& e) {
                std::cerr << "Error: " << e.what() << "\n";
                std::cout << "Press enter...";
                std::cin.get();
                continue;
            }
            break;
        }
        return gravityAcceleration;
    }

    double thrustTimeMenu() {
        double thrustTime;
        while(true) {
            std::string input;
            clear();
            std::cout << "\033[0;36m┌────────────────────────────┐\033[0m\n"
                      << "\033[0;36m│\033[0m        \033[1;31mRocketLabCLI\033[0m        \033[0;36m│\033[0m\n"
                      << "\033[0;36m├────────────────────────────┤\033[0m\n"
                      << "\033[0;36m│\033[0m Enter the thrust time (s)  \033[0;36m│\033[0m\n"
                      << "\033[0;36m│\033[0m                            \033[0;36m│\033[0m\n"
                      << "\033[0;36m│\033[0m \033[0;31me\033[0m - Exit                   \033[0;36m│\033[0m\n"
                      << "\033[0;36m└────────────────────────────┘\033[0m\n"
                      << "\033[1;32m ❯ \033[0m\033[0;37m";
            std::getline(std::cin, input);
            std::cout << "\033[0m\n";

            if(input == "e") {
                menu::secureExit();
            }

            try {
                thrustTime = std::stod(input);
            } catch(const std::exception& e) {
                std::cerr << "Error: " << e.what() << "\n";
                std::cout << "Press enter...";
                std::cin.get();
                continue;
            }
            break;
        }
        return thrustTime;
    }

    double angleOfAttackMenu() {
        double angleOfAttack;
        while(true) {
            std::string input;
            clear();
            std::cout << "\033[0;36m┌────────────────────────────────┐\033[0m\n"
                      << "\033[0;36m│\033[0m          \033[1;31mRocketLabCLI\033[0m          \033[0;36m│\033[0m\n"
                      << "\033[0;36m├────────────────────────────────┤\033[0m\n"
                      << "\033[0;36m│\033[0m Enter the angle of attack (°)  \033[0;36m│\033[0m\n"
                      << "\033[0;36m│\033[0m                                \033[0;36m│\033[0m\n"
                      << "\033[0;36m│\033[0m \033[0;31me\033[0m - Exit                       \033[0;36m│\033[0m\n"
                      << "\033[0;36m└────────────────────────────────┘\033[0m\n"
                      << "\033[1;32m ❯ \033[0m\033[0;37m";
            std::getline(std::cin, input);
            std::cout << "\033[0m\n";

            if(input == "e") {
                menu::secureExit();
            }

            try {
                angleOfAttack = std::stod(input);
            } catch(const std::exception& e) {
                std::cerr << "Error: " << e.what() << "\n";
                std::cout << "Press enter...";
                std::cin.get();
                continue;
            }
            break;
        }
        return angleOfAttack;
    }

    void resultMenu(
        double gravityAcceleration, double mass, double engineThrust, double thrustTime, double angleOfAttack,
        double accelerationTime, double inertiaTime, double fallTime, double totalTime, double maxHeight, double maxSpeed
    ) {
        while(true) {
            std::string input;
            clear();
            std::cout << "\033[0;36m┌──────────────────────────────────────┐\033[0m\n"
                      << "\033[0;36m│\033[0m             \033[1;31mRocketLabCLI\033[0m             \033[0;36m│\033[0m\n"
                      << "\033[0;36m├──────────────────────────────────────┤\033[0m\n"
                      << "\033[0;36m│\033[0m Parameters:                           \n"
                      << "\033[0;36m│\033[0m  Gravity acceleration: " << std::to_string(gravityAcceleration) << " m/s²\n"
                      << "\033[0;36m│\033[0m  Mass: " << std::to_string(mass*1000) << " g\n"
                      << "\033[0;36m│\033[0m  Engine thrust: " << std::to_string(engineThrust) << " N\n"
                      << "\033[0;36m│\033[0m  Thrust time: " << std::to_string(thrustTime) << " s\n"
                      << "\033[0;36m│\033[0m  Angle of attack: " << std::to_string(angleOfAttack) << " °\n"
                      << "\033[0;36m│\033[0m Result:                               \n"
                      << "\033[0;36m│\033[0m  Acceleration time: " << std::to_string(accelerationTime) << " s\n"
                      << "\033[0;36m│\033[0m  Anertia time: " << std::to_string(inertiaTime) << " s\n"
                      << "\033[0;36m│\033[0m  Fall time: " << std::to_string(fallTime) << " s\n"
                      << "\033[0;36m│\033[0m  Total time: " << std::to_string(totalTime) << " s\n"
                      << "\033[0;36m│\033[0m  Max height: " << std::to_string(maxHeight) << " m\n"
                      << "\033[0;36m│\033[0m  Max speed: " << std::to_string(std::abs(maxSpeed)) << " m/s\n"
                      << "\033[0;36m│\033[0m                                      \033[0;36m│\033[0m\n"
                      << "\033[0;36m│\033[0m \033[0;32ms\033[0m - Save                             \033[0;36m│\033[0m\n"
                      << "\033[0;36m│\033[0m \033[0;33mm\033[0m - Main menu                        \033[0;36m│\033[0m\n"
                      << "\033[0;36m│\033[0m \033[0;31me\033[0m - Exit                             \033[0;36m│\033[0m\n"
                      << "\033[0;36m└──────────────────────────────────────┘\033[0m\n"
                      << "\033[1;32m ❯ \033[0m\033[0;37m";
            std::getline(std::cin, input);
            std::cout << "\033[0m\n";

            if(input == "s") {
                menu::saveMenu(gravityAcceleration, mass, engineThrust, thrustTime, angleOfAttack,
                    accelerationTime, inertiaTime, fallTime, totalTime, maxHeight, maxSpeed);
            }
            else if(input == "m") {
                break;
            }
            else if(input == "e") {
                menu::secureExit();
            }
            else {
                std::cout << "Error: wrong input \"" << input << "\"\n";
                std::cout << "Press enter...";
                std::cin.get();
                continue;
            }
        }
    }
    
    void saveMenu(
        double gravityAcceleration, double mass, double engineThrust, double thrustTime, double angleOfAttack,
        double accelerationTime, double inertiaTime, double fallTime, double totalTime, double maxHeight, double maxSpeed
    ) {
        while(true) {
            std::string input;

            //name; cancel -> break;
            std::string fileName;
            clear();
            std::cout << "\033[0;36m┌────────────────────────────┐\033[0m\n"
                      << "\033[0;36m│\033[0m        \033[1;31mRocketLabCLI\033[0m        \033[0;36m│\033[0m\n"
                      << "\033[0;36m├────────────────────────────┤\033[0m\n"
                      << "\033[0;36m│\033[0m Name of file               \033[0;36m│\033[0m\n"
                      << "\033[0;36m│\033[0m                            \033[0;36m│\033[0m\n"
                      << "\033[0;36m│\033[0m \033[0;33mc\033[0m - cancel                 \033[0;36m│\033[0m\n"
                      << "\033[0;36m│\033[0m \033[0;31me\033[0m - Exit                   \033[0;36m│\033[0m\n"
                      << "\033[0;36m└────────────────────────────┘\033[0m\n"
                      << "\033[1;32m ❯ \033[0m\033[0;37m";
            std::getline(std::cin, input);
            std::cout << "\033[0m\n";

            if(input == "e") {
                menu::secureExit();
            }
            else if(input == "c") {
                break;
            }
            fileName = input;

            //save? cancel -> break;
            clear();
            std::cout << "\033[0;36m┌────────────────────────────┐\033[0m\n"
                      << "\033[0;36m│\033[0m        \033[1;31mRocketLabCLI\033[0m        \033[0;36m│\033[0m\n"
                      << "\033[0;36m├────────────────────────────┤\033[0m\n"
                      << "\033[0;36m│\033[0m Confirm save?              \033[0;36m│\033[0m\n"
                      << "\033[0;36m│\033[0m                            \033[0;36m│\033[0m\n"
                      << "\033[0;36m│\033[0m \033[0;32ms\033[0m - save                   \033[0;36m│\033[0m\n"
                      << "\033[0;36m│\033[0m \033[0;33mc\033[0m - cancel                 \033[0;36m│\033[0m\n"
                      << "\033[0;36m│\033[0m \033[0;31me\033[0m - Exit                   \033[0;36m│\033[0m\n"
                      << "\033[0;36m└────────────────────────────┘\033[0m\n"
                      << "\033[1;32m ❯ \033[0m\033[0;37m";
            std::getline(std::cin, input);
            std::cout << "\033[0m\n";

            if(input == "e") {
                menu::secureExit();
            }
            else if(input == "c") {
                break;
            }
            else if(input == "s") {}
            else {
                std::cout << "Error: wrong input \"" << input << "\"\n";
                std::cout << "Press enter...";
                std::cin.get();
                continue;
            }

            //save: ofstream, if error, etc;
            std::ofstream outFile(fileName);
            if(!outFile) {
                std::cerr << "Error creating file!\n";
                std::cout << "Press enter...";
                std::cin.get();
                continue;
            }

            outFile << "RocketLabCLI Simulation Result:\n"
                    << "Parameters:\n"
                    << "  Gravity acceleration: " << std::to_string(gravityAcceleration) << " m/s²\n"
                    << "  Mass: " << std::to_string(mass*1000) << " g\n"
                    << "  Engine thrust: " << std::to_string(engineThrust) << " N\n"
                    << "  Thrust time: " << std::to_string(thrustTime) << " s\n"
                    << "  Angle of attack: " << std::to_string(angleOfAttack) << " °\n"
                    << "Result:                               \n"
                    << "  Acceleration time: " << std::to_string(accelerationTime) << " s\n"
                    << "  Anertia time: " << std::to_string(inertiaTime) << " s\n"
                    << "  Fall time: " << std::to_string(fallTime) << " s\n"
                    << "  Total time: " << std::to_string(totalTime) << " s\n"
                    << "  Max height: " << std::to_string(maxHeight) << " m\n"
                    << "  Max speed: " << std::to_string(std::abs(maxSpeed)) << " m/s\n"
                    << "EOF\n";

            outFile.close();
            std::cout << "Sucessifuly saved results to " << fileName << "\n";
            std::cout << "Press enter...";
            std::cin.get();
            break;
        }
    }

    void clear() {
    std::cout << "\033[2J\033[H"; 
    }

    void secureExit() {
        throw std::runtime_error("Exit Program");
    }
}