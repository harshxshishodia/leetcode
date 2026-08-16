class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = static_cast<int>(s.size());
        vector<int> ones(n + 1);
        vector<int> zeroes(n + 1);

        for (int i = 0; i < n; i++) {
            ones[i + 1] =
                ones[i] +
                (s[i] == '1');
        }

        for (int i = n - 1; i >= 0; i--) {
            zeroes[i] =
                zeroes[i + 1] +
                (s[i] == '0');
        }

        int answer = n;

        for (int split = 0; split <= n; split++) {
            answer = min(
                answer,
                ones[split] +
                zeroes[split]
            );
        }

        return answer;
    }
};
