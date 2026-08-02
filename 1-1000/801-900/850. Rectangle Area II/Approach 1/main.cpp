class Solution {
    struct Event {
        int x;
        int y1;
        int y2;
        int type; // +1 for start, -1 for end
        bool operator<(const Event& other) const {
            return x < other.x;
        }
    };
    vector<int> countCovered;
    vector<int> lengthCovered;
    vector<int> yCoordinates;
    int treeSize;

    void updateRange(int nodeIndex, int left, int right, int queryLeft, int queryRight, int value) {
        if (queryLeft > right || queryRight < left) {
            return;
        }
        if (left >= queryLeft && right <= queryRight) {
            countCovered[nodeIndex] += value;
        } else {
            int mid = left + (right - left) / 2;
            updateRange(2 * nodeIndex + 1, left, mid, queryLeft, queryRight, value);
            updateRange(2 * nodeIndex + 2, mid + 1, right, queryLeft, queryRight, value);
        }
        if (countCovered[nodeIndex] > 0) {
            lengthCovered[nodeIndex] = yCoordinates[right + 1] - yCoordinates[left];
        } else if (left == right) {
            lengthCovered[nodeIndex] = 0;
        } else {
            lengthCovered[nodeIndex] = lengthCovered[2 * nodeIndex + 1] + lengthCovered[2 * nodeIndex + 2];
        }
    }

public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        vector<Event> events;
        for (const auto& rect : rectangles) {
            events.push_back({rect[0], rect[1], rect[3], 1});
            events.push_back({rect[2], rect[1], rect[3], -1});
            yCoordinates.push_back(rect[1]);
            yCoordinates.push_back(rect[3]);
        }
        sort(events.begin(), events.end());
        sort(yCoordinates.begin(), yCoordinates.end());
        yCoordinates.erase(unique(yCoordinates.begin(), yCoordinates.end()), yCoordinates.end());
        
        int numY = yCoordinates.size();
        treeSize = numY - 1;
        countCovered.assign(4 * treeSize, 0);
        lengthCovered.assign(4 * treeSize, 0);
        
        long long totalArea = 0;
        long long MOD = 1000000007;
        int previousX = events[0].x;
        
        for (const auto& event : events) {
            int currentX = event.x;
            totalArea = (totalArea + (long long)(currentX - previousX) * lengthCovered[0]) % MOD;
            previousX = currentX;
            int y1Rank = lower_bound(yCoordinates.begin(), yCoordinates.end(), event.y1) - yCoordinates.begin();
            int y2Rank = lower_bound(yCoordinates.begin(), yCoordinates.end(), event.y2) - yCoordinates.begin() - 1;
            updateRange(0, 0, treeSize - 1, y1Rank, y2Rank, event.type);
        }
        
        return totalArea;
    }
};
