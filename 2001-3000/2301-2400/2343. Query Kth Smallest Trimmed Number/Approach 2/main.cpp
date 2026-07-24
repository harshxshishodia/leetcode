class Solution {
    bool isTrimmedLess(const vector<string>& nums,int first,int second,int trimLength) {
        int digitCount=nums[0].size();

        for(int pos=digitCount-trimLength;pos<digitCount;pos++) {
            if(nums[first][pos]!=nums[second][pos])
                return nums[first][pos]<nums[second][pos];
        }

        return first<second;
    }

public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums,vector<vector<int>>& queries) {
        int size=nums.size();
        int digitCount=nums[0].size();
        vector<vector<int>> orderByTrim(digitCount+1);
        vector<bool> trimUsed(digitCount+1,false);

        for(auto& query:queries)
            trimUsed[query[1]]=true;

        for(int trimLength=1;trimLength<=digitCount;trimLength++) {
            if(!trimUsed[trimLength])
                continue;

            orderByTrim[trimLength].resize(size);
            iota(orderByTrim[trimLength].begin(),orderByTrim[trimLength].end(),0);

            sort(orderByTrim[trimLength].begin(),orderByTrim[trimLength].end(),[&](int first,int second) {
                return isTrimmedLess(nums,first,second,trimLength);
            });
        }

        vector<int> answer;

        for(auto& query:queries)
            answer.push_back(orderByTrim[query[1]][query[0]-1]);

        return answer;
    }
};
