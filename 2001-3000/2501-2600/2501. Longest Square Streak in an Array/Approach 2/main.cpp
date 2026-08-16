class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(
            nums.begin(),
            nums.end()
        );

        unordered_map<int, int> best;
        int answer = -1;

        for (int value : nums) {
            int length = 1;

            int root =
                static_cast<int>(
                    sqrt(
                        static_cast<double>(value)
                    )
                );

            if (1LL *
                root *
                root ==
                value) {
                auto found =
                    best.find(
                        root
                    );

                if (found != best.end()) {
                    length =
                        found->second +
                        1;
                }
            }

            best[value] = max(
                best[value],
                length
            );

            if (best[value] >= 2) {
                answer = max(
                    answer,
                    best[value]
                );
            }
        }

        return answer;
    }
};
