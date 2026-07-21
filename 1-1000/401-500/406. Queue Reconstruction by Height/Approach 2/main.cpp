class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();

        sort(people.begin(), people.end(), [](const vector<int>& first, const vector<int>& second) {
            if (first[0] == second[0])
                return first[1] > second[1];

            return first[0] < second[0];
        });

        vector<vector<int>> answer(n, vector<int>());
        vector<bool> occupied(n, false);

        for (const vector<int>& person : people) {
            int emptyPositions = person[1] + 1;

            for (int index = 0; index < n; index++) {
                if (!occupied[index])
                    emptyPositions--;

                if (emptyPositions == 0) {
                    answer[index] = person;
                    occupied[index] = true;
                    break;
                }
            }
        }

        return answer;
    }
};