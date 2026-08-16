class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = static_cast<int>(s.size());
        int answer = n;

        for (int split = 0; split <= n; split++) {
            int flips = 0;

            for (int i = 0; i < split; i++) {
                if (s[i] == '1') {
                    flips++;
                }
            }

            for (int i = split; i < n; i++) {
                if (s[i] == '0') {
                    flips++;
                }
            }

            answer = min(answer, flips);
        }

        return answer;
    }
};
