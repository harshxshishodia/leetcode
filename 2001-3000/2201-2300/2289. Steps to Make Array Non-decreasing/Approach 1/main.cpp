class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int answer = 0;

        while (true) {
            int n =
                static_cast<int>(nums.size());

            vector<bool> remove(n);
            bool changed = false;

            for (int index = 1; index < n; index++) {
                if (nums[index - 1] >
                    nums[index]) {
                    remove[index] = true;
                    changed = true;
                }
            }

            if (!changed) {
                break;
            }

            vector<int> next;

            for (int index = 0; index < n; index++) {
                if (!remove[index]) {
                    next.push_back(
                        nums[index]
                    );
                }
            }

            nums = next;
            answer++;
        }

        return answer;
    }
};
