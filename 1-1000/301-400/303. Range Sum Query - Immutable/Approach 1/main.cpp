class NumArray {
    vector<int> numbers;

public:
    NumArray(vector<int>& nums) : numbers(nums) {}

    int sumRange(int left, int right) {
        int totalSum = 0;
        for (int i = left; i <= right; i++) {
            totalSum += numbers[i];
        }
        return totalSum;
    }
};
