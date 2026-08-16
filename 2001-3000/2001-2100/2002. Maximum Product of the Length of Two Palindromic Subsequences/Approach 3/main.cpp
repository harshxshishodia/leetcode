class Solution {
    bool palindrome(
        const string& s,
        int mask
    ) {
        vector<int> indices;

        for (int index = 0;
             index < static_cast<int>(s.size());
             index++) {
            if ((mask & (1 << index)) != 0) {
                indices.push_back(index);
            }
        }

        int left = 0;
        int right =
            static_cast<int>(indices.size()) -
            1;

        while (left < right) {
            if (s[indices[left]] !=
                s[indices[right]]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

public:
    int maxProduct(string s) {
        int states =
            1 << s.size();

        int full =
            states - 1;

        vector<int> length(states);

        for (int mask = 1; mask < states; mask++) {
            if (palindrome(
                    s,
                    mask)) {
                length[mask] =
                    __builtin_popcount(
                        static_cast<unsigned int>(mask)
                    );
            }
        }

        int answer = 0;

        for (int first = 1; first < states; first++) {
            if (length[first] == 0) {
                continue;
            }

            int available =
                full ^ first;

            for (int second = available;
                 second > 0;
                 second =
                 (second - 1) & available) {
                if (length[second] > 0) {
                    answer = max(
                        answer,
                        length[first] *
                        length[second]
                    );
                }
            }
        }

        return answer;
    }
};
