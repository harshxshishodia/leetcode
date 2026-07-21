class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> length(n, 1);
        vector<int> count(n, 1);
        int maximumLength = 1;

        for (int index = 0; index < n; index++) {
            for (int previous = 0; previous < index; previous++) {
                if (nums[previous] >= nums[index])
                    continue;

                if (length[previous] + 1 > length[index]) {
                    length[index] = length[previous] + 1;
                    count[index] = count[previous];
                } else if (length[previous] + 1 == length[index]) {
                    count[index] += count[previous];
                }
            }

            maximumLength = max(maximumLength, length[index]);
        }

        int answer = 0;

        for (int index = 0; index < n; index++) {
            if (length[index] == maximumLength)
                answer += count[index];
        }

        return answer;
    }
};