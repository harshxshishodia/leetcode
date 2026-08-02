class Solution {
    struct Event {
        double y;
        double x1;
        double x2;
        int type;
        bool operator<(const Event& other) const {
            return y < other.y;
        }
    };

    vector<int> countCovered;
    vector<double> lengthCovered;
    vector<double> xCoordinates;
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
            lengthCovered[nodeIndex] = xCoordinates[right + 1] - xCoordinates[left];
        } else if (left == right) {
            lengthCovered[nodeIndex] = 0;
        } else {
            lengthCovered[nodeIndex] = lengthCovered[2 * nodeIndex + 1] + lengthCovered[2 * nodeIndex + 2];
        }
    }

public:
    double separateSquares(vector<vector<int>>& squares) {
        vector<Event> events;
        for (const auto& sq : squares) {
            double x = sq[0], y = sq[1], l = sq[2];
            events.push_back({y, x, x + l, 1});
            events.push_back({y + l, x, x + l, -1});
            xCoordinates.push_back(x);
            xCoordinates.push_back(x + l);
        }
        sort(events.begin(), events.end());
        sort(xCoordinates.begin(), xCoordinates.end());
        xCoordinates.erase(unique(xCoordinates.begin(), xCoordinates.end()), xCoordinates.end());

        int numX = xCoordinates.size();
        treeSize = numX - 1;
        countCovered.assign(4 * treeSize, 0);
        lengthCovered.assign(4 * treeSize, 0);

        double totalArea = 0;
        double previousY = events[0].y;

        vector<tuple<double, double, double>> intervals; // {prevY, currY, xLength}

        for (const auto& event : events) {
            double currentY = event.y;
            double areaAdd = (currentY - previousY) * lengthCovered[0];
            totalArea += areaAdd;
            if (currentY > previousY) {
                intervals.push_back({previousY, currentY, lengthCovered[0]});
            }
            previousY = currentY;

            int x1Rank = lower_bound(xCoordinates.begin(), xCoordinates.end(), event.x1) - xCoordinates.begin();
            int x2Rank = lower_bound(xCoordinates.begin(), xCoordinates.end(), event.x2) - xCoordinates.begin() - 1;
            updateRange(0, 0, treeSize - 1, x1Rank, x2Rank, event.type);
        }

        double halfArea = totalArea / 2.0;
        double accumulatedArea = 0;

        for (const auto& item : intervals) {
            double y1 = get<0>(item);
            double y2 = get<1>(item);
            double xLen = get<2>(item);
            double currentIntervalArea = (y2 - y1) * xLen;

            if (accumulatedArea + currentIntervalArea >= halfArea) {
                double remainingAreaNeeded = halfArea - accumulatedArea;
                return y1 + (remainingAreaNeeded / xLen);
            }
            accumulatedArea += currentIntervalArea;
        }

        return 0.0;
    }
};
