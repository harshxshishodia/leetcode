class Solution {
public:
    long long countTheNumOfKFreeSubsets(
        vector<int>& nums,
        int k
    ) {
        if (k == 0) {
            return
                1LL <<
                nums.size();
        }

        map<int, vector<int>> groups;

        for (int value : nums) {
            groups[value % k].push_back(
                value
            );
        }

        long long answer = 1;

        for (auto& [remainder, values] :
             groups) {
            sort(
                values.begin(),
                values.end()
            );

            long long skip = 1;
            long long take = 0;

            int previous =
                numeric_limits<int>::min();

            for (int value : values) {
                long long nextSkip =
                    skip +
                    take;

                long long nextTake;

                if (previous !=
                        numeric_limits<int>::min() &&
                    value -
                        previous ==
                        k) {
                    nextTake =
                        skip;
                } else {
                    nextTake =
                        skip +
                        take;
                }

                skip =
                    nextSkip;

                take =
                    nextTake;

                previous =
                    value;
            }

            answer *=
                skip +
                take;
        }

        return answer;
    }
};
