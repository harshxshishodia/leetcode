class Robot {
    int width, height;
    int perimeterLength;
    int currentPosition;
    bool hasMovedFlag;

public:
    Robot(int w, int h)
        : width(w), height(h), perimeterLength(2 * (w + h - 2)), currentPosition(0), hasMovedFlag(false) {}

    void step(int num) {
        hasMovedFlag = true;
        currentPosition = (currentPosition + num) % perimeterLength;
    }

    vector<int> getPos() {
        if (currentPosition < width) {
            return {currentPosition, 0};
        } else if (currentPosition < width + height - 1) {
            return {width - 1, currentPosition - (width - 1)};
        } else if (currentPosition < 2 * width + height - 2) {
            return {width - 1 - (currentPosition - (width + height - 1) + 1), height - 1};
        } else {
            return {0, height - 1 - (currentPosition - (2 * width + height - 2) + 1)};
        }
    }

    string getDir() {
        if (!hasMovedFlag) return "East";
        if (currentPosition == 0) return "South";
        if (currentPosition < width) return "East";
        if (currentPosition < width + height - 1) return "North";
        if (currentPosition < 2 * width + height - 2) return "West";
        return "South";
    }
};
