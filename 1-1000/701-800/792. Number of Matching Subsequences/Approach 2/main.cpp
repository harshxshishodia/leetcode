class Solution {
public:
    int numMatchingSubseq(
        string s,
        vector<string>& words
    ) {
        int n = static_cast<int>(s.size());

        vector<array<int, 26>> next(
            n + 1
        );

        next[n].fill(-1);

        for (int i = n - 1; i >= 0; i--) {
            next[i] = next[i + 1];
            next[i][s[i] - 'a'] = i;
        }

        int answer = 0;

        for (const string& word : words) {
            int position = 0;
            bool possible = true;

            for (char character : word) {
                if (position > n ||
                    next[position][character - 'a'] == -1) {
                    possible = false;
                    break;
                }

                position =
                    next[position][character - 'a'] +
                    1;
            }

            if (possible) {
                answer++;
            }
        }

        return answer;
    }
};
