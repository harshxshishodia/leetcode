class Solution {
public:
    int longestSubsequence(
        string s,
        int k
    ) {
        int answer = 0;
        long long value = 0;
        long long place = 1;

        for (int index =
                 static_cast<int>(s.size()) - 1;
             index >= 0;
             index--) {
            if (s[index] == '0') {
                answer++;
            } else if (place <= k &&
                       value + place <= k) {
                value += place;
                answer++;
            }

            if (place <= k) {
                place *= 2;
            }
        }

        return answer;
    }
};
