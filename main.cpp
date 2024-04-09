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
