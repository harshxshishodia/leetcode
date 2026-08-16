class Solution {
    int answer = 0;

    bool valid(
        const vector<int>& chosen
    ) {
        int target =
            -1;

        for (int index = 1;
             index < static_cast<int>(chosen.size());
             index++) {
            int current =
                (
                    chosen[index - 1] +
                    chosen[index]
                ) %
                2;

            if (target == -1) {
                target =
                    current;
            } else if (target != current) {
                return false;
            }
        }

        return true;
    }

    void search(
        const vector<int>& nums,
        int index,
        vector<int>& chosen
    ) {
        if (index ==
            static_cast<int>(nums.size())) {
            if (valid(chosen)) {
                answer = max(
                    answer,
                    static_cast<int>(chosen.size())
                );
            }

            return;
        }

        search(
            nums,
            index + 1,
            chosen
        );

        chosen.push_back(
            nums[index]
        );

        search(
            nums,
            index + 1,
            chosen
        );

        chosen.pop_back();
    }

public:
    int maximumLength(vector<int>& nums) {
        answer =
            0;

        vector<int> chosen;

        search(
            nums,
            0,
            chosen
        );

        return answer;
    }
};
