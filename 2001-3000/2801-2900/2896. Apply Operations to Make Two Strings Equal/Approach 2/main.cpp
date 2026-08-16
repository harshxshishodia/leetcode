class Solution {
    vector<int> positions;
    int x;
    unordered_map<string, long long> memo;

    long long solve(string used) {
        int first = -1;

        for (int index = 0;
             index < static_cast<int>(used.size());
             index++) {
            if (used[index] == '0') {
                first =
                    index;

                break;
            }
        }

        if (first == -1) {
            return 0;
        }

        auto found =
            memo.find(used);

        if (found != memo.end()) {
            return found->second;
        }

        long long answer =
            numeric_limits<long long>::max() /
            4;

        used[first] =
            '1';

        for (int second = first + 1;
             second < static_cast<int>(used.size());
             second++) {
            if (used[second] == '1') {
                continue;
            }

            used[second] =
                '1';

            long long pairCost =
                min<long long>(
                    x,
                    positions[second] -
                    positions[first]
                );

            answer = min(
                answer,
                pairCost +
                solve(used)
            );

            used[second] =
                '0';
        }

        used[first] =
            '0';

        memo[used] =
            answer;

        return answer;
    }

public:
    int minOperations(
        string s1,
        string s2,
        int inputX
    ) {
        positions.clear();
        memo.clear();
        x =
            inputX;

        for (int index = 0;
             index < static_cast<int>(s1.size());
             index++) {
            if (s1[index] !=
                s2[index]) {
                positions.push_back(
                    index
                );
            }
        }

        if (positions.size() % 2 != 0) {
            return -1;
        }

        string used(
            positions.size(),
            '0'
        );

        return static_cast<int>(
            solve(used)
        );
    }
};
