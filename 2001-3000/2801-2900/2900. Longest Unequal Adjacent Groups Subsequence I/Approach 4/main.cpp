class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = static_cast<int>(words.size());
        vector<int> length(n, 1);
        vector<int> parent(n, -1);
        array<int, 2> bestIndex = {-1, -1};

        for (int i = 0; i < n; i++) {
            int opposite = groups[i] ^ 1;

            if (bestIndex[opposite] != -1) {
                parent[i] = bestIndex[opposite];
                length[i] = length[parent[i]] + 1;
            }

            if (bestIndex[groups[i]] == -1 || length[i] > length[bestIndex[groups[i]]]) {
                bestIndex[groups[i]] = i;
            }
        }

        int end = bestIndex[0];

        if (end == -1 || (bestIndex[1] != -1 && length[bestIndex[1]] > length[end])) {
            end = bestIndex[1];
        }

        vector<string> answer;

        while (end != -1) {
            answer.push_back(words[end]);
            end = parent[end];
        }

        reverse(answer.begin(), answer.end());
        return answer;
    }
};
