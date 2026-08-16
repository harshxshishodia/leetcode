class Solution {
public:
    int maximumEnergy(
        vector<int>& energy,
        int k
    ) {
        int answer =
            numeric_limits<int>::min();

        for (int start = 0;
             start < static_cast<int>(energy.size());
             start++) {
            int total = 0;

            for (int index = start;
                 index < static_cast<int>(energy.size());
                 index += k) {
                total +=
                    energy[index];
            }

            answer = max(
                answer,
                total
            );
        }

        return answer;
    }
};
