class Solution {
public:
    int longestSubsequence(
        string s,
        int k
    ) {
        int n =
            static_cast<int>(s.size());

        int answer = 0;
        int states =
            1 << n;

        for (int mask = 0; mask < states; mask++) {
            long long value = 0;
            int length = 0;
            bool tooLarge = false;

            for (int index = 0; index < n; index++) {
                if ((mask & (1 << index)) == 0) {
                    continue;
                }

                value =
                    value *
                    2 +
                    (s[index] - '0');

                length++;

                if (value > k) {
                    tooLarge = true;
                    break;
                }
            }

            if (!tooLarge) {
                answer = max(
                    answer,
                    length
                );
            }
        }

        return answer;
    }
};
