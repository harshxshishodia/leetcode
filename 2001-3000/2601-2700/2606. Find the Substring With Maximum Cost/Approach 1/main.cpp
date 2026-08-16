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

        int answer = 0;

        for (int left = 0;
             left < static_cast<int>(s.size());
             left++) {
            int sum = 0;

            for (int right = left;
                 right < static_cast<int>(s.size());
                 right++) {
                sum +=
                    cost[
                        s[right] -
                        'a'
                    ];

                answer = max(
                    answer,
                    sum
                );
            }
        }

        return answer;
    }
};
