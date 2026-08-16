class Solution {
public:
    int maxTotalReward(
        vector<int>& rewardValues
    ) {
        sort(
            rewardValues.begin(),
            rewardValues.end()
        );

        rewardValues.erase(
            unique(
                rewardValues.begin(),
                rewardValues.end()
            ),
            rewardValues.end()
        );

        int maximum =
            rewardValues.back();

        int limit =
            2 *
            maximum;

        vector<bool> reachable(
            limit
        );

        reachable[0] =
            true;

        int answer = 0;

        for (int reward :
             rewardValues) {
            for (int total =
                     reward -
                     1;
                 total >= 0;
                 total--) {
                if (!reachable[total]) {
                    continue;
                }

                int next =
                    total +
                    reward;

                reachable[next] =
                    true;

                answer = max(
                    answer,
                    next
                );
            }
        }

        return answer;
    }
};
