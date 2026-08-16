class Vector2D {
    vector<int> elements;
    int currentIndex;

public:
    Vector2D(vector<vector<int>>& vec) : currentIndex(0) {
        for (const auto& row : vec) {
            for (int val : row) {
                elements.push_back(val);
            }
        }
    }

    int next() {
        return elements[currentIndex++];
    }

    bool hasNext() {
        return currentIndex < static_cast<int>(elements.size());
    }
};
