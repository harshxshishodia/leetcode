class Solution {
public:
    int totalSteps(vector<int>& nums) {
        vector<pair<int, int>> stack;
        int answer = 0;

        for (int value : nums) {
            int steps = 0;

            while (!stack.empty() &&
                   value >=
                   stack.back().first) {
                steps = max(
                    steps,
                    stack.back().second
                );

                stack.pop_back();
            }

            if (stack.empty()) {
                steps = 0;
            } else {
                steps++;
            }

            answer = max(
                answer,
                steps
            );

            stack.push_back({
                value,
                steps
            });
        }

        return answer;
    }
};
