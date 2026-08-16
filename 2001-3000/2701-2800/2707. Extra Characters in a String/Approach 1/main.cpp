class Solution {
    unordered_set<string> words;

    int solve(
        const string& s,
        int index
    ) {
        if (index == static_cast<int>(s.size())) {
            return 0;
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

        return answer;
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

        return solve(
            s,
            0
        );
    }
};
