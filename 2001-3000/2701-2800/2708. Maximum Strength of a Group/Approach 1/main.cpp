class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        int n =
            static_cast<int>(nums.size());

        long long answer =
            numeric_limits<long long>::min();

        for (int mask = 1;
             mask < (1 << n);
             mask++) {
            long long product = 1;

            for (int index = 0;
                 index < n;
                 index++) {
                if ((mask & (1 << index)) != 0) {
                    product *=
                        nums[index];
                }
            }

            answer = max(
                answer,
                product
            );
        }

        return answer;
    }
};
