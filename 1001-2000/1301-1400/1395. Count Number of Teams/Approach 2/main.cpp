class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n =
            static_cast<int>(rating.size());

        int answer = 0;

        for (int middle = 0; middle < n; middle++) {
            int leftSmaller = 0;
            int leftGreater = 0;
            int rightSmaller = 0;
            int rightGreater = 0;

            for (int left = 0; left < middle; left++) {
                if (rating[left] < rating[middle]) {
                    leftSmaller++;
                } else {
                    leftGreater++;
                }
            }

            for (int right = middle + 1; right < n; right++) {
                if (rating[right] < rating[middle]) {
                    rightSmaller++;
                } else {
                    rightGreater++;
                }
            }

            answer +=
                leftSmaller *
                rightGreater;

            answer +=
                leftGreater *
                rightSmaller;
        }

        return answer;
    }
};
