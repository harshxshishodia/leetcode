class Solution {
public:
    int minIncrements(
        int n,
        vector<int>& cost
    ) {
        int answer = 0;

        for (int node = n / 2;
             node >= 1;
             node--) {
            int left =
                node * 2;

            int right =
                node * 2 + 1;

            answer +=
                abs(
                    cost[left - 1] -
                    cost[right - 1]
                );

            cost[node - 1] +=
                max(
                    cost[left - 1],
                    cost[right - 1]
                );
        }

        return answer;
    }
};
