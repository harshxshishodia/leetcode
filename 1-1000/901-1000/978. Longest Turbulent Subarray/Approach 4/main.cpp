class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = static_cast<int>(arr.size());
        int left = 0;
        int answer = 1;

        for (int right = 1; right < n; right++) {
            int comparison =
                arr[right - 1] < arr[right]
                    ? -1
                    : arr[right - 1] > arr[right]
                        ? 1
                        : 0;

            if (comparison == 0) {
                left = right;
            } else if (right == n - 1 ||
                       comparison *
                       (
                           arr[right] < arr[right + 1]
                               ? -1
                               : arr[right] > arr[right + 1]
                                   ? 1
                                   : 0
                       ) != -1) {
                answer = max(
                    answer,
                    right - left + 1
                );

                left = right;
            }
        }

        return answer;
    }
};
