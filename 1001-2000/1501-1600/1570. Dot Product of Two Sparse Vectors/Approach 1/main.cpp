class SparseVector {
public:
    unordered_map<int, int> nonZeroMap;

    SparseVector(vector<int> &nums) {
        for (int i = 0; i < static_cast<int>(nums.size()); i++) {
            if (nums[i] != 0) {
                nonZeroMap[i] = nums[i];
            }
        }
    }

    int dotProduct(SparseVector& vec) {
        int result = 0;
        for (const auto& [index, val] : nonZeroMap) {
            if (vec.nonZeroMap.count(index)) {
                result += val * vec.nonZeroMap[index];
            }
        }
        return result;
    }
};
