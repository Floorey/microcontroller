#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class WaterLevelSensor {
public:

    bool isWaterLow() {
        int randomValue = rand() % 100 + 1;

        return randomValue > 30;
    }


    int getCurrentWaterLevel() const {
        return rand() % 100 + 1;
    }


    void releaseWater(int waterLevel) const {
        if (waterLevel > 30) {
            std::cout << "Water released." << std::endl;
        } else {
            std::cout << "Water level is too low to release water." << std::endl;
        }
    }
};

int main() {
    srand(time(0));
    WaterLevelSensor sensor1;
    WaterLevelSensor sensor2;

    std::string input;
    do {
        int waterLevel1 = sensor1.getCurrentWaterLevel();
        int waterLevel2 = sensor2.getCurrentWaterLevel();

        std::cout << "Current water level - Sensor 1: " << waterLevel1 << std::endl;
        std::cout << "Current water level - Sensor 2: " << waterLevel2 << std::endl;


        std::cout << "Please select a sensor (1 or 2) to release water, or type 'quit' to exit:" << std::endl;
        std::cin >> input;


        if (input == "1") {
            sensor1.releaseWater(waterLevel1);
        } else if (input == "2") {
            sensor2.releaseWater(waterLevel2);
        } else if (input != "quit") {
            std::cout << "Invalid input. Please use 1 for sensor 1 and 2 for sensor 2." << std::endl;
        }
    } while (input != "quit");

    return 0;
}
