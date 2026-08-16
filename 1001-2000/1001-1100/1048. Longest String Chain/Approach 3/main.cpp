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

public:
    int longestStrChain(vector<string>& words) {
        sort(
            words.begin(),
            words.end(),
            [](const string& first, const string& second) {
                return first.size() < second.size();
            }
        );

        int n = static_cast<int>(words.size());
        vector<int> dp(
            n,
            1
        );

        int answer = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (predecessor(
                        words[j],
                        words[i])) {
                    dp[i] = max(
                        dp[i],
                        dp[j] + 1
                    );
                }
            }

            answer = max(
                answer,
                dp[i]
            );
        }

        return answer;
    }
};
