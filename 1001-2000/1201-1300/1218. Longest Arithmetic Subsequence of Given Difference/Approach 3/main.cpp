class Solution {
public:
    int longestSubsequence(
        vector<int>& arr,
        int difference
    ) {
        unordered_map<int, int> best;
        int answer = 0;

        for (int value : arr) {
            int length =
                best[value - difference] +
                1;

            best[value] = max(
                best[value],
                length
            );

            answer = max(
                answer,
                best[value]
            );
        }

        return answer;
    }
};
