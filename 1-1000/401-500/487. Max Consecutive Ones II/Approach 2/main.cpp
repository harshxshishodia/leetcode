class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int withoutFlip = 0;
        int withFlip = 0;
        int answer = 0;

        for (int value : nums) {
            if (value == 1) {
                withoutFlip++;
                withFlip++;
            } else {
                withFlip = withoutFlip + 1;
                withoutFlip = 0;
            }

            answer = max(answer, withFlip);
        }

        return answer;
    }
};
