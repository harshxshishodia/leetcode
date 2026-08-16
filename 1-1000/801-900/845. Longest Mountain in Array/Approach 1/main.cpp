class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = static_cast<int>(arr.size());
        int answer = 0;

        for (int peak = 1; peak + 1 < n; peak++) {
            if (arr[peak - 1] >= arr[peak] ||
                arr[peak] <= arr[peak + 1]) {
                continue;
            }

            int left = peak;
            int right = peak;

            while (left > 0 &&
                   arr[left - 1] < arr[left]) {
                left--;
            }

            while (right + 1 < n &&
                   arr[right] > arr[right + 1]) {
                right++;
            }

            answer = max(
                answer,
                right - left + 1
            );
        }

        return answer;
    }
};
