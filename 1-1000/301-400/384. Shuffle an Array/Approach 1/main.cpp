class Solution {
    vector<int> original;

public:
    Solution(vector<int>& nums) : original(nums) {}

    vector<int> reset() {
        return original;
    }

    vector<int> shuffle() {
        vector<int> auxiliary = original;
        vector<int> shuffledResult;
        while (!auxiliary.empty()) {
            int removeIndex = rand() % auxiliary.size();
            shuffledResult.push_back(auxiliary[removeIndex]);
            auxiliary.erase(auxiliary.begin() + removeIndex);
        }
        return shuffledResult;
    }
};
