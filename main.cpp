#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>


class WaterLevelSensor {
public:
    virtual int getCurrentWaterLevel() const = 0;

    virtual void releaseWater(int waterLevel) const {
        if (waterLevel > 30) {
            std::cout << "Water released." << std::endl;
        } else {
            std::cout << "Water level is too low to release water." << std::endl;
        }
    }
};
class OverflowSensor : public WaterLevelSensor {
private:
    int waterLevel = 0; // water level in the cistern
public:
    // getCurrentWaterLevel for overflow sensor
    int getCurrentWaterLevel() const override {
        return waterLevel;
    }
    // methode to add water to the cistren from rainwater collector
    void addWater(int amound) {
        waterLevel += amound;
        checkOverflow(); // check for overflow after adding water
    }

    //override releasedWater() for stopping outlet sensor is low
    void releaseWater(int waterLevel) const override {
        if (waterLevel < 30) {
            std::cout << "Cistern water level is to low. Stopping water outlet." << std::endl;
        } else {
            std::cout << "Cistern water level is sufficient. Proceeding with water outlet," << std::endl;
        }
    }

private:
    // method to check for an overflow in the cistern
    void checkOverflow() {
        if (waterLevel > 100) {
            std::cout << "Overflow detected in the cistern. Signaling to stop water supply."<< std::endl;
            stopWaterSupply();
        }
    }
    // method to stop the water supply
    void stopWaterSupply() const {
        std::cout << "Stopping water supply from rainwater collector to prevent overflow in the cistern." << std::endl;
    }
};
class MinimumLevelSensor : public WaterLevelSensor {
private:
    int minLevel = 0;
public:
    // constructor to set the minimum water level sensor
    MinimumLevelSensor(int min) : minLevel(min) {}

    int getCurrentWaterLevel() const override {
        return minLevel;
    }

    // override releaseWater() for stopping outlet if minimum level is not met
    void releaseWater(int waterLevel) const override {
        if (waterLevel < minLevel) {
            std::cout << "Cistern water level is below minimum. Stopping water outlet." << std::endl;
        } else {
            std::cout << "Cistern water level is sufficient. Proceeding with water outlet." << std::endl;
        }
    }
};
class FountainBasinSensor : public WaterLevelSensor {
private:
    int waterLevel = 0;
public:
    int getCurrentWaterLevel() const override {
        return waterLevel;
    }
    void addWater(int amound) {
        waterLevel += amound;
        checkAlarm();
    }
    void checkAlarm() const {
        if (waterLevel > 2000) {
            std::cout << "Alarm: Water level in the fountain basin is too high!" << std::endl;
        }
    }
};
int main() {
    srand(time(0));

    OverflowSensor sensor1; // overflow sensor cistern
    MinimumLevelSensor sensor2(50); //minimum Sensor2
    FountainBasinSensor sensor3; // fountain sensor

    std::string input;
    do {
        int waterLevel1 = sensor1.getCurrentWaterLevel();
        int waterLevel2 = sensor2.getCurrentWaterLevel();
        int waterLevel3 = sensor3.getCurrentWaterLevel();


        std::cout << "Current water level - Cistern Overflow Sensor: " << waterLevel1 << std::endl;
        std::cout << "Current minimum water level - Cistern Minimum Level Sensor: " << waterLevel2 << std::endl;
        std::cout << "Current water level - Fountain Basin Sensor: " << waterLevel3 << std::endl;

        std::cout << "Please select an action (1: Add water to cistern, 2: Release water from cistern, 3: Quit):" << std::endl;
        std::cin >> input;

        if (input == "1") {
            // Add water to the cistern from the rainwater collector
            int waterAmount;
            std::cout << "Enter the amount of water to add to the cistern: ";
            std::cin >> waterAmount;
            sensor1.addWater(waterAmount);

            // Add the added water to the fountain basin
            sensor3.addWater(waterAmount);
        } else if (input == "2") {
            // Release water from the cistern if conditions are met
            sensor2.releaseWater(sensor2.getCurrentWaterLevel());
        } else if (input != "3") {
            std::cout << "Invalid input. Please use 1, 2, or 3 to select an action." << std::endl;
        }
    } while (input != "3");

    return 0;
}