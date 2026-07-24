class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums,vector<vector<int>>& queries) {
        int size=nums.size();
        int digitCount=nums[0].size();

        vector<vector<int>> orderByTrim(digitCount+1,vector<int>(size));
        vector<int> order(size);
        vector<int> buffer(size);

        iota(order.begin(),order.end(),0);

        for(int trimLength=1;trimLength<=digitCount;trimLength++) {
            int counts[10]={};
            int digitPos=digitCount-trimLength;

            for(int index:order)
                counts[nums[index][digitPos]-'0']++;

            for(int i=1;i<10;i++)
                counts[i]+=counts[i-1];

            for(int i=size-1;i>=0;i--) {
                int digit=nums[order[i]][digitPos]-'0';
                buffer[--counts[digit]]=order[i];
            }

            order.swap(buffer);
            orderByTrim[trimLength]=order;
        }

        vector<int> answer;

        for(auto& query:queries)
            answer.push_back(orderByTrim[query[1]][query[0]-1]);

        return answer;
    }
};
