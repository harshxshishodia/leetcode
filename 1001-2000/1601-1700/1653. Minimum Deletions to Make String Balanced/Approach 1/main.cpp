class Solution {
public:
    int minimumDeletions(string s) {
        int n =
            static_cast<int>(s.size());

        int answer = n;

        for (int split = 0; split <= n; split++) {
            int deletions = 0;

            for (int i = 0; i < split; i++) {
                if (s[i] == 'b') {
                    deletions++;
                }
            }

            for (int i = split; i < n; i++) {
                if (s[i] == 'a') {
                    deletions++;
                }
            }

            answer = min(
                answer,
                deletions
            );
        }

        return answer;
    }
};
