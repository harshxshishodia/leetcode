class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        int answer = 2;

        for (int first = 0; first < n; first++) {
            for (int second = first + 1; second < n; second++) {
                long long difference =
                    static_cast<long long>(nums[second]) -
                    nums[first];

                int length = 2;
                int previous = nums[second];

                for (int next = second + 1; next < n; next++) {
                    if (static_cast<long long>(nums[next]) -
                        previous == difference) {
                        length++;
                        previous = nums[next];
                    }
                }

                answer = max(
                    answer,
                    length
                );
            }
        }

        return answer;
    }
};
