class Solution {
    vector<vector<int>> memo;
    vector<bool> visited;

    vector<int> solve(
        const vector<int>& nums,
        int index
    ) {
        if (visited[index]) {
            return memo[index];
        }

        visited[index] = true;
        vector<int> best = {nums[index]};

        for (int next = index + 1;
             next < static_cast<int>(nums.size());
             next++) {
            if (nums[next] % nums[index] != 0) {
                continue;
            }

            vector<int> candidate = solve(nums, next);
            candidate.insert(candidate.begin(), nums[index]);

            if (candidate.size() > best.size()) {
                best = candidate;
            }
        }

        memo[index] = best;
        return memo[index];
    }

public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = static_cast<int>(nums.size());
        memo.assign(n, {});
        visited.assign(n, false);

        vector<int> answer;

        for (int i = 0; i < n; i++) {
            vector<int> candidate = solve(nums, i);

            if (candidate.size() > answer.size()) {
                answer = candidate;
            }
        }

        return answer;
    }
};
