class Solution {
public:
    vector<int> goodIndices(
        vector<int>& nums,
        int k
    ) {
        int n =
            static_cast<int>(nums.size());

        vector<int> answer;

        for (int index = k;
             index + k < n;
             index++) {
            bool valid = true;

            for (int current =
                     index - k + 1;
                 current <= index - 1;
                 current++) {
                if (nums[current] >
                    nums[current - 1]) {
                    valid = false;
                    break;
                }
            }

            if (!valid) {
                continue;
            }

            for (int current =
                     index + 2;
                 current <= index + k;
                 current++) {
                if (nums[current] <
                    nums[current - 1]) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                answer.push_back(
                    index
                );
            }
        }

        return answer;
    }
};
