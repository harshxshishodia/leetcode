class Solution {
    vector<vector<int>> memo;
    vector<vector<bool>> visited;

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

        if (visited[index][total]) {
            return memo[index][total];
        }

        visited[index][total] =
            true;

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

        memo[index][total] =
            answer;

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

        int maximum =
            *max_element(
                rewardValues.begin(),
                rewardValues.end()
            );

        int limit =
            2 *
            maximum;

        memo.assign(
            rewardValues.size(),
            vector<int>(
                limit,
                0
            )
        );

        visited.assign(
            rewardValues.size(),
            vector<bool>(
                limit,
                false
            )
        );

        return solve(
            rewardValues,
            0,
            0
        );
    }
};
