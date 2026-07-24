class Solution {
    void heapify(vector<int>& values,int heapSize,int root) {
        while(true) {
            int largest=root;
            int leftChild=2*root+1;
            int rightChild=leftChild+1;

            if(leftChild<heapSize&&values[leftChild]>values[largest])
                largest=leftChild;

            if(rightChild<heapSize&&values[rightChild]>values[largest])
                largest=rightChild;

            if(largest==root)
                break;

            int temp=values[root];
            values[root]=values[largest];
            values[largest]=temp;

            root=largest;
        }
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        int size=nums.size();

        for(int root=size/2-1;root>=0;root--)
            heapify(nums,size,root);

        for(int end=size-1;end>0;end--) {
            int temp=nums[0];
            nums[0]=nums[end];
            nums[end]=temp;

            heapify(nums,end,0);
        }

        return nums;
    }
};
