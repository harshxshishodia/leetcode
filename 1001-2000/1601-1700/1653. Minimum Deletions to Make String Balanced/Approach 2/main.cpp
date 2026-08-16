class Solution {
public:
    int minimumDeletions(string s) {
        int n =
            static_cast<int>(s.size());

        vector<int> bPrefix(
            n + 1
        );

        vector<int> aSuffix(
            n + 1
        );

        for (int i = 0; i < n; i++) {
            bPrefix[i + 1] =
                bPrefix[i] +
                (s[i] == 'b');
        }

        for (int i = n - 1; i >= 0; i--) {
            aSuffix[i] =
                aSuffix[i + 1] +
                (s[i] == 'a');
        }

        int answer = n;

        for (int split = 0; split <= n; split++) {
            answer = min(
                answer,
                bPrefix[split] +
                aSuffix[split]
            );
        }

        return answer;
    }
};
