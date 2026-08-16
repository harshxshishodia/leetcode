class Solution {
    vector<int> originalArray;
    vector<int> currentArray;

public:
    Solution(vector<int>& nums) : originalArray(nums), currentArray(nums) {}

    vector<int> reset() {
        currentArray = originalArray;
        return currentArray;
    }

    vector<int> shuffle() {
        int n = static_cast<int>(currentArray.size());
        for (int i = 0; i < n; i++) {
            int randomIndex = i + rand() % (n - i);
            swap(currentArray[i], currentArray[randomIndex]);
        }
        return currentArray;
    }
};
