class Solution {
    vector<int> solve(
        const vector<int>& nums,
        int index
    ) {
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

        return best;
    }

public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> answer;

        for (int i = 0; i < static_cast<int>(nums.size()); i++) {
            vector<int> candidate = solve(nums, i);

            if (candidate.size() > answer.size()) {
                answer = candidate;
            }
        }

        return answer;
    }
};
