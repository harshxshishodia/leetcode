class Solution {
    unordered_set<string> valid;

    int solve(
        const string& target,
        int index
    ) {
        if (index ==
            static_cast<int>(target.size())) {
            return 0;
        }

        const int INF =
            1000000000;

        int answer =
            INF;

        string current;

        for (int end = index;
             end < static_cast<int>(target.size());
             end++) {
            current.push_back(
                target[end]
            );

            if (!valid.count(current)) {
                continue;
            }

            int next =
                solve(
                    target,
                    end + 1
                );

            if (next != INF) {
                answer = min(
                    answer,
                    1 +
                    next
                );
            }
        }

        return answer;
    }

public:
    int minValidStrings(
        vector<string>& words,
        string target
    ) {
        valid.clear();

        for (const string& word :
             words) {
            string prefix;

            for (char character :
                 word) {
                prefix.push_back(
                    character
                );

                valid.insert(
                    prefix
                );
            }
        }

        int answer =
            solve(
                target,
                0
            );

        return answer >=
                1000000000
            ? -1
            : answer;
    }
};
