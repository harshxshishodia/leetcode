class Solution {
    bool possible(
        const vector<int>& nums,
        long long limit
    ) {
        vector<long long> values(
            nums.begin(),
            nums.end()
        );

        for (int index =
                 static_cast<int>(values.size()) - 1;
             index >= 1;
             index--) {
            if (values[index] > limit) {
                long long excess =
                    values[index] -
                    limit;

                values[index] -=
                    excess;

                values[index - 1] +=
                    excess;
            }
        }

        return values[0] <= limit;
    }

public:
    int minimizeArrayValue(vector<int>& nums) {
        int maximum =
            *max_element(
                nums.begin(),
                nums.end()
            );

        for (int candidate = 0;
             candidate <= maximum;
             candidate++) {
            if (possible(
                    nums,
                    candidate)) {
                return candidate;
            }
        }

        return maximum;
    }
};
