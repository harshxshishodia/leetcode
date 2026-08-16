class Solution {
    bool balanced(
        const string& s,
        int left,
        int right
    ) {
        array<int, 26> frequency = {};

        for (int index = left;
             index <= right;
             index++) {
            frequency[
                s[index] -
                'a'
            ]++;
        }

        int target = 0;

        for (int count :
             frequency) {
            if (count == 0) {
                continue;
            }

            if (target == 0) {
                target =
                    count;
            } else if (target != count) {
                return false;
            }
        }

        return true;
    }

    int solve(
        const string& s,
        int index
    ) {
        if (index ==
            static_cast<int>(s.size())) {
            return 0;
        }

        int answer =
            static_cast<int>(
                s.size()
            );

        for (int end = index;
             end < static_cast<int>(s.size());
             end++) {
            if (
                balanced(
                    s,
                    index,
                    end
                )
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

        return answer;
    }

public:
    int minimumSubstringsInPartition(
        string s
    ) {
        return solve(
            s,
            0
        );
    }
};
