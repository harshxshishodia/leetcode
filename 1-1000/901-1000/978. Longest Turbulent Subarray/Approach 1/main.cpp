class Solution {
    bool turbulent(
        const vector<int>& arr,
        int left,
        int right
    ) {
        for (int i = left + 1; i <= right; i++) {
            if (arr[i] == arr[i - 1]) {
                return false;
            }

            if (i >= left + 2) {
                long long first =
                    static_cast<long long>(arr[i - 1]) -
                    arr[i - 2];

                long long second =
                    static_cast<long long>(arr[i]) -
                    arr[i - 1];

                if ((first > 0) == (second > 0)) {
                    return false;
                }
            }
        }

        return true;
    }

public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = static_cast<int>(arr.size());
        int answer = 1;

        for (int left = 0; left < n; left++) {
            for (int right = left; right < n; right++) {
                if (turbulent(
                        arr,
                        left,
                        right)) {
                    answer = max(
                        answer,
                        right - left + 1
                    );
                }
            }
        }

        return answer;
    }
};
