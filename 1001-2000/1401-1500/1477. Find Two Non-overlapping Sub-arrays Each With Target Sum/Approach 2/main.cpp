class Solution {
public:
    int minSumOfLengths(
        vector<int>& arr,
        int target
    ) {
        int n =
            static_cast<int>(arr.size());

        const int INF =
            1000000000;

        vector<int> best(
            n + 1,
            INF
        );

        unordered_map<long long, int> lastIndex;
        lastIndex[0] = 0;

        long long prefix = 0;
        int answer = INF;

        for (int right = 1; right <= n; right++) {
            prefix += arr[right - 1];

            best[right] =
                best[right - 1];

            auto found =
                lastIndex.find(
                    prefix - target
                );

            if (found != lastIndex.end()) {
                int left =
                    found->second;

                int length =
                    right - left;

                if (best[left] != INF) {
                    answer = min(
                        answer,
                        length +
                        best[left]
                    );
                }

                best[right] = min(
                    best[right],
                    length
                );
            }

            lastIndex[prefix] = right;
        }

        return answer == INF
            ? -1
            : answer;
    }
};
