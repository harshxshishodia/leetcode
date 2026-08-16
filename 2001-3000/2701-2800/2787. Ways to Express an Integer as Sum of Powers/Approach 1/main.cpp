class Solution {
    static constexpr int MOD = 1000000007;

    vector<int> buildPowers(int n, int x) {
        vector<int> powers;

        for (int base = 1; ; base++) {
            long long value = 1;

            for (int exponent = 0; exponent < x; exponent++) {
                value *= base;

                if (value > n) {
                    break;
                }
            }

            if (value > n) {
                break;
            }

            powers.push_back(static_cast<int>(value));
        }

        return powers;
    }

    int solve(const vector<int>& powers, int index, int remaining) {
        if (remaining == 0) {
            return 1;
        }

        if (index == static_cast<int>(powers.size()) || remaining < 0) {
            return 0;
        }

        long long answer = solve(powers, index + 1, remaining);

        if (powers[index] <= remaining) {
            answer += solve(
                powers,
                index + 1,
                remaining - powers[index]
            );
        }

        return static_cast<int>(answer % MOD);
    }

public:
    int numberOfWays(int n, int x) {
        vector<int> powers = buildPowers(n, x);
        return solve(powers, 0, n);
    }
};
