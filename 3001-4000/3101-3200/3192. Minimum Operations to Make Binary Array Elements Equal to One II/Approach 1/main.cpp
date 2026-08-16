class Solution {
public:
    int minOperations(vector<int>& nums) {
        string start;
        string target;

        for (int value : nums) {
            start.push_back(
                static_cast<char>(
                    '0' +
                    value
                )
            );

            target.push_back(
                '1'
            );
        }

        queue<string> pending;
        unordered_map<string, int> distance;

        pending.push(
            start
        );

        distance[start] =
            0;

        while (!pending.empty()) {
            string state =
                pending.front();

            pending.pop();

            if (state == target) {
                return distance[state];
            }

            for (int index = 0;
                 index < static_cast<int>(state.size());
                 index++) {
                string next =
                    state;

                for (int current = index;
                     current < static_cast<int>(next.size());
                     current++) {
                    next[current] =
                        next[current] == '0'
                            ? '1'
                            : '0';
                }

                if (distance.count(next)) {
                    continue;
                }

                distance[next] =
                    distance[state] +
                    1;

                pending.push(
                    next
                );
            }
        }

        return -1;
    }
};
