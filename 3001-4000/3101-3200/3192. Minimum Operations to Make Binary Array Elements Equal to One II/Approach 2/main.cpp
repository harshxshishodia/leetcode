class Solution {
public:
    int minOperations(vector<int>& nums) {
        int answer = 0;
        int n =
            static_cast<int>(nums.size());

        for (int index = 0;
             index < n;
             index++) {
            if (nums[index] == 1) {
                continue;
            }

            answer++;

            for (int current = index;
                 current < n;
                 current++) {
                nums[current] ^=
                    1;
            }
        }

        return answer;
    }
};
