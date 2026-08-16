class NumArray {
    vector<int> arrayData;

public:
    NumArray(vector<int>& nums) : arrayData(nums) {}

    void update(int index, int val) {
        arrayData[index] = val;
    }

    int sumRange(int left, int right) {
        int totalSum = 0;
        for (int i = left; i <= right; i++) {
            totalSum += arrayData[i];
        }
        return totalSum;
    }
};
