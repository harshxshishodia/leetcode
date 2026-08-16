class Solution {
public:
    int minOperations(int n) {
        int highest = 1;

        while (highest < n) {
            highest <<= 1;
        }

        int limit =
            highest << 1;

        vector<int> powers;

        for (int value = 1;
             value <= limit;
             value <<= 1) {
            powers.push_back(value);
        }

        vector<int> distance(
            limit + 1,
            -1
        );

        queue<int> pending;

        distance[n] = 0;
        pending.push(n);

        while (!pending.empty()) {
            int current =
                pending.front();

            pending.pop();

            if (current == 0) {
                return distance[current];
            }

            for (int power : powers) {
                int lower =
                    current -
                    power;

                int upper =
                    current +
                    power;

                if (lower >= 0 &&
                    lower <= limit &&
                    distance[lower] == -1) {
                    distance[lower] =
                        distance[current] +
                        1;

                    pending.push(lower);
                }

                if (upper >= 0 &&
                    upper <= limit &&
                    distance[upper] == -1) {
                    distance[upper] =
                        distance[current] +
                        1;

                    pending.push(upper);
                }
            }
        }

        return -1;
    }
};
