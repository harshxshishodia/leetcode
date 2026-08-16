class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1000000007;
        int n = static_cast<int>(arr.size());

        vector<int> previousLess(
            n
        );

        vector<int> nextLessOrEqual(
            n
        );

        stack<int> indices;

        for (int i = 0; i < n; i++) {
            while (!indices.empty() &&
                   arr[indices.top()] > arr[i]) {
                indices.pop();
            }

            previousLess[i] =
                indices.empty()
                    ? -1
                    : indices.top();

            indices.push(i);
        }

        while (!indices.empty()) {
            indices.pop();
        }

        for (int i = n - 1; i >= 0; i--) {
            while (!indices.empty() &&
                   arr[indices.top()] >= arr[i]) {
                indices.pop();
            }

            nextLessOrEqual[i] =
                indices.empty()
                    ? n
                    : indices.top();

            indices.push(i);
        }

        long long answer = 0;

        for (int i = 0; i < n; i++) {
            long long left =
                i - previousLess[i];

            long long right =
                nextLessOrEqual[i] - i;

            answer +=
                1LL *
                arr[i] *
                left *
                right;

            answer %= MOD;
        }

        return static_cast<int>(answer);
    }
};
