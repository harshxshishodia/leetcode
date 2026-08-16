class Solution {
    long long answer = 0;

    bool valid(
        const vector<int>& chosen,
        int k
    ) {
        for (int first = 0;
             first < static_cast<int>(chosen.size());
             first++) {
            for (int second = first + 1;
                 second < static_cast<int>(chosen.size());
                 second++) {
                if (abs(
                        chosen[first] -
                        chosen[second]
                    ) == k) {
                    return false;
                }
            }
        }

        return true;
    }

    void search(
        const vector<int>& nums,
        int k,
        int index,
        vector<int>& chosen
    ) {
        if (index ==
            static_cast<int>(nums.size())) {
            answer +=
                valid(
                    chosen,
                    k
                );

            return;
        }

        search(
            nums,
            k,
            index + 1,
            chosen
        );

        chosen.push_back(
            nums[index]
        );

        search(
            nums,
            k,
            index + 1,
            chosen
        );

        chosen.pop_back();
    }

public:
    long long countTheNumOfKFreeSubsets(
        vector<int>& nums,
        int k
    ) {
        answer = 0;

        vector<int> chosen;

        search(
            nums,
            k,
            0,
            chosen
        );

        return answer;
    }
};
