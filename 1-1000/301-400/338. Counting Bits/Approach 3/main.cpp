class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> answer(n + 1);
        int offset = 1;

        for (int i = 1; i <= n; i++) {
            if (i == offset * 2) {
                offset = i;
            }

            answer[i] = 1 + answer[i - offset];
        }

        return answer;
    }
};
