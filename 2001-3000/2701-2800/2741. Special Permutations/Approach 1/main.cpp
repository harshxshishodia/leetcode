class Solution {
    bool valid(
        const vector<int>& permutation
    ) {
        for (int index = 1;
             index < static_cast<int>(permutation.size());
             index++) {
            int first =
                permutation[index - 1];

            int second =
                permutation[index];

            if (first % second != 0 &&
                second % first != 0) {
                return false;
            }
        }

        return true;
    }

public:
    int specialPerm(vector<int>& nums) {
        const int MOD =
            1000000007;

        sort(
            nums.begin(),
            nums.end()
        );

        long long answer = 0;

        do {
            answer +=
                valid(nums);

            answer %=
                MOD;
        } while (next_permutation(
            nums.begin(),
            nums.end()
        ));

        return static_cast<int>(
            answer
        );
    }
};
