class Solution {
    unordered_set<string> words;
    vector<int> memo;

    int solve(
        const string& s,
        int index
    ) {
        if (index == static_cast<int>(s.size())) {
            return 0;
        }

        if (memo[index] != -1) {
            return memo[index];
        }

        int answer =
            1 +
            solve(
                s,
                index + 1
            );

        string current;

        for (int end = index;
             end < static_cast<int>(s.size());
             end++) {
            current.push_back(
                s[end]
            );

            if (words.count(current)) {
                answer = min(
                    answer,
                    solve(
                        s,
                        end + 1
                    )
                );
            }
        }

        memo[index] =
            answer;

        return memo[index];
    }

public:
    int minExtraChar(
        string s,
        vector<string>& dictionary
    ) {
        words = unordered_set<string>(
            dictionary.begin(),
            dictionary.end()
        );

        memo.assign(
            s.size(),
            -1
        );

        return solve(
            s,
            0
        );
    }
};
