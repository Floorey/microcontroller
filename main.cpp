#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

// wate sensor
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
    void sendCommand(int microcotrollerID, const std::string& commnand){
      std::cout << "Command to:'" << commnand << "' microcontroller" << microcotrollerID << " send. " << std::endl;

    }
};
int main() {
    srand(time(0));
    WaterLevelSensor sensor1;
    WaterLevelSensor sensor2;

    CommandSender sender;

    while (true) {
        int waterLevel1 = sensor1.getCurrentWaterLevel();
        int waterLevel2 = sensor2.getCurrentWaterLevel();

        std::cout << "actual value: sensor 1: " << waterLevel1 << std::endl;
        std::cout << "actual value: sensor 2: " << waterLevel2 << std::endl;

        if (sensor1.isWaterLow()) {
            sender.sendCommand(1,"output");
        }
        if (sensor2.isWaterLow()) {
            sender.sendCommand(2, "output");
        }
        // check for user input
        std::cout << "Please insert the sensor: 1 or 2. Valid inputs are 1 and 2:" << std::endl;
        int sensorChoice;
        std::cin >> sensorChoice;

        if(sensorChoice == 1) {
            sensor1.releaseWater();
        } else if (sensorChoice == 2) {
            sensor2.releaseWater();
        } else {
            std::cout << " Invalid input: Plaes use 1 for sensor1 and 2 for sensor2" << std::endl;
        }
        return 0;

    }
}