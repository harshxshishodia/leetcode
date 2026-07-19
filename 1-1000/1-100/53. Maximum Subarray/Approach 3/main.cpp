class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int prefixSum = 0;
        int minimumPrefix = 0;
        int answer = INT_MIN;

        for (int number : nums) {
            prefixSum += number;
            answer = max(answer, prefixSum - minimumPrefix);
            minimumPrefix = min(minimumPrefix, prefixSum);
        }

        return answer;
    }
};