class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        if (nums.size() == 1) {
            return to_string(nums[0]);
        }

        if (nums.size() == 2) {
            return to_string(nums[0]) +
                   "/" +
                   to_string(nums[1]);
        }

        string answer =
            to_string(nums[0]) +
            "/(" +
            to_string(nums[1]);

        for (int i = 2; i < static_cast<int>(nums.size()); i++) {
            answer += "/";
            answer += to_string(nums[i]);
        }

        answer += ")";
        return answer;
    }
};
