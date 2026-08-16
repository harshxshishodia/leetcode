class Solution {
    int solve(
        const vector<int>& nums,
        int index
    ) {
        int n =
            static_cast<int>(nums.size());

        if (index == n) {
            return 0;
        }

        const int INF =
            1000000000;

        int answer = INF;
        int currentGcd = 0;

        for (int end = index; end < n; end++) {
            currentGcd =
                gcd(
                    currentGcd,
                    nums[end]
                );

            if (currentGcd <= 1) {
                continue;
            }

            int next =
                solve(
                    nums,
                    end + 1
                );

            if (next != INF) {
                answer = min(
                    answer,
                    1 + next
                );
            }
        }

        return answer;
    }

public:
    int minimumSplits(vector<int>& nums) {
        const int INF =
            1000000000;

        int answer =
            solve(
                nums,
                0
            );

        return answer == INF
            ? -1
            : answer;
    }
};
