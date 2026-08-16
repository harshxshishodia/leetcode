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

        int answer =
            1 +
            power(
                value % 2 == 0
                    ? value / 2
                    : 3 * value + 1
            );

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

        priority_queue<pair<int, int>> heap;

        for (int value = lo; value <= hi; value++) {
            heap.push({
                power(value),
                value
            });

            if (static_cast<int>(heap.size()) > k) {
                heap.pop();
            }
        }

        return heap.top().second;
    }
};
