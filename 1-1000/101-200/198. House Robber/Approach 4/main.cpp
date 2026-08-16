class Solution {
public:
    int rob(vector<int>& nums) {
        int previous2 = 0;
        int previous1 = 0;

        for (int money : nums) {
            int current = max(previous1, previous2 + money);
            previous2 = previous1;
            previous1 = current;
        }

        return previous1;
    }
};
