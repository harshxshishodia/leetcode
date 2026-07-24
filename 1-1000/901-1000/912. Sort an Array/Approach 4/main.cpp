class Solution {
    unsigned int seed=2463534242u;

    unsigned int nextRandom() {
        seed^=seed<<13;
        seed^=seed>>17;
        seed^=seed<<5;

        return seed;
    }

    void quickSort(vector<int>& values,int left,int right) {
        while(left<right) {
            int pivotValue=values[left+nextRandom()%(right-left+1)];
            int lessEnd=left;
            int scan=left;
            int greaterStart=right;

            while(scan<=greaterStart) {
                if(values[scan]<pivotValue) {
                    int temp=values[lessEnd];
                    values[lessEnd]=values[scan];
                    values[scan]=temp;

                    lessEnd++;
                    scan++;
                }
                else if(values[scan]>pivotValue) {
                    int temp=values[scan];
                    values[scan]=values[greaterStart];
                    values[greaterStart]=temp;

                    greaterStart--;
                }
                else
                    scan++;
            }

            if(lessEnd-left<right-greaterStart) {
                quickSort(values,left,lessEnd-1);
                left=greaterStart+1;
            }
            else {
                quickSort(values,greaterStart+1,right);
                right=lessEnd-1;
            }
        }
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums,0,nums.size()-1);

        return nums;
    }
};
