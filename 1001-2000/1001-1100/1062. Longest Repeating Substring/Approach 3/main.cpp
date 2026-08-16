class Solution {
    vector<int> buildSuffixArray(
        const string& s
    ) {
        int n = static_cast<int>(s.size());

        vector<int> suffix(n);
        vector<int> rank(n);
        vector<int> nextRank(n);

        for (int i = 0; i < n; i++) {
            suffix[i] = i;
            rank[i] =
                static_cast<unsigned char>(s[i]);
        }

        for (int length = 1;
             length < n;
             length *= 2) {
            sort(
                suffix.begin(),
                suffix.end(),
                [&](int first, int second) {
                    if (rank[first] != rank[second]) {
                        return rank[first] < rank[second];
                    }

                    int firstNext =
                        first + length < n
                            ? rank[first + length]
                            : -1;

                    int secondNext =
                        second + length < n
                            ? rank[second + length]
                            : -1;

                    return firstNext < secondNext;
                }
            );

            nextRank[suffix[0]] = 0;

            for (int i = 1; i < n; i++) {
                int previous =
                    suffix[i - 1];

                int current =
                    suffix[i];

                bool different =
                    rank[previous] != rank[current];

                if (!different) {
                    int previousNext =
                        previous + length < n
                            ? rank[previous + length]
                            : -1;

                    int currentNext =
                        current + length < n
                            ? rank[current + length]
                            : -1;

                    different =
                        previousNext != currentNext;
                }

                nextRank[current] =
                    nextRank[previous] +
                    different;
            }

            rank = nextRank;

            if (rank[suffix[n - 1]] == n - 1) {
                break;
            }
        }

        return suffix;
    }

public:
    int longestRepeatingSubstring(string s) {
        int n = static_cast<int>(s.size());

        if (n <= 1) {
            return 0;
        }

        vector<int> suffix =
            buildSuffixArray(s);

        vector<int> rank(n);

        for (int i = 0; i < n; i++) {
            rank[suffix[i]] = i;
        }

        int length = 0;
        int answer = 0;

        for (int i = 0; i < n; i++) {
            int position =
                rank[i];

            if (position == n - 1) {
                length = 0;
                continue;
            }

            int j =
                suffix[position + 1];

            while (i + length < n &&
                   j + length < n &&
                   s[i + length] == s[j + length]) {
                length++;
            }

            answer = max(
                answer,
                length
            );

            if (length > 0) {
                length--;
            }
        }

        return answer;
    }
};
