class Solution {
    unsigned int sortKey(int value) {
        return static_cast<unsigned int>(value)^0x80000000u;
    }

    void radixSort(vector<int>& values,int left,int right,int bit) {
        if(left>=right||bit<0)
            return;

        int low=left;
        int high=right;

        while(low<=high) {
            while(low<=high&&((sortKey(values[low])>>bit)&1u)==0)
                low++;

            while(low<=high&&((sortKey(values[high])>>bit)&1u)==1)
                high--;

            if(low<=high) {
                int temp=values[low];
                values[low]=values[high];
                values[high]=temp;

                low++;
                high--;
            }
        }

        radixSort(values,left,high,bit-1);
        radixSort(values,low,right,bit-1);
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        radixSort(nums,0,nums.size()-1,31);

        return nums;
    }
};
