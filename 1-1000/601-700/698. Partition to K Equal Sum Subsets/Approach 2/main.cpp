class Solution {
    bool search(
        const vector<int>& nums,
        int index,
        int target,
        vector<int>& buckets
    ) {
        if (index == static_cast<int>(nums.size())) {
            return true;
        }

        int value = nums[index];

        for (int bucket = 0;
             bucket < static_cast<int>(buckets.size());
             bucket++) {
            if (buckets[bucket] + value > target) {
                continue;
            }

            bool duplicate = false;

            for (int previous = 0;
                 previous < bucket;
                 previous++) {
                if (buckets[previous] == buckets[bucket]) {
                    duplicate = true;
                    break;
                }
            }

            if (duplicate) {
                continue;
            }

            buckets[bucket] += value;

            if (search(
                    nums,
                    index + 1,
                    target,
                    buckets)) {
                return true;
            }

            buckets[bucket] -= value;
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

        int target = total / k;

        sort(
            nums.begin(),
            nums.end(),
            greater<int>()
        );

        if (nums[0] > target) {
            return false;
        }

        vector<int> buckets(k);

        return search(
            nums,
            0,
            target,
            buckets
        );
    }
};
