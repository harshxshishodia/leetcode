class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n =
            static_cast<int>(arr.size());

        vector<int> left(n);
        vector<int> right(n);

        left[0] = arr[0];

        for (int i = 1; i < n; i++) {
            left[i] = max(
                arr[i],
                left[i - 1] + arr[i]
            );
        }

        right[n - 1] =
            arr[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            right[i] = max(
                arr[i],
                right[i + 1] + arr[i]
            );
        }

        int answer =
            *max_element(
                left.begin(),
                left.end()
            );

        for (int deleted = 1;
             deleted + 1 < n;
             deleted++) {
            answer = max(
                answer,
                left[deleted - 1] +
                right[deleted + 1]
            );
        }

        return answer;
    }
};
