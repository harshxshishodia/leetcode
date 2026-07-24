class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int size=nums.size();
        vector<int> output(size);

        for(int shift=0;shift<32;shift+=8) {
            int counts[256]={};

            for(int value:nums) {
                unsigned int key=static_cast<unsigned int>(value)^0x80000000u;
                int digit=(key>>shift)&255u;

                counts[digit]++;
            }

            for(int i=1;i<256;i++)
                counts[i]+=counts[i-1];

            for(int i=size-1;i>=0;i--) {
                unsigned int key=static_cast<unsigned int>(nums[i])^0x80000000u;
                int digit=(key>>shift)&255u;

                output[--counts[digit]]=nums[i];
            }

            nums.swap(output);
        }

        return nums;
    }
};
