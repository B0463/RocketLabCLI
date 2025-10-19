namespace menu {
    void mainMenu();
    void newSimulation();
    double massMenu();
    double engineThrustMenu();
    double gravityAccelerationMenu();
    double thrustTimeMenu();
    void resultMenu(
        double gravityAcceleration, double mass, double engineThrust, double thrustTime,
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
            std::cout << "==============================\n"
                      << "=        RocketLabCLI        =\n"
                      << "==============================\n"
                      << "= n - New Simulation         =\n"
                      << "=                            =\n"
                      << "= e - Exit                   =\n"
                      << "==============================\n"
                      << ">> ";
            std::getline(std::cin, input);
            std::cout << "\n";

            if(input == "e") menu::secureExit();
            if(input == "n") menu::newSimulation();
            else {
                std::cout << "Error: wrong input\n";
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
        
        double accelerationTime, inertiaTime, fallTime, totalTime;
        double maxHeight, maxSpeed;

        simulation::simulate(mass, engineThrust, gravityAcceleration, thrustTime,
            &accelerationTime, &inertiaTime, &fallTime, &totalTime, &maxHeight, &maxSpeed);

        menu::resultMenu(gravityAcceleration, mass, engineThrust, thrustTime,
            accelerationTime, inertiaTime, fallTime, totalTime, maxHeight, maxSpeed);

        return;
    }

    double massMenu() {
        double mass;
        while(true) {
            std::string input;
            clear();
            std::cout << "==============================\n"
                      << "=        RocketLabCLI        =\n"
                      << "==============================\n"
                      << "= Enter the mass (g)         =\n"
                      << "=                            =\n"
                      << "= e - Exit                   =\n"
                      << "==============================\n"
                      << ">> ";
            std::getline(std::cin, input);
            std::cout << "\n";

            if(input == "e") menu::secureExit();

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
            std::cout << "================================\n"
                      << "=         RocketLabCLI         =\n"
                      << "================================\n"
                      << "= Enter the engine thrust (N)  =\n"
                      << "=                              =\n"
                      << "= e - Exit                     =\n"
                      << "================================\n"
                      << ">> ";
            std::getline(std::cin, input);
            std::cout << "\n";

            if(input == "e") menu::secureExit();

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
            std::cout << "==========================================\n"
                      << "=              RocketLabCLI              =\n"
                      << "==========================================\n"
                      << "= Enter the gravity acceleration (m/s²)  =\n"
                      << "=                                        =\n"
                      << "= e - Exit                               =\n"
                      << "==========================================\n"
                      << ">> ";
            std::getline(std::cin, input);
            std::cout << "\n";

            if(input == "e") menu::secureExit();

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
            std::cout << "==============================\n"
                      << "=        RocketLabCLI        =\n"
                      << "==============================\n"
                      << "= Enter the thrust time (s)  =\n"
                      << "=                            =\n"
                      << "= e - Exit                   =\n"
                      << "==============================\n"
                      << ">> ";
            std::getline(std::cin, input);
            std::cout << "\n";

            if(input == "e") menu::secureExit();

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

    void resultMenu(
        double gravityAcceleration, double mass, double engineThrust, double thrustTime,
        double accelerationTime, double inertiaTime, double fallTime, double totalTime, double maxHeight, double maxSpeed
    ) {
        while(true) {
            std::string input;
            clear();
            std::cout << "========================================\n"
                      << "=             RocketLabCLI             =\n"
                      << "========================================\n"
                      << "= Parameters:                           \n"
                      << "=  Gravity acceleration: " << std::to_string(gravityAcceleration) << " m/s²\n"
                      << "=  Mass: " << std::to_string(mass*1000) << " g\n"
                      << "=  Engine thrust: " << std::to_string(engineThrust) << " N\n"
                      << "=  Thrust time: " << std::to_string(thrustTime) << " s\n"
                      << "= Result:                               \n"
                      << "=  Acceleration time: " << std::to_string(accelerationTime) << " s\n"
                      << "=  Anertia time: " << std::to_string(inertiaTime) << " s\n"
                      << "=  Fall time: " << std::to_string(fallTime) << " s\n"
                      << "=  Total time: " << std::to_string(totalTime) << " s\n"
                      << "=  Max height: " << std::to_string(maxHeight) << " m\n"
                      << "=  Max speed: " << std::to_string(std::abs(maxSpeed)) << " m/s\n"
                      << "=                                       \n"
                      << "= s - Save                              \n"
                      << "= m - Main menu                         \n"
                      << "= e - Exit                              \n"
                      << "========================================\n"
                      << ">> ";
            std::getline(std::cin, input);
            std::cout << "\n";

            if(input == "s") menu::secureExit();
            if(input == "e") menu::secureExit();
            else {
                std::cout << "Error: wrong input\n";
                std::cout << "Press enter...";
                std::cin.get();
                continue;
            }
        }
    }

    void clear() {
    std::cout << "\033[2J\033[H"; 
    }

    void secureExit() {
        throw std::runtime_error("Exit Program");
    }
}