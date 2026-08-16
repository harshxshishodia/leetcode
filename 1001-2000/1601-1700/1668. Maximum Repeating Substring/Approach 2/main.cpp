class Solution {
public:
    int maxRepeating(string sequence, string word) {
        string repeated = word;
        int answer = 0;

        while (repeated.size() <= sequence.size()) {
            if (sequence.find(repeated) == string::npos) {
                break;
            }

            answer++;
            repeated += word;
        }

        return answer;
    }
};
