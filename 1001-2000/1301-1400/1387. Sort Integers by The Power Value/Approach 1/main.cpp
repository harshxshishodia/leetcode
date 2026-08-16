class Solution {
    int power(int value) {
        int steps = 0;
        long long current = value;

        while (current != 1) {
            if (current % 2 == 0) {
                current /= 2;
            } else {
                current =
                    3 * current + 1;
            }

            steps++;
        }

        return steps;
    }

public:
    int getKth(
        int lo,
        int hi,
        int k
    ) {
        vector<pair<int, int>> values;

        for (int value = lo; value <= hi; value++) {
            values.push_back({
                power(value),
                value
            });
        }

        sort(
            values.begin(),
            values.end()
        );

        return values[k - 1].second;
    }
};
