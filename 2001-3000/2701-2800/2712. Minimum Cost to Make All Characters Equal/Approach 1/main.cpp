class Solution {
    string targetA;
    string targetB;

public:
    long long minimumCost(string s) {
        int n =
            static_cast<int>(s.size());

        targetA =
            string(
                n,
                '0'
            );

        targetB =
            string(
                n,
                '1'
            );

        unordered_map<string, long long> distance;

        priority_queue<
            pair<long long, string>,
            vector<pair<long long, string>>,
            greater<pair<long long, string>>
        > pending;

        distance[s] = 0;

        pending.push({
            0,
            s
        });

        while (!pending.empty()) {
            auto [currentCost, state] =
                pending.top();

            pending.pop();

            if (distance[state] !=
                currentCost) {
                continue;
            }

            if (state == targetA ||
                state == targetB) {
                return currentCost;
            }

            for (int length = 1;
                 length < n;
                 length++) {
                string prefix =
                    state;

                for (int index = 0;
                     index < length;
                     index++) {
                    prefix[index] =
                        prefix[index] == '0'
                            ? '1'
                            : '0';
                }

                long long prefixCost =
                    currentCost +
                    length;

                if (!distance.count(prefix) ||
                    prefixCost <
                    distance[prefix]) {
                    distance[prefix] =
                        prefixCost;

                    pending.push({
                        prefixCost,
                        prefix
                    });
                }

                string suffix =
                    state;

                for (int index =
                         n - length;
                     index < n;
                     index++) {
                    suffix[index] =
                        suffix[index] == '0'
                            ? '1'
                            : '0';
                }

                long long suffixCost =
                    currentCost +
                    length;

                if (!distance.count(suffix) ||
                    suffixCost <
                    distance[suffix]) {
                    distance[suffix] =
                        suffixCost;

                    pending.push({
                        suffixCost,
                        suffix
                    });
                }
            }
        }

        return 0;
    }
};
