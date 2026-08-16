class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = static_cast<int>(words.size());
        vector<int> length(n, 1);
        vector<int> parent(n, -1);
        int bestIndex = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (groups[i] != groups[j] && length[j] + 1 > length[i]) {
                    length[i] = length[j] + 1;
                    parent[i] = j;
                }
            }

            if (length[i] > length[bestIndex]) {
                bestIndex = i;
            }
        }

        vector<string> answer;

        while (bestIndex != -1) {
            answer.push_back(words[bestIndex]);
            bestIndex = parent[bestIndex];
        }

        reverse(answer.begin(), answer.end());
        return answer;
    }
};
