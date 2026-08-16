class Solution {
public:
    long long minimumCost(string s) {
        long long answer = 0;
        int n =
            static_cast<int>(s.size());

        for (int index = 1;
             index < n;
             index++) {
            if (s[index] !=
                s[index - 1]) {
                answer +=
                    min(
                        index,
                        n - index
                    );
            }
        }

        return answer;
    }
};
