class Solution {
    bool predecessor(
        const string& shorter,
        const string& longer
    ) {
        if (longer.size() != shorter.size() + 1) {
            return false;
        }

        int first = 0;
        int second = 0;

        while (second < static_cast<int>(longer.size())) {
            if (first < static_cast<int>(shorter.size()) &&
                shorter[first] == longer[second]) {
                first++;
            }

            second++;
        }

        return first ==
               static_cast<int>(shorter.size());
    }

    int solve(
        const vector<string>& words,
        int index,
        vector<int>& memo
    ) {
        if (memo[index] != -1) {
            return memo[index];
        }

        int answer = 1;

        for (int next = index + 1;
             next < static_cast<int>(words.size());
             next++) {
            if (predecessor(
                    words[index],
                    words[next])) {
                answer = max(
                    answer,
                    1 +
                    solve(
                        words,
                        next,
                        memo
                    )
                );
            }
        }

        memo[index] = answer;
        return memo[index];
    }

public:
    int longestStrChain(vector<string>& words) {
        sort(
            words.begin(),
            words.end(),
            [](const string& first, const string& second) {
                return first.size() < second.size();
            }
        );

        vector<int> memo(
            words.size(),
            -1
        );

        int answer = 0;

        for (int i = 0;
             i < static_cast<int>(words.size());
             i++) {
            answer = max(
                answer,
                solve(
                    words,
                    i,
                    memo
                )
            );
        }

        return answer;
    }
};
