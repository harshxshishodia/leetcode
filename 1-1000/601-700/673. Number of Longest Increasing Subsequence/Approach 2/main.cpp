class Solution {
    pair<int, int> solve(
        const vector<int>& nums,
        int index
    ) {
        int bestLength = 1;
        int count = 1;

        for (int next = index + 1;
             next < static_cast<int>(nums.size());
             next++) {
            if (nums[next] <= nums[index]) {
                continue;
            }

            auto [nextLength, nextCount] =
                solve(nums, next);

            int candidateLength =
                1 + nextLength;

            if (candidateLength > bestLength) {
                bestLength = candidateLength;
                count = nextCount;
            } else if (candidateLength == bestLength) {
                count += nextCount;
            }
        }

        return {
            bestLength,
            count
        };
    }

public:
    int findNumberOfLIS(vector<int>& nums) {
        int bestLength = 0;
        int answer = 0;

        for (int i = 0; i < static_cast<int>(nums.size()); i++) {
            auto [length, count] = solve(nums, i);

            if (length > bestLength) {
                bestLength = length;
                answer = count;
            } else if (length == bestLength) {
                answer += count;
            }
        }

        return answer;
    }
};
