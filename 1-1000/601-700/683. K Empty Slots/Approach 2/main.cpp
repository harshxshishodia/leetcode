class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int k) {
        set<int> turnedOn;

        for (int day = 0; day < bulbs.size(); day++) {
            int position = bulbs[day];
            auto iterator = turnedOn.insert(position).first;
            auto nextIterator = next(iterator);

            if (nextIterator != turnedOn.end() && *nextIterator - position == k + 1)
                return day + 1;

            if (iterator != turnedOn.begin()) {
                auto previousIterator = prev(iterator);

                if (position - *previousIterator == k + 1)
                    return day + 1;
            }
        }

        return -1;
    }
};