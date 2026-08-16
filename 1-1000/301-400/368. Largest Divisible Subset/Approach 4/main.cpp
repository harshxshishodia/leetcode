class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = static_cast<int>(nums.size());
        vector<int> length(n, 1);
        vector<int> parent(n, -1);
        int bestIndex = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 &&
                    length[j] + 1 > length[i]) {
                    length[i] = length[j] + 1;
                    parent[i] = j;
                }
            }

            if (length[i] > length[bestIndex]) {
                bestIndex = i;
            }
        }

        vector<int> answer;

        while (bestIndex != -1) {
            answer.push_back(nums[bestIndex]);
            bestIndex = parent[bestIndex];
        }

        reverse(answer.begin(), answer.end());
        return answer;
    }
};
