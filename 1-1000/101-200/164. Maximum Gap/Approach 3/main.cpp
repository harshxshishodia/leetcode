class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2)
            return 0;

        multiset<int> sortedValues(nums.begin(),nums.end());

        auto it=sortedValues.begin();
        int previousValue=*it;
        int maxGap=0;

        it++;

        while(it!=sortedValues.end()) {
            maxGap=max(maxGap,*it-previousValue);
            previousValue=*it;
            it++;
        }

        return maxGap;
    }
};
