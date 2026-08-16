class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> answer;
        int previousGroup = -1;

        for (int i = 0; i < static_cast<int>(words.size()); i++) {
            if (groups[i] != previousGroup) {
                answer.push_back(words[i]);
                previousGroup = groups[i];
            }
        }

        return answer;
    }
};
