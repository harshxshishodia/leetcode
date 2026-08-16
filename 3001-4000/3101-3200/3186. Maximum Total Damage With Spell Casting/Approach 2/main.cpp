class Solution {
    vector<long long> values;
    vector<long long> damage;

    long long solve(int index) {
        if (index ==
            static_cast<int>(values.size())) {
            return 0;
        }

        long long skip =
            solve(
                index + 1
            );

        int next =
            index + 1;

        while (
            next <
                static_cast<int>(values.size()) &&
            values[next] <=
                values[index] +
                2
        ) {
            next++;
        }

        long long take =
            damage[index] +
            solve(next);

        return max(
            skip,
            take
        );
    }

public:
    long long maximumTotalDamage(vector<int>& power) {
        map<long long, long long> frequency;

        for (int value : power) {
            frequency[value]++;
        }

        values.clear();
        damage.clear();

        for (auto [value, count] :
             frequency) {
            values.push_back(
                value
            );

            damage.push_back(
                value *
                count
            );
        }

        return solve(0);
    }
};
