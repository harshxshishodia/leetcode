class Solution {
public:
    vector<int> goodIndices(
        vector<int>& nums,
        int k
    ) {
        int n =
            static_cast<int>(nums.size());

        vector<int> increases(
            n
        );

        vector<int> decreases(
            n
        );

        for (int index = 1; index < n; index++) {
            increases[index] =
                increases[index - 1] +
                (
                    nums[index] >
                    nums[index - 1]
                );

            decreases[index] =
                decreases[index - 1] +
                (
                    nums[index] <
                    nums[index - 1]
                );
        }

        vector<int> answer;

        for (int index = k;
             index + k < n;
             index++) {
            int leftIncreases =
                increases[index - 1] -
                increases[index - k];

            int rightDecreases =
                decreases[index + k] -
                decreases[index + 1];

            if (leftIncreases == 0 &&
                rightDecreases == 0) {
                answer.push_back(index);
            }
        }

        return answer;
    }
};
