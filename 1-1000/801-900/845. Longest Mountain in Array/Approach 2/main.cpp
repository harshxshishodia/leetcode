class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = static_cast<int>(arr.size());

        vector<int> increasing(
            n,
            1
        );

        vector<int> decreasing(
            n,
            1
        );

        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i - 1]) {
                increasing[i] =
                    increasing[i - 1] + 1;
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] > arr[i + 1]) {
                decreasing[i] =
                    decreasing[i + 1] + 1;
            }
        }

        int answer = 0;

        for (int i = 1; i + 1 < n; i++) {
            if (increasing[i] > 1 &&
                decreasing[i] > 1) {
                answer = max(
                    answer,
                    increasing[i] +
                    decreasing[i] -
                    1
                );
            }
        }

        return answer;
    }
};
