class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n =
            static_cast<int>(prices.size());

        long long answer = 0;

        for (int left = 0; left < n; left++) {
            for (int right = left; right < n; right++) {
                bool valid = true;

                for (int index = left + 1;
                     index <= right;
                     index++) {
                    if (prices[index - 1] -
                        prices[index] != 1) {
                        valid = false;
                        break;
                    }
                }

                answer +=
                    valid;
            }
        }

        return answer;
    }
};
