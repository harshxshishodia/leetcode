class Solution {
    struct State {
        long double minimum;
        long double maximum;
        string minimumExpression;
        string maximumExpression;
    };

    map<pair<int, int>, State> memo;

    State solve(
        const vector<int>& nums,
        int left,
        int right
    ) {
        if (left == right) {
            string value = to_string(nums[left]);

            return {
                static_cast<long double>(nums[left]),
                static_cast<long double>(nums[left]),
                value,
                value
            };
        }

        pair<int, int> key = {left, right};

        if (memo.count(key)) {
            return memo[key];
        }

        State answer = {
            numeric_limits<long double>::infinity(),
            -numeric_limits<long double>::infinity(),
            "",
            ""
        };

        for (int split = left; split < right; split++) {
            State first = solve(nums, left, split);
            State second = solve(nums, split + 1, right);

            long double maximumValue =
                first.maximum / second.minimum;

            long double minimumValue =
                first.minimum / second.maximum;

            string maximumRight =
                split + 1 < right
                    ? "(" + second.minimumExpression + ")"
                    : second.minimumExpression;

            string minimumRight =
                split + 1 < right
                    ? "(" + second.maximumExpression + ")"
                    : second.maximumExpression;

            if (maximumValue > answer.maximum) {
                answer.maximum = maximumValue;
                answer.maximumExpression =
                    first.maximumExpression +
                    "/" +
                    maximumRight;
            }

            if (minimumValue < answer.minimum) {
                answer.minimum = minimumValue;
                answer.minimumExpression =
                    first.minimumExpression +
                    "/" +
                    minimumRight;
            }
        }

        memo[key] = answer;
        return memo[key];
    }

public:
    string optimalDivision(vector<int>& nums) {
        memo.clear();

        return solve(
            nums,
            0,
            static_cast<int>(nums.size()) - 1
        ).maximumExpression;
    }
};
