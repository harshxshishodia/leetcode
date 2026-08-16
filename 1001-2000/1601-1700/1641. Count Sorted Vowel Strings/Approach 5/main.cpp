class Solution {
public:
    int countVowelStrings(int n) {
        long long a =
            n + 1LL;

        long long b =
            n + 2LL;

        long long c =
            n + 3LL;

        long long d =
            n + 4LL;

        return static_cast<int>(
            a *
            b *
            c *
            d /
            24
        );
    }
};
