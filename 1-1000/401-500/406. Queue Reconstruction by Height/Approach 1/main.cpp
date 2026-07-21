class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int>& first, const vector<int>& second) {
            if (first[0] == second[0])
                return first[1] < second[1];

            return first[0] > second[0];
        });

        vector<vector<int>> answer;

        for (const vector<int>& person : people)
            answer.insert(answer.begin() + person[1], person);

        return answer;
    }
};