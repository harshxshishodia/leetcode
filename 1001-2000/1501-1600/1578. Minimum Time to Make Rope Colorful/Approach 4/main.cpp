class Solution {
public:
    int minCost(
        string colors,
        vector<int>& neededTime
    ) {
        int answer = 0;
        int maximum =
            neededTime[0];

        for (int i = 1;
             i < static_cast<int>(colors.size());
             i++) {
            if (colors[i] != colors[i - 1]) {
                maximum =
                    neededTime[i];

                continue;
            }

            answer += min(
                maximum,
                neededTime[i]
            );

            maximum = max(
                maximum,
                neededTime[i]
            );
        }

        return answer;
    }
};
