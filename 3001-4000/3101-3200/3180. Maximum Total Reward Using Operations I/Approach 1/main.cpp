class Solution {
    int solve(
        const vector<int>& rewards,
        int index,
        int total
    ) {
        if (index ==
            static_cast<int>(
                rewards.size()
            )) {
            return total;
        }

        int answer =
            solve(
                rewards,
                index + 1,
                total
            );

        if (rewards[index] > total) {
            answer = max(
                answer,
                solve(
                    rewards,
                    index + 1,
                    total +
                    rewards[index]
                )
            );
        }

        return answer;
    }

public:
    int maxTotalReward(
        vector<int>& rewardValues
    ) {
        sort(
            rewardValues.begin(),
            rewardValues.end()
        );

        return solve(
            rewardValues,
            0,
            0
        );
    }
};
