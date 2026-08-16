class TopVotedCandidate {
    vector<int> voteTimes;
    vector<int> leadersAtTimes;

public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) : voteTimes(times) {
        unordered_map<int, int> voteTally;
        int currentLeader = -1;
        int maxVotes = 0;

        for (int i = 0; i < static_cast<int>(persons.size()); i++) {
            int p = persons[i];
            voteTally[p]++;
            if (voteTally[p] >= maxVotes) {
                maxVotes = voteTally[p];
                currentLeader = p;
            }
            leadersAtTimes.push_back(currentLeader);
        }
    }

    int q(int t) {
        int index = upper_bound(voteTimes.begin(), voteTimes.end(), t) - voteTimes.begin() - 1;
        return leadersAtTimes[index];
    }
};
