class Solution {
public:
    int maximumCostSubstring(
        string s,
        string chars,
        vector<int>& vals
    ) {
        array<int, 26> cost;

        for (int index = 0; index < 26; index++) {
            cost[index] =
                index + 1;
        }

        for (int index = 0;
             index < static_cast<int>(chars.size());
             index++) {
            cost[
                chars[index] -
                'a'
            ] =
                vals[index];
        }

        int current = 0;
        int answer = 0;

        for (char character :
             s) {
            current = max(
                0,
                current +
                cost[
                    character -
                    'a'
                ]
            );

            answer = max(
                answer,
                current
            );
        }

        return answer;
    }
};
