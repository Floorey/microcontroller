#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class WaterLevelSensor {
public:
    // Pure virtual function
    virtual int getCurrentWaterLevel() const = 0;

    // Method to release water
    virtual void releaseWater(int waterLevel) const {
        if (waterLevel > 30) {
            std::cout << "Water released." << std::endl;
        } else {
            std::cout << "Water level is too low to release water." << std::endl;
        }
    }
};

class RandomWaterLevelSensor : public WaterLevelSensor {
public:
    // Implement getCurrentWaterLevel() for random water level generation
    int getCurrentWaterLevel() const override {
        return rand() % 100 + 1;
    }
};

class ManualWaterLevelSensor : public WaterLevelSensor {
private:
    int waterLevel = 0;

public:
    // Implement getCurrentWaterLevel() for manually set water level
    int getCurrentWaterLevel() const override {
        return waterLevel;
    }

    // Method to set the water level manually
    void setWaterLevel(int level) {
        waterLevel = level;
    }
};

class OverflowSensor : public WaterLevelSensor {
private:
    int waterLevel = 0; // Water level in the basin below the fountain

public:
    // Override getCurrentWaterLevel() to get water level from Sensor 1 and 2
    int getCurrentWaterLevel() const override {
        return waterLevel;
    }

    // Method to add water from Sensor 1 and 2
    void addWater(int amount) {
        waterLevel += amount;
    }

    // Override releaseWater() for overflow detection
    void releaseWater(int waterLevel) const override {
        if (waterLevel > 0) {
            std::cout << "Overflow detected in the basin below the fountain. Signaling to stop water supply." << std::endl;
            stopWaterSupply();
        } else {
            std::cout << "No overflow detected." << std::endl;
        }
    }

private:
    // Method to stop the water supply
    void stopWaterSupply() const {
        std::cout << "Stopping water supply to prevent overflow in the basin." << std::endl;
    }
};

int main() {
    srand(time(0));
    RandomWaterLevelSensor sensor1;
    RandomWaterLevelSensor sensor2;
    OverflowSensor sensor3;

    std::string input;
    do {
        int waterLevel1 = sensor1.getCurrentWaterLevel();
        int waterLevel2 = sensor2.getCurrentWaterLevel();
        int waterLevel3 = sensor3.getCurrentWaterLevel();

        std::cout << "Current water level - Sensor 1: " << waterLevel1 << std::endl;
        std::cout << "Current water level - Sensor 2: " << waterLevel2 << std::endl;
        std::cout << "Current water level - Sensor 3 (Basin below the fountain): " << waterLevel3 << std::endl;

        std::cout << "Please select a sensor (1 or 2) to release water, or type 'quit' to exit:" << std::endl;
        std::cin >> input;

        if (input == "1") {
            sensor3.addWater(waterLevel1);
        } else if (input == "2") {
            sensor3.addWater(waterLevel2);
        } else if (input != "quit") {
            std::cout << "Invalid input. Please use 1, 2, or quit to exit." << std::endl;
        }
    } while (input != "quit");

    return 0;
}
