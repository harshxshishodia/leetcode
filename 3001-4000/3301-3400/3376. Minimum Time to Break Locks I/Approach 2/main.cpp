class Solution {
    int answer;

    void search(
        const vector<int>& strength,
        int K,
        int broken,
        vector<bool>& used,
        int time
    ) {
        if (broken ==
            static_cast<int>(strength.size())) {
            answer = min(
                answer,
                time
            );

            return;
        }

        int factor =
            1 +
            broken *
            K;

        for (int index = 0;
             index < static_cast<int>(strength.size());
             index++) {
            if (used[index]) {
                continue;
            }

            used[index] =
                true;

            int minutes =
                (
                    strength[index] +
                    factor -
                    1
                ) /
                factor;

            search(
                strength,
                K,
                broken + 1,
                used,
                time +
                minutes
            );

            used[index] =
                false;
        }
    }

public:
    int findMinimumTime(
        vector<int>& strength,
        int K
    ) {
        answer =
            numeric_limits<int>::max();

        vector<bool> used(
            strength.size()
        );

        search(
            strength,
            K,
            0,
            used,
            0
        );

        return answer;
    }
};
