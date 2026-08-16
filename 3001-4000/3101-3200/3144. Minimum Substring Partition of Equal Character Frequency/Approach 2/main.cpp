class Solution {
    vector<int> memo;

    int solve(
        const string& s,
        int index
    ) {
        if (index ==
            static_cast<int>(s.size())) {
            return 0;
        }

        if (memo[index] != -1) {
            return memo[index];
        }

        array<int, 26> frequency = {};

        int maximum = 0;
        int distinct = 0;

        int answer =
            static_cast<int>(
                s.size()
            );

        for (int end = index;
             end < static_cast<int>(s.size());
             end++) {
            int character =
                s[end] -
                'a';

            if (frequency[character] == 0) {
                distinct++;
            }

            frequency[character]++;

            maximum = max(
                maximum,
                frequency[character]
            );

            int length =
                end -
                index +
                1;

            if (
                maximum *
                distinct ==
                length
            ) {
                answer = min(
                    answer,
                    1 +
                    solve(
                        s,
                        end + 1
                    )
                );
            }
        }

        memo[index] =
            answer;

        return answer;
    }

public:
    int minimumSubstringsInPartition(
        string s
    ) {
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
