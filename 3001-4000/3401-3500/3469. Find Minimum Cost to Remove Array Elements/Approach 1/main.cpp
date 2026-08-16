class Solution {
    int solve(vector<int> nums) {
        if (nums.empty()) {
            return 0;
        }

        if (nums.size() < 3) {
            return *max_element(
                nums.begin(),
                nums.end()
            );
        }

        int answer =
            numeric_limits<int>::max();

        for (int first = 0;
             first < 3;
             first++) {
            for (int second = first + 1;
                 second < 3;
                 second++) {
                vector<int> next;

                for (int index = 0;
                     index < static_cast<int>(nums.size());
                     index++) {
                    if (
                        index == first ||
                        index == second
                    ) {
                        continue;
                    }

                    next.push_back(
                        nums[index]
                    );
                }

                answer = min(
                    answer,
                    max(
                        nums[first],
                        nums[second]
                    ) +
                    solve(next)
                );
            }
        }

        return answer;
    }

public:
    int minCost(vector<int>& nums) {
        return solve(nums);
    }
};
