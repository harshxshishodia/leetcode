class Solution {
    vector<string>* words;
    vector<int>* groups;
    vector<vector<int>> memo;
    vector<bool> visited;

    bool compatible(
        int first,
        int second
    ) {
        if ((*groups)[first] ==
            (*groups)[second]) {
            return false;
        }

        if ((*words)[first].size() !=
            (*words)[second].size()) {
            return false;
        }

        int differences = 0;

        for (int position = 0;
             position < static_cast<int>((*words)[first].size());
             position++) {
            differences +=
                (*words)[first][position] !=
                (*words)[second][position];

            if (differences > 1) {
                return false;
            }
        }

        return differences == 1;
    }

    vector<int> solve(int index) {
        if (visited[index]) {
            return memo[index];
        }

        visited[index] =
            true;

        vector<int> answer = {
            index
        };

        for (int next = index + 1;
             next < static_cast<int>(words->size());
             next++) {
            if (!compatible(
                    index,
                    next)) {
                continue;
            }

            vector<int> suffix =
                solve(next);

            if (suffix.size() + 1 >
                answer.size()) {
                answer.clear();
                answer.push_back(index);

                answer.insert(
                    answer.end(),
                    suffix.begin(),
                    suffix.end()
                );
            }
        }

        memo[index] =
            answer;

        return memo[index];
    }

public:
    vector<string> getWordsInLongestSubsequence(
        vector<string>& inputWords,
        vector<int>& inputGroups
    ) {
        words =
            &inputWords;

        groups =
            &inputGroups;

        memo.assign(
            words->size(),
            {}
        );

        visited.assign(
            words->size(),
            false
        );

        vector<int> best;

        for (int start = 0;
             start < static_cast<int>(words->size());
             start++) {
            vector<int> candidate =
                solve(start);

            if (candidate.size() >
                best.size()) {
                best =
                    candidate;
            }
        }

        vector<string> answer;

        for (int index : best) {
            answer.push_back(
                (*words)[index]
            );
        }

        return answer;
    }
};
