class Solution {
    unsigned int seed=2463534242u;

    unsigned int nextRandom() {
        seed^=seed<<13;
        seed^=seed>>17;
        seed^=seed<<5;

        return seed;
    }

    bool isTrimmedLess(const vector<string>& nums,int first,int second,int trimLength) {
        int digitCount=nums[0].size();

        for(int pos=digitCount-trimLength;pos<digitCount;pos++) {
            if(nums[first][pos]!=nums[second][pos])
                return nums[first][pos]<nums[second][pos];
        }

        return first<second;
    }

    int partition(vector<int>& order,int left,int right,const vector<string>& nums,int trimLength) {
        int pivotIndex=left+nextRandom()%(right-left+1);
        int pivotValue=order[pivotIndex];

        swap(order[pivotIndex],order[right]);

        int storeIndex=left;

        for(int index=left;index<right;index++) {
            if(isTrimmedLess(nums,order[index],pivotValue,trimLength)) {
                swap(order[index],order[storeIndex]);
                storeIndex++;
            }
        }

        swap(order[storeIndex],order[right]);

        return storeIndex;
    }

    int quickSelect(vector<int>& order,int target,const vector<string>& nums,int trimLength) {
        int left=0;
        int right=order.size()-1;

        while(left<=right) {
            int pivotIndex=partition(order,left,right,nums,trimLength);

            if(pivotIndex==target)
                return order[pivotIndex];

            if(pivotIndex<target)
                left=pivotIndex+1;
            else
                right=pivotIndex-1;
        }

        return -1;
    }

public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums,vector<vector<int>>& queries) {
        int size=nums.size();
        vector<int> answer;

        for(auto& query:queries) {
            vector<int> order(size);

            iota(order.begin(),order.end(),0);
            answer.push_back(quickSelect(order,query[0]-1,nums,query[1]));
        }

        return answer;
    }
};
