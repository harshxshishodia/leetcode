class Solution {
public:
    int beautifulSubsets(
        vector<int>& nums,
        int k
    ) {
        map<int, map<int, int>> groups;

        for (int value : nums) {
            groups[value % k][value]++;
        }

        long long total = 1;

        for (auto& [remainder, frequency] :
             groups) {
            long long skip = 1;
            long long take = 0;

            int previousValue =
                numeric_limits<int>::min();

            for (auto [value, count] :
                 frequency) {
                long long choices =
                    (1LL << count) -
                    1;

                long long nextSkip =
                    skip +
                    take;

                long long nextTake;

                if (previousValue !=
                        numeric_limits<int>::min() &&
                    value -
                        previousValue ==
                        k) {
                    nextTake =
                        skip *
                        choices;
                } else {
                    nextTake =
                        (
                            skip +
                            take
                        ) *
                        choices;
                }

                skip =
                    nextSkip;

                take =
                    nextTake;

                previousValue =
                    value;
            }

            total *=
                skip +
                take;
        }

        return static_cast<int>(
            total - 1
        );
    }
};
