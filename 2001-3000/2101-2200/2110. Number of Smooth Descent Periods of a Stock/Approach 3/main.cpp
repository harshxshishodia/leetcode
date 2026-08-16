class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long length = 1;
        long long answer = 1;

        for (int index = 1;
             index < static_cast<int>(prices.size());
             index++) {
            if (prices[index - 1] -
                prices[index] == 1) {
                length++;
            } else {
                length = 1;
            }

            answer +=
                length;
        }

        return answer;
    }
};
