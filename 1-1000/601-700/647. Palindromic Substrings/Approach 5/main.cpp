class Solution {
public:
    int countSubstrings(string s) {
        int n = static_cast<int>(s.size());
        vector<int> odd(n);
        vector<int> even(n);

        int left = 0;
        int right = -1;

        for (int i = 0; i < n; i++) {
            int radius =
                i > right
                    ? 1
                    : min(
                        odd[left + right - i],
                        right - i + 1
                    );

            while (i - radius >= 0 &&
                   i + radius < n &&
                   s[i - radius] == s[i + radius]) {
                radius++;
            }

            odd[i] = radius;

            if (i + radius - 1 > right) {
                left = i - radius + 1;
                right = i + radius - 1;
            }
        }

        left = 0;
        right = -1;

        for (int i = 0; i < n; i++) {
            int radius =
                i > right
                    ? 0
                    : min(
                        even[left + right - i + 1],
                        right - i + 1
                    );

            while (i - radius - 1 >= 0 &&
                   i + radius < n &&
                   s[i - radius - 1] == s[i + radius]) {
                radius++;
            }

            even[i] = radius;

            if (i + radius - 1 > right) {
                left = i - radius;
                right = i + radius - 1;
            }
        }

        long long answer = 0;

        for (int radius : odd) {
            answer += radius;
        }

        for (int radius : even) {
            answer += radius;
        }

        return static_cast<int>(answer);
    }
};
