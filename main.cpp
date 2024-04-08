#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

// water sensor
class WaterLevelSensor {
public:
    bool isWaterLow(){
        int randomValue = rand() % 100 + 1;

        // is true if water is over a certain level
        return randomValue > 30;
    }

    // get water level
    int getCurrentWaterLevel() {
        return rand() %100 + 1;
    }

    void releaseWater() {
        std::cout << "Output water." << std::endl;
    }
};

class CommandSender {
public:
    void sendCommand(int microcontrollerID, const std::string& command){
        std::cout << "Command to: '" << command << "' microcontroller " << microcontrollerID << " send." << std::endl;
    }
};

int main() {
    srand(time(0));
    WaterLevelSensor sensor1;
    WaterLevelSensor sensor2;

    CommandSender sender;

    std::string input;
    do {
        int waterLevel1 = sensor1.getCurrentWaterLevel();
        int waterLevel2 = sensor2.getCurrentWaterLevel();

        std::cout << "Actual value: sensor 1: " << waterLevel1 << std::endl;
        std::cout << "Actual value: sensor 2: " << waterLevel2 << std::endl;

        // Check if water level is low and send command if necessary
        if (sensor1.isWaterLow() && input == "1") {
            sender.sendCommand(1, "output");
        }
        if (sensor2.isWaterLow() && input == "2") {
            sender.sendCommand(2, "output");
        }

        // Check for user input
        std::cout << "Please insert the sensor: 1 or 2. Valid inputs are 1 and 2. Type 'quit' to exit:" << std::endl;
        std::cin >> input;

        // Release water if user input is valid
        if(input == "1" || input == "2") {
            if(input == "1") {
                sensor1.releaseWater();
            } else {
                sensor2.releaseWater();
            }
        } else if (input != "quit") {
            std::cout << "Invalid input: Please use 1 for sensor 1 and 2 for sensor 2." << std::endl;
        }
    } while(input != "quit"); // Continue loop until 'quit' is entered

    return 0;
}
