class Solution {
    long long answer = 0;
    unordered_set<int> selected;

    void search(
        const vector<int>& nums,
        int k,
        int index
    ) {
        if (index ==
            static_cast<int>(nums.size())) {
            answer++;
            return;
        }

        search(
            nums,
            k,
            index + 1
        );

        int value =
            nums[index];

        if (!selected.count(
                value - k) &&
            !selected.count(
                value + k)) {
            selected.insert(
                value
            );

            search(
                nums,
                k,
                index + 1
            );

            selected.erase(
                value
            );
        }
    }

public:
    long long countTheNumOfKFreeSubsets(
        vector<int>& nums,
        int k
    ) {
        selected.clear();
        answer = 0;

        search(
            nums,
            k,
            0
        );

        return answer;
    }
};
