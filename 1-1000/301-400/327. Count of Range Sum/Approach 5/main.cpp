#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

class Solution {
    using OrderedSet = tree<pair<long long, int>, null_type, less<pair<long long, int>>, rb_tree_tag, tree_order_statistics_node_update>;

public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        OrderedSet prefixSums;
        long long prefix = 0;
        long long answer = 0;

        prefixSums.insert({0, 0});

        for (int index = 0; index < nums.size(); index++) {
            prefix += nums[index];

            int rightCount = prefixSums.order_of_key({prefix - lower, INT_MAX});
            int leftCount = prefixSums.order_of_key({prefix - upper, INT_MIN});
            answer += rightCount - leftCount;

            prefixSums.insert({prefix, index + 1});
        }

        return answer;
    }
};