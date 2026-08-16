class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> answer(n + 1);

        for (int i = 0; i <= n; i++) {
            int value = i;
            int count = 0;

            while (value > 0) {
                value &= value - 1;
                count++;
            }

            answer[i] = count;
        }

        return answer;
    }
};
