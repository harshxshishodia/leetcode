class Solution {
public:
    int minOperations(
        string s1,
        string s2,
        int x
    ) {
        int n =
            static_cast<int>(s1.size());

        string start(
            n,
            '0'
        );

        int mismatchCount = 0;

        for (int index = 0;
             index < n;
             index++) {
            if (s1[index] !=
                s2[index]) {
                start[index] =
                    '1';

                mismatchCount++;
            }
        }

        if (mismatchCount % 2 != 0) {
            return -1;
        }

        string target(
            n,
            '0'
        );

        if (start == target) {
            return 0;
        }

        unordered_map<string, long long> distance;

        priority_queue<
            pair<long long, string>,
            vector<pair<long long, string>>,
            greater<pair<long long, string>>
        > pending;

        distance[start] = 0;

        pending.push({
            0,
            start
        });

        while (!pending.empty()) {
            auto [currentCost, state] =
                pending.top();

            pending.pop();

            if (distance[state] !=
                currentCost) {
                continue;
            }

            if (state == target) {
                return static_cast<int>(
                    currentCost
                );
            }

            for (int index = 0;
                 index + 1 < n;
                 index++) {
                string next =
                    state;

                next[index] =
                    next[index] == '0'
                        ? '1'
                        : '0';

                next[index + 1] =
                    next[index + 1] == '0'
                        ? '1'
                        : '0';

                long long nextCost =
                    currentCost +
                    1;

                if (!distance.count(next) ||
                    nextCost <
                    distance[next]) {
                    distance[next] =
                        nextCost;

                    pending.push({
                        nextCost,
                        next
                    });
                }
            }

            for (int first = 0;
                 first < n;
                 first++) {
                for (int second = first + 1;
                     second < n;
                     second++) {
                    string next =
                        state;

                    next[first] =
                        next[first] == '0'
                            ? '1'
                            : '0';

                    next[second] =
                        next[second] == '0'
                            ? '1'
                            : '0';

                    long long nextCost =
                        currentCost +
                        x;

                    if (!distance.count(next) ||
                        nextCost <
                        distance[next]) {
                        distance[next] =
                            nextCost;

                        pending.push({
                            nextCost,
                            next
                        });
                    }
                }
            }
        }

        return -1;
    }
};
