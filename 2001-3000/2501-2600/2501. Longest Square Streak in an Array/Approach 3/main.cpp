class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<long long> values(
            nums.begin(),
            nums.end()
        );

        int answer = -1;

        for (int value : nums) {
            int root =
                static_cast<int>(
                    sqrt(
                        static_cast<double>(value)
                    )
                );

            if (1LL *
                    root *
                    root ==
                    value &&
                values.count(root)) {
                continue;
            }

            long long current =
                value;

            int length = 1;

            while (current <= 1000000000LL) {
                long long next =
                    current *
                    current;

                if (!values.count(next)) {
                    break;
                }

                current =
                    next;

                length++;
            }

            if (length >= 2) {
                answer = max(
                    answer,
                    length
                );
            }
        }

        return answer;
    }
};
