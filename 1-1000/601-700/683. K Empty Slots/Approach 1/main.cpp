class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int k) {
        int n = bulbs.size();
        vector<bool> turnedOn(n, false);

        for (int day = 0; day < n; day++) {
            turnedOn[bulbs[day] - 1] = true;
            int previous = -1;

            for (int position = 0; position < n; position++) {
                if (!turnedOn[position])
                    continue;

                if (previous != -1 && position - previous - 1 == k)
                    return day + 1;

                previous = position;
            }
        }

        return -1;
    }
};