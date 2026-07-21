class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 0);

        for (int index = 0; index < n; index++) {
            for (int right = index + 1; right < n; right++) {
                if (nums[right] < nums[index])
                    answer[index]++;
            }
        }

        return answer;
    }
};