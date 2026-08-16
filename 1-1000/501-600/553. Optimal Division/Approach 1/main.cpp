class Solution {
    struct Result {
        long double value;
        string expression;
    };

    vector<Result> solve(
        const vector<int>& nums,
        int left,
        int right
    ) {
        if (left == right) {
            return {{
                static_cast<long double>(nums[left]),
                to_string(nums[left])
            }};
        }

        vector<Result> answer;

        for (int split = left; split < right; split++) {
            vector<Result> first = solve(
                nums,
                left,
                split
            );

            vector<Result> second = solve(
                nums,
                split + 1,
                right
            );

            for (const Result& a : first) {
                for (const Result& b : second) {
                    string rightExpression = b.expression;

                    if (split + 1 < right) {
                        rightExpression =
                            "(" + rightExpression + ")";
                    }

                    answer.push_back({
                        a.value / b.value,
                        a.expression + "/" + rightExpression
                    });
                }
            }
        }

        return answer;
    }

public:
    string optimalDivision(vector<int>& nums) {
        vector<Result> results = solve(
            nums,
            0,
            static_cast<int>(nums.size()) - 1
        );

        Result best = results[0];

        for (const Result& result : results) {
            if (result.value > best.value) {
                best = result;
            }
        }

        return best.expression;
    }
};
