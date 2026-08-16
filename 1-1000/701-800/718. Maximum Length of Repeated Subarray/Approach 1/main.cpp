class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int answer = 0;

        for (int first = 0;
             first < static_cast<int>(nums1.size());
             first++) {
            for (int second = 0;
                 second < static_cast<int>(nums2.size());
                 second++) {
                int length = 0;

                while (first + length < static_cast<int>(nums1.size()) &&
                       second + length < static_cast<int>(nums2.size()) &&
                       nums1[first + length] == nums2[second + length]) {
                    length++;
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
