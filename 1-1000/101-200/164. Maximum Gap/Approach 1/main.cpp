class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int size=nums.size();

        if(size<2)
            return 0;

        sort(nums.begin(),nums.end());

        int maxGap=0;

        for(int index=1;index<size;index++)
            maxGap=max(maxGap,nums[index]-nums[index-1]);

        return maxGap;
    }
};
