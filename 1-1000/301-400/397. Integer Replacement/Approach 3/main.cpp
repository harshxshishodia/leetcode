class Solution {
public:
    int integerReplacement(int n) {
        queue<pair<long long, int>> pending;
        unordered_set<long long> visited;

        pending.push({n, 0});
        visited.insert(n);

        while (!pending.empty()) {
            auto [value, steps] = pending.front();
            pending.pop();

            if (value == 1) {
                return steps;
            }

            if (value % 2 == 0) {
                long long next = value / 2;

                if (visited.insert(next).second) {
                    pending.push({next, steps + 1});
                }
            } else {
                long long smaller = value - 1;
                long long larger = value + 1;

                if (visited.insert(smaller).second) {
                    pending.push({smaller, steps + 1});
                }

                if (visited.insert(larger).second) {
                    pending.push({larger, steps + 1});
                }
            }
        }

        return 0;
    }
};
