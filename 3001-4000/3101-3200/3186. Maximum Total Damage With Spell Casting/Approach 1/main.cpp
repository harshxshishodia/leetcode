class Solution {
    long long answer = 0;

    bool valid(
        const vector<int>& power,
        const vector<int>& chosen
    ) {
        for (int first = 0;
             first < static_cast<int>(chosen.size());
             first++) {
            for (int second = first + 1;
                 second < static_cast<int>(chosen.size());
                 second++) {
                int difference =
                    abs(
                        power[chosen[first]] -
                        power[chosen[second]]
                    );

                if (difference == 1 ||
                    difference == 2) {
                    return false;
                }
            }
        }

        return true;
    }

    void search(
        const vector<int>& power,
        int index,
        vector<int>& chosen,
        long long total
    ) {
        if (index ==
            static_cast<int>(power.size())) {
            if (valid(
                    power,
                    chosen)) {
                answer = max(
                    answer,
                    total
                );
            }

            return;
        }

        search(
            power,
            index + 1,
            chosen,
            total
        );

        chosen.push_back(
            index
        );

        search(
            power,
            index + 1,
            chosen,
            total +
            power[index]
        );

        chosen.pop_back();
    }

public:
    long long maximumTotalDamage(vector<int>& power) {
        answer = 0;

        vector<int> chosen;

        search(
            power,
            0,
            chosen,
            0
        );

        return answer;
    }
};
