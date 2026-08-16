class Solution {
    static constexpr int MOD = 1000000007;
    unordered_set<int> values;
    unordered_map<int, long long> memo;

    long long countTrees(int root) {
        auto found = memo.find(root);

        if (found != memo.end()) {
            return found->second;
        }

        long long answer = 1;

        for (int left : values) {
            if (root % left != 0) {
                continue;
            }

            int right = root / left;

            if (!values.count(right)) {
                continue;
            }

            answer +=
                countTrees(left) *
                countTrees(right);

            answer %= MOD;
        }

        memo[root] = answer;
        return memo[root];
    }

public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        values.clear();
        memo.clear();

        for (int value : arr) {
            values.insert(value);
        }

        long long answer = 0;

        for (int value : arr) {
            answer += countTrees(value);
            answer %= MOD;
        }

        return static_cast<int>(answer);
    }
};
