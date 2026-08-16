class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int withoutDeletion = 0;
        int withDeletion = 0;
        int answer = 0;

        for (int value : nums) {
            if (value == 1) {
                withoutDeletion++;
                withDeletion++;
            } else {
                withDeletion =
                    withoutDeletion;

                withoutDeletion = 0;
            }

            answer = max(
                answer,
                withDeletion
            );
        }

        if (answer == static_cast<int>(nums.size())) {
            return answer - 1;
        }

        return answer;
    }
};
