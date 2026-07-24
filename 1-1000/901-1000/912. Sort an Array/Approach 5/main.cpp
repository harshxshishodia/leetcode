class Solution {
    void swapValues(int& first,int& second) {
        int temp=first;
        first=second;
        second=temp;
    }

    void insertionSort(vector<int>& values,int left,int right) {
        for(int index=left+1;index<=right;index++) {
            int current=values[index];
            int position=index-1;

            while(position>=left&&values[position]>current) {
                values[position+1]=values[position];
                position--;
            }

            values[position+1]=current;
        }
    }

    void heapifyWindow(vector<int>& values,int left,int heapSize,int root) {
        while(true) {
            int largest=root;
            int leftChild=2*root+1;
            int rightChild=leftChild+1;

            if(leftChild<heapSize&&values[left+leftChild]>values[left+largest])
                largest=leftChild;

            if(rightChild<heapSize&&values[left+rightChild]>values[left+largest])
                largest=rightChild;

            if(largest==root)
                break;

            swapValues(values[left+root],values[left+largest]);
            root=largest;
        }
    }

    void heapSortWindow(vector<int>& values,int left,int right) {
        int heapSize=right-left+1;

        for(int root=heapSize/2-1;root>=0;root--)
            heapifyWindow(values,left,heapSize,root);

        for(int end=heapSize-1;end>0;end--) {
            swapValues(values[left],values[left+end]);
            heapifyWindow(values,left,end,0);
        }
    }

    int medianOfThree(int first,int second,int third) {
        if(first<second) {
            if(second<third)
                return second;

            if(first<third)
                return third;

            return first;
        }

        if(first<third)
            return first;

        if(second<third)
            return third;

        return second;
    }

    void introSort(vector<int>& values,int left,int right,int depthLimit) {
        while(left<right) {
            if(right-left+1<=16) {
                insertionSort(values,left,right);
                return;
            }

            if(depthLimit==0) {
                heapSortWindow(values,left,right);
                return;
            }

            depthLimit--;

            int pivotValue=medianOfThree(values[left],values[left+(right-left)/2],values[right]);
            int lessEnd=left;
            int scan=left;
            int greaterStart=right;

            while(scan<=greaterStart) {
                if(values[scan]<pivotValue) {
                    swapValues(values[lessEnd],values[scan]);
                    lessEnd++;
                    scan++;
                }
                else if(values[scan]>pivotValue) {
                    swapValues(values[scan],values[greaterStart]);
                    greaterStart--;
                }
                else
                    scan++;
            }

            if(lessEnd-left<right-greaterStart) {
                introSort(values,left,lessEnd-1,depthLimit);
                left=greaterStart+1;
            }
            else {
                introSort(values,greaterStart+1,right,depthLimit);
                right=lessEnd-1;
            }
        }
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        int size=nums.size();
        int maxDepth=0;
        int currentSize=size;

        while(currentSize>1) {
            maxDepth++;
            currentSize/=2;
        }

        introSort(nums,0,size-1,2*maxDepth);

        return nums;
    }
};
