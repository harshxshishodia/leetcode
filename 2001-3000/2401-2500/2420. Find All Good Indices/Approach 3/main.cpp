class Solution {
public:
    vector<int> goodIndices(
        vector<int>& nums,
        int k
    ) {
        int n =
            static_cast<int>(nums.size());

        vector<int> nonIncreasing(
            n,
            1
        );

        vector<int> nonDecreasing(
            n,
            1
        );

        for (int index = 1; index < n; index++) {
            if (nums[index] <=
                nums[index - 1]) {
                nonIncreasing[index] =
                    nonIncreasing[index - 1] +
                    1;
            }
        }

        for (int index = n - 2;
             index >= 0;
             index--) {
            if (nums[index] <=
                nums[index + 1]) {
                nonDecreasing[index] =
                    nonDecreasing[index + 1] +
                    1;
            }
        }

        vector<int> answer;

        for (int index = k;
             index + k < n;
             index++) {
            if (nonIncreasing[index - 1] >= k &&
                nonDecreasing[index + 1] >= k) {
                answer.push_back(index);
            }
        }

        return answer;
    }
};
