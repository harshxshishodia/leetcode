class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long prefix = 0;
        long long answer = 0;

        for (int index = 0;
             index < static_cast<int>(nums.size());
             index++) {
            prefix +=
                nums[index];

            long long needed =
                (
                    prefix +
                    index
                ) /
                (index + 1);

            answer = max(
                answer,
                needed
            );
        }

        return static_cast<int>(
            answer
        );
    }
};
