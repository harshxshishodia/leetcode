class Solution {
public:
    int minCost(
        string colors,
        vector<int>& neededTime
    ) {
        int answer = 0;
        int n =
            static_cast<int>(colors.size());

        int start = 0;

        while (start < n) {
            int end = start;
            int total = 0;
            int maximum = 0;

            while (end < n &&
                   colors[end] == colors[start]) {
                total +=
                    neededTime[end];

                maximum = max(
                    maximum,
                    neededTime[end]
                );

                end++;
            }

            answer +=
                total - maximum;

            start = end;
        }

        return answer;
    }
};
