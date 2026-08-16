class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = static_cast<int>(arr.size());
        int answer = 1;

        for (int left = 0; left < n; left++) {
            int previousSign = 0;

            for (int right = left + 1; right < n; right++) {
                int sign =
                    arr[right] > arr[right - 1]
                        ? 1
                        : arr[right] < arr[right - 1]
                            ? -1
                            : 0;

                if (sign == 0 ||
                    sign == previousSign) {
                    break;
                }

                answer = max(
                    answer,
                    right - left + 1
                );

                previousSign = sign;
            }
        }

        return answer;
    }
};
