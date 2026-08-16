class Solution {
    static constexpr int MOD =
        1000000007;

    array<int, 10> primes = {
        2,3,5,7,11,13,17,19,23,29
    };

    vector<int> masks;

    int buildMask(int value) {
        int mask = 0;

        for (int bit = 0; bit < 10; bit++) {
            int prime =
                primes[bit];

            int count = 0;

            while (value % prime == 0) {
                value /=
                    prime;

                count++;
            }

            if (count >= 2) {
                return -1;
            }

            if (count == 1) {
                mask |=
                    1 << bit;
            }
        }

        return mask;
    }

    long long search(
        int index,
        int used
    ) {
        if (index ==
            static_cast<int>(masks.size())) {
            return 1;
        }

        long long answer =
            search(
                index + 1,
                used
            );

        if (masks[index] != -1 &&
            (used & masks[index]) == 0) {
            answer +=
                search(
                    index + 1,
                    used |
                    masks[index]
                );
        }

        return answer %
               MOD;
    }

public:
    int squareFreeSubsets(vector<int>& nums) {
        masks.clear();

        for (int value : nums) {
            masks.push_back(
                buildMask(value)
            );
        }

        long long answer =
            search(
                0,
                0
            ) -
            1;

        if (answer < 0) {
            answer +=
                MOD;
        }

        return static_cast<int>(
            answer
        );
    }
};
