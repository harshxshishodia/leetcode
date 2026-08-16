class ParkingSystem {
    int bigCapacity;
    int mediumCapacity;
    int smallCapacity;

public:
    ParkingSystem(int big, int medium, int small)
        : bigCapacity(big), mediumCapacity(medium), smallCapacity(small) {}

    bool addCar(int carType) {
        if (carType == 1) {
            if (bigCapacity > 0) {
                bigCapacity--;
                return true;
            }
        } else if (carType == 2) {
            if (mediumCapacity > 0) {
                mediumCapacity--;
                return true;
            }
        } else if (carType == 3) {
            if (smallCapacity > 0) {
                smallCapacity--;
                return true;
            }
        }
        return false;
    }
};
