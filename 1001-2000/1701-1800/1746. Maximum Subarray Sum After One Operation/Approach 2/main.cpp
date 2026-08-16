class Solution {
public:
    int maxSumAfterOperation(vector<int>& nums) {
        int n =
            static_cast<int>(nums.size());

        vector<int> left(n);
        vector<int> right(n);

        left[0] = nums[0];

        for (int i = 1; i < n; i++) {
            left[i] = max(
                nums[i],
                left[i - 1] + nums[i]
            );
        }

        right[n - 1] =
            nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            right[i] = max(
                nums[i],
                right[i + 1] + nums[i]
            );
        }

        int answer =
            numeric_limits<int>::min();

        for (int i = 0; i < n; i++) {
            int candidate =
                nums[i] *
                nums[i];

            if (i > 0) {
                candidate +=
                    max(
                        0,
                        left[i - 1]
                    );
            }

            if (i + 1 < n) {
                candidate +=
                    max(
                        0,
                        right[i + 1]
                    );
            }

            answer = max(
                answer,
                candidate
            );
        }

        return answer;
    }
};
