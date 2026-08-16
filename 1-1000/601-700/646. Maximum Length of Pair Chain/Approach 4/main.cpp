class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(
            pairs.begin(),
            pairs.end(),
            [](const vector<int>& first, const vector<int>& second) {
                return first[1] < second[1];
            }
        );

        int answer = 0;
        int currentEnd = numeric_limits<int>::min();

        for (const vector<int>& pair : pairs) {
            if (pair[0] > currentEnd) {
                answer++;
                currentEnd = pair[1];
            }
        }

        return answer;
    }
};
