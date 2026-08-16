class Solution {
    bool palindrome(
        const string& s,
        int mask
    ) {
        int left = 0;
        int right =
            static_cast<int>(s.size()) -
            1;

        while (left <= right) {
            while (left <= right &&
                   (mask & (1 << left)) == 0) {
                left++;
            }

            while (left <= right &&
                   (mask & (1 << right)) == 0) {
                right--;
            }

            if (left <= right) {
                if (s[left] != s[right]) {
                    return false;
                }

                left++;
                right--;
            }
        }

        return true;
    }

public:
    int maxProduct(string s) {
        int n =
            static_cast<int>(s.size());

        int states =
            1 << n;

        int full =
            states - 1;

        vector<int> best(states);

        for (int mask = 1; mask < states; mask++) {
            if (palindrome(
                    s,
                    mask)) {
                best[mask] =
                    __builtin_popcount(
                        static_cast<unsigned int>(mask)
                    );
            }
        }

        for (int bit = 0; bit < n; bit++) {
            for (int mask = 0; mask < states; mask++) {
                if ((mask & (1 << bit)) != 0) {
                    best[mask] = max(
                        best[mask],
                        best[
                            mask ^ (1 << bit)
                        ]
                    );
                }
            }
        }

        int answer = 0;

        for (int first = 1; first < states; first++) {
            if (!palindrome(
                    s,
                    first)) {
                continue;
            }

            int firstLength =
                __builtin_popcount(
                    static_cast<unsigned int>(first)
                );

            answer = max(
                answer,
                firstLength *
                best[full ^ first]
            );
        }

        return answer;
    }
};
