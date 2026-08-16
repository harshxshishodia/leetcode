class Solution {
    int answer;

    void search(
        const vector<int>& nums,
        int index,
        int pairs,
        int maximum,
        vector<bool>& used
    ) {
        if (pairs == 0) {
            answer = min(
                answer,
                maximum
            );

            return;
        }

        int n =
            static_cast<int>(nums.size());

        if (index >= n) {
            return;
        }

        int first = index;

        while (first < n &&
               used[first]) {
            first++;
        }

        if (first >= n) {
            return;
        }

        search(
            nums,
            first + 1,
            pairs,
            maximum,
            used
        );

        used[first] = true;

        for (int second = first + 1;
             second < n;
             second++) {
            if (used[second]) {
                continue;
            }

            used[second] = true;

            search(
                nums,
                first + 1,
                pairs - 1,
                max(
                    maximum,
                    nums[second] -
                    nums[first]
                ),
                used
            );

            used[second] = false;
        }

        used[first] = false;
    }

public:
    int minimizeMax(
        vector<int>& nums,
        int p
    ) {
        if (p == 0) {
            return 0;
        }

        sort(
            nums.begin(),
            nums.end()
        );

        answer =
            numeric_limits<int>::max();

        vector<bool> used(
            nums.size()
        );

        search(
            nums,
            0,
            p,
            0,
            used
        );

        return answer;
    }
};
