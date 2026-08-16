class SparseVector {
public:
    vector<pair<int, int>> nonZeroPairs;

    SparseVector(vector<int> &nums) {
        for (int i = 0; i < static_cast<int>(nums.size()); i++) {
            if (nums[i] != 0) {
                nonZeroPairs.emplace_back(i, nums[i]);
            }
        }
    }

    int dotProduct(SparseVector& vec) {
        int result = 0;
        int i = 0, j = 0;
        while (i < static_cast<int>(nonZeroPairs.size()) && j < static_cast<int>(vec.nonZeroPairs.size())) {
            if (nonZeroPairs[i].first == vec.nonZeroPairs[j].first) {
                result += nonZeroPairs[i].second * vec.nonZeroPairs[j].second;
                i++;
                j++;
            } else if (nonZeroPairs[i].first < vec.nonZeroPairs[j].first) {
                i++;
            } else {
                j++;
            }
        }
        return result;
    }
};
