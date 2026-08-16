class Solution {
public:
    int numSplits(string s) {
        int n =
            static_cast<int>(s.size());

        vector<int> prefix(n);
        vector<int> suffix(n);

        array<int, 26> count = {};
        int distinct = 0;

        for (int i = 0; i < n; i++) {
            int index =
                s[i] - 'a';

            if (count[index] == 0) {
                distinct++;
            }

            count[index]++;
            prefix[i] = distinct;
        }

        count.fill(0);
        distinct = 0;

        for (int i = n - 1; i >= 0; i--) {
            int index =
                s[i] - 'a';

            if (count[index] == 0) {
                distinct++;
            }

            count[index]++;
            suffix[i] = distinct;
        }

        int answer = 0;

        for (int split = 0; split + 1 < n; split++) {
            if (prefix[split] ==
                suffix[split + 1]) {
                answer++;
            }
        }

        return answer;
    }
};
