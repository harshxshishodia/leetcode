class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n =
            static_cast<int>(rating.size());

        int answer = 0;

        for (int first = 0; first < n; first++) {
            for (int second = first + 1; second < n; second++) {
                for (int third = second + 1; third < n; third++) {
                    if ((rating[first] < rating[second] &&
                         rating[second] < rating[third]) ||
                        (rating[first] > rating[second] &&
                         rating[second] > rating[third])) {
                        answer++;
                    }
                }
            }
        }

        return answer;
    }
};
