class Solution {
public:
    int maximumEnergy(
        vector<int>& energy,
        int k
    ) {
        int answer =
            numeric_limits<int>::min();

        for (int index =
                 static_cast<int>(
                     energy.size()
                 ) -
                 1;
             index >= 0;
             index--) {
            if (
                index +
                k <
                static_cast<int>(
                    energy.size()
                )
            ) {
                energy[index] +=
                    energy[index + k];
            }

            answer = max(
                answer,
                energy[index]
            );
        }

        return answer;
    }
};
