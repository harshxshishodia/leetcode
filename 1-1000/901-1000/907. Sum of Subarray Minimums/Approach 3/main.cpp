class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1000000007;

        vector<pair<int, int>> stack;
        long long endingSum = 0;
        long long answer = 0;

        for (int value : arr) {
            int count = 1;

            while (!stack.empty() &&
                   stack.back().first >= value) {
                endingSum -=
                    1LL *
                    stack.back().first *
                    stack.back().second;

                count +=
                    stack.back().second;

                stack.pop_back();
            }

            stack.push_back({
                value,
                count
            });

            endingSum +=
                1LL *
                value *
                count;

            endingSum %= MOD;

            answer +=
                endingSum;

            answer %= MOD;
        }

        return static_cast<int>(answer);
    }
};
