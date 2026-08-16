class Solution {
public:
    int numSplits(string s) {
        int answer = 0;

        for (int split = 1;
             split < static_cast<int>(s.size());
             split++) {
            unordered_set<char> left;
            unordered_set<char> right;

            for (int i = 0; i < split; i++) {
                left.insert(s[i]);
            }

            for (int i = split;
                 i < static_cast<int>(s.size());
                 i++) {
                right.insert(s[i]);
            }

            if (left.size() ==
                right.size()) {
                answer++;
            }
        }

        return answer;
    }
};
