class Solution {
    array<int, 10> primes = {
        2,3,5,7,11,13,17,19,23,29
    };

    long long answer = 0;

    bool valid(
        const vector<int>& chosen
    ) {
        int used = 0;

        for (int value :
             chosen) {
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
                    return false;
                }

                if (count == 1) {
                    if ((used & (1 << bit)) != 0) {
                        return false;
                    }

                    used |=
                        1 << bit;
                }
            }
        }

        return true;
    }

    void search(
        const vector<int>& nums,
        int index,
        vector<int>& chosen
    ) {
        if (index ==
            static_cast<int>(nums.size())) {
            if (!chosen.empty() &&
                valid(chosen)) {
                answer++;
            }

            return;
        }

        search(
            nums,
            index + 1,
            chosen
        );

        chosen.push_back(
            nums[index]
        );

        search(
            nums,
            index + 1,
            chosen
        );

        chosen.pop_back();
    }

public:
    int squareFreeSubsets(vector<int>& nums) {
        const int MOD =
            1000000007;

        answer = 0;

        vector<int> chosen;

        search(
            nums,
            0,
            chosen
        );

        return static_cast<int>(
            answer %
            MOD
        );
    }
};
