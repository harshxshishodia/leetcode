class Solution {
    bool palindrome(
        const string& s,
        int mask
    ) {
        string value;

        for (int index = 0;
             index < static_cast<int>(s.size());
             index++) {
            if ((mask & (1 << index)) != 0) {
                value.push_back(
                    s[index]
                );
            }
        }

        int left = 0;
        int right =
            static_cast<int>(value.size()) -
            1;

        while (left < right) {
            if (value[left] != value[right]) {
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

            for (int second = first + 1;
                 second < states;
                 second++) {
                if ((first & second) == 0 &&
                    length[second] > 0) {
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
