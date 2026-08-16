class SnakeGame {
    int width, height;
    vector<vector<int>> foodList;
    int foodIndex;
    int score;
    deque<pair<int, int>> body;
    unordered_set<int> occupiedCoordinates;

public:
    SnakeGame(int w, int h, vector<vector<int>>& food)
        : width(w), height(h), foodList(food), foodIndex(0), score(0) {
        body.push_back({0, 0});
        occupiedCoordinates.insert(0);
    }

    int move(string direction) {
        auto [headRow, headCol] = body.front();
        if (direction == "U") headRow--;
        else if (direction == "D") headRow++;
        else if (direction == "L") headCol--;
        else if (direction == "R") headCol++;

        if (headRow < 0 || headRow >= height || headCol < 0 || headCol >= width) {
            return -1;
        }

        auto tail = body.back();
        occupiedCoordinates.erase(tail.first * width + tail.second);

        int newHeadPos = headRow * width + headCol;
        if (occupiedCoordinates.count(newHeadPos)) {
            return -1;
        }

        if (foodIndex < static_cast<int>(foodList.size()) && headRow == foodList[foodIndex][0] && headCol == foodList[foodIndex][1]) {
            foodIndex++;
            score++;
            occupiedCoordinates.insert(tail.first * width + tail.second);
        } else {
            body.pop_back();
        }

        body.push_front({headRow, headCol});
        occupiedCoordinates.insert(newHeadPos);
        return score;
    }
};
