class Solution {
    int solve(
        const vector<int>& nums,
        int index
    ) {
        int n =
            static_cast<int>(nums.size());

        if (index == n - 1) {
            return 0;
        }

        int answer = 0;

        for (int next = index + 1;
             next < n;
             next++) {
            answer = max(
                answer,
                (
                    next -
                    index
                ) *
                nums[next] +
                solve(
                    nums,
                    next
                )
            );
        }

        return answer;
    }

public:
    int maxScore(vector<int>& nums) {
        return solve(
            nums,
            0
        );
    }
};
