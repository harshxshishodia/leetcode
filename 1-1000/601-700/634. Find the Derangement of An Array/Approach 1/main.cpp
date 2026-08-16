class Solution {
    static constexpr int MOD = 1000000007;
    int answer;

    void generate(
        int n,
        int position,
        vector<int>& permutation,
        vector<bool>& used
    ) {
        if (position > n) {
            answer++;

            if (answer >= MOD) {
                answer -= MOD;
            }

            return;
        }

        for (int value = 1; value <= n; value++) {
            if (used[value] || value == position) {
                continue;
            }

            used[value] = true;
            permutation.push_back(value);

            generate(
                n,
                position + 1,
                permutation,
                used
            );

            permutation.pop_back();
            used[value] = false;
        }
    }

public:
    int findDerangement(int n) {
        answer = 0;
        vector<int> permutation;
        vector<bool> used(n + 1);

        generate(
            n,
            1,
            permutation,
            used
        );

        return answer;
    }
};
