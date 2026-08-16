class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> answer(n + 1);

        for (int i = 0; i <= n; i++) {
            int value = i;
            int count = 0;

            while (value > 0) {
                count += value & 1;
                value >>= 1;
            }

            answer[i] = count;
        }

        return answer;
    }
};
