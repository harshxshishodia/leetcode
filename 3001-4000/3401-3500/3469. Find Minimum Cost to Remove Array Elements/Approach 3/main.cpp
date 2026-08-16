class Solution {
public:
    int minCost(vector<int>& nums) {
        int n =
            static_cast<int>(nums.size());

        if (n < 3) {
            return *max_element(
                nums.begin(),
                nums.end()
            );
        }

        const int INF =
            1000000000;

        vector<int> current(
            n,
            INF
        );

        current[0] =
            0;

        for (int nextIndex = 1;
             nextIndex + 1 < n;
             nextIndex += 2) {
            vector<int> next(
                n,
                INF
            );

            for (int carried = 0;
                 carried < nextIndex;
                 carried++) {
                if (current[carried] == INF) {
                    continue;
                }

                int first =
                    carried;

                int second =
                    nextIndex;

                int third =
                    nextIndex + 1;

                next[first] = min(
                    next[first],
                    current[carried] +
                    max(
                        nums[second],
                        nums[third]
                    )
                );

                next[second] = min(
                    next[second],
                    current[carried] +
                    max(
                        nums[first],
                        nums[third]
                    )
                );

                next[third] = min(
                    next[third],
                    current[carried] +
                    max(
                        nums[first],
                        nums[second]
                    )
                );
            }

            current.swap(
                next
            );
        }

        int nextIndex =
            1 +
            2 *
            (
                (n - 1) /
                2
            );

        int answer =
            INF;

        for (int carried = 0;
             carried < n;
             carried++) {
            if (current[carried] == INF) {
                continue;
            }

            if (n % 2 == 1) {
                answer = min(
                    answer,
                    current[carried] +
                    nums[carried]
                );
            } else {
                answer = min(
                    answer,
                    current[carried] +
                    max(
                        nums[carried],
                        nums[n - 1]
                    )
                );
            }
        }

        return answer;
    }
};
