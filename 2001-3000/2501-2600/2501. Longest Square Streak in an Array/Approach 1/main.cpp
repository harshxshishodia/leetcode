class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int answer = -1;

        for (int start :
             nums) {
            long long current =
                start;

            int length = 1;

            while (true) {
                long long next =
                    current *
                    current;

                bool found = false;

                for (int value : nums) {
                    if (value == next) {
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    break;
                }

                current =
                    next;

                length++;
            }

            if (length >= 2) {
                answer = max(
                    answer,
                    length
                );
            }
        }

        return answer;
    }
};
