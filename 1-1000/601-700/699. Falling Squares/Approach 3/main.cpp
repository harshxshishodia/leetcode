class Solution {
    map<int, int>::iterator split(map<int, int>& heights, int coordinate) {
        auto iterator = prev(heights.upper_bound(coordinate));

        if (iterator->first == coordinate)
            return iterator;

        return heights.insert({coordinate, iterator->second}).first;
    }

public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        map<int, int> heights;
        heights[0] = 0;

        vector<int> answer;
        int maximumHeight = 0;

        for (const vector<int>& position : positions) {
            int left = position[0];
            int right = left + position[1];
            auto rightIterator = split(heights, right);
            auto leftIterator = split(heights, left);
            int baseHeight = 0;

            for (auto iterator = leftIterator; iterator != rightIterator; iterator++)
                baseHeight = max(baseHeight, iterator->second);

            int currentHeight = baseHeight + position[1];
            heights.erase(leftIterator, rightIterator);
            auto currentIterator = heights.insert({left, currentHeight}).first;

            if (currentIterator != heights.begin()) {
                auto previousIterator = prev(currentIterator);

                if (previousIterator->second == currentIterator->second) {
                    heights.erase(currentIterator);
                    currentIterator = previousIterator;
                }
            }

            auto nextIterator = next(currentIterator);

            if (nextIterator != heights.end() && nextIterator->second == currentIterator->second)
                heights.erase(nextIterator);

            maximumHeight = max(maximumHeight, currentHeight);
            answer.push_back(maximumHeight);
        }

        return answer;
    }
};