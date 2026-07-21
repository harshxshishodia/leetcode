#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

class Solution {
    using OrderedSet = tree<pair<long long, int>, null_type, less<pair<long long, int>>, rb_tree_tag, tree_order_statistics_node_update>;

public:
    int reversePairs(vector<int>& nums) {
        OrderedSet values;
        int answer = 0;

        for (int index = 0; index < nums.size(); index++) {
            long long limit = 2LL * nums[index];
            int lessOrEqual = values.order_of_key({limit, INT_MAX});
            answer += values.size() - lessOrEqual;
            values.insert({nums[index], index});
        }

        return answer;
    }
};