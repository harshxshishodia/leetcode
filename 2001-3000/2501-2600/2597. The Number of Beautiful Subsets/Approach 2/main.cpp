class Solution {
    int answer = 0;
    unordered_map<int, int> selected;

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

        if (selected[value - k] == 0 &&
            selected[value + k] == 0) {
            selected[value]++;

            search(
                nums,
                k,
                index + 1
            );

            selected[value]--;
        }
    }

public:
    int beautifulSubsets(
        vector<int>& nums,
        int k
    ) {
        answer = 0;
        selected.clear();

        search(
            nums,
            k,
            0
        );

        return answer - 1;
    }
};
