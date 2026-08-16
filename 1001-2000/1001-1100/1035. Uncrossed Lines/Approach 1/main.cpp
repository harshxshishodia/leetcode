class Solution {
    int solve(
        const vector<int>& first,
        const vector<int>& second,
        int i,
        int j
    ) {
        if (i == static_cast<int>(first.size()) ||
            j == static_cast<int>(second.size())) {
            return 0;
        }

        if (first[i] == second[j]) {
            return 1 +
                   solve(
                       first,
                       second,
                       i + 1,
                       j + 1
                   );
        }

        return max(
            solve(
                first,
                second,
                i + 1,
                j
            ),
            solve(
                first,
                second,
                i,
                j + 1
            )
        );
    }

public:
    int maxUncrossedLines(
        vector<int>& nums1,
        vector<int>& nums2
    ) {
        return solve(
            nums1,
            nums2,
            0,
            0
        );
    }
};
