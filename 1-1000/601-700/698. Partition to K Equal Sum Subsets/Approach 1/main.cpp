class Solution {
    bool search(
        const vector<int>& nums,
        int index,
        int target,
        vector<int>& buckets
    ) {
        if (index == static_cast<int>(nums.size())) {
            for (int sum : buckets) {
                if (sum != target) {
                    return false;
                }
            }

            return true;
        }

        for (int bucket = 0;
             bucket < static_cast<int>(buckets.size());
             bucket++) {
            if (buckets[bucket] + nums[index] > target) {
                continue;
            }

            buckets[bucket] += nums[index];

            if (search(
                    nums,
                    index + 1,
                    target,
                    buckets)) {
                return true;
            }

            buckets[bucket] -= nums[index];
        }

        return false;
    }

public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total = accumulate(
            nums.begin(),
            nums.end(),
            0
        );

        if (total % k != 0) {
            return false;
        }

        vector<int> buckets(k);

        return search(
            nums,
            0,
            total / k,
            buckets
        );
    }
};
