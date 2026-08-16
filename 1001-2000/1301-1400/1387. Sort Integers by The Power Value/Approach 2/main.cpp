class Solution {
    unordered_map<long long, int> memo;

    int power(long long value) {
        if (value == 1) {
            return 0;
        }

        auto found =
            memo.find(value);

        if (found != memo.end()) {
            return found->second;
        }

        int answer;

        if (value % 2 == 0) {
            answer =
                1 +
                power(value / 2);
        } else {
            answer =
                1 +
                power(
                    3 * value + 1
                );
        }

        memo[value] = answer;
        return answer;
    }

public:
    int getKth(
        int lo,
        int hi,
        int k
    ) {
        memo.clear();
        memo[1] = 0;

        vector<pair<int, int>> values;

        for (int value = lo; value <= hi; value++) {
            values.push_back({
                power(value),
                value
            });
        }

        nth_element(
            values.begin(),
            values.begin() + k - 1,
            values.end()
        );

        return values[k - 1].second;
    }
};
