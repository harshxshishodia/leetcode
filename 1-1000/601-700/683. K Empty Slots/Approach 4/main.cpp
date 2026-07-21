class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int k) {
        int n = bulbs.size();
        vector<int> days(n);

        for (int day = 0; day < n; day++)
            days[bulbs[day] - 1] = day + 1;

        int answer = INT_MAX;
        int left = 0;
        int right = k + 1;

        for (int index = left + 1; right < n; index++) {
            if (days[index] < days[left] || days[index] <= days[right]) {
                if (index == right)
                    answer = min(answer, max(days[left], days[right]));

                left = index;
                right = index + k + 1;
            }
        }

        return answer == INT_MAX ? -1 : answer;
    }
};