class Solution {
    int answer;

    void search(
        const vector<int>& nums,
        int index,
        int remaining,
        int capability
    ) {
        if (remaining == 0) {
            answer = min(
                answer,
                capability
            );

            return;
        }

        if (index >= static_cast<int>(nums.size()) ||
            static_cast<int>(nums.size()) - index <
            2 * remaining - 1) {
            return;
        }

        search(
            nums,
            index + 1,
            remaining,
            capability
        );

        search(
            nums,
            index + 2,
            remaining - 1,
            max(
                capability,
                nums[index]
            )
        );
    }

public:
    int minCapability(
        vector<int>& nums,
        int k
    ) {
        answer =
            numeric_limits<int>::max();

        search(
            nums,
            0,
            k,
            0
        );

        return answer;
    }
};
